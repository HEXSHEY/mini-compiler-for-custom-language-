import tkinter as tk
from tkinter import filedialog, messagebox, font, scrolledtext, ttk
import subprocess
import os
import re
import threading
import graphviz
from PIL import Image, ImageTk
import sys

class CompilerGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Advanced Mini Compiler")
        self.root.geometry("1200x800")
        self.root.configure(bg="#1e1e1e")
        self.root.option_add("*tearOff", False)
        
        # Initialize compilation state BEFORE create_widgets
        self.compiling = False
        self.error_lines = []
        
        # Custom theme setup
        self.setup_theme()
        self.setup_fonts()
        self.create_widgets()
        self.create_menu()
        
        # Bind events
        self.code_text.bind("<KeyRelease>", self.on_code_change)
        self.code_text.bind("<<Modified>>", self.update_line_numbers)

    def setup_theme(self):
        style = ttk.Style()
        style.theme_use("clam")
        
        # Configure colors
        style.configure(".", background="#1e1e1e", foreground="#d4d4d4")
        style.configure("TFrame", background="#1e1e1e")
        style.configure("TButton", background="#0e639c", foreground="white", 
                        font=("Arial", 10, "bold"), borderwidth=1)
        style.map("TButton", background=[("active", "#1177bb")])
        style.configure("TNotebook", background="#252526", borderwidth=0)
        style.configure("TNotebook.Tab", background="#2d2d2d", 
                        foreground="#d4d4d4", padding=[10, 4])
        style.map("TNotebook.Tab", background=[("selected", "#0e639c")])
        style.configure("TLabel", background="#1e1e1e", foreground="#d4d4d4")
        style.configure("TScrollbar", background="#3c3c3c")

    def setup_fonts(self):
        self.text_font = font.Font(family="Consolas", size=12)
        self.button_font = font.Font(family="Arial", size=10, weight="bold")
        self.title_font = font.Font(family="Arial", size=14, weight="bold")
        self.status_font = font.Font(family="Arial", size=9)

    def create_menu(self):
        menubar = tk.Menu(self.root)
        
        # File menu
        file_menu = tk.Menu(menubar, tearoff=0)
        file_menu.add_command(label="New", command=self.new_file, accelerator="Ctrl+N")
        file_menu.add_command(label="Open", command=self.load_file, accelerator="Ctrl+O")
        file_menu.add_command(label="Save", command=self.save_file, accelerator="Ctrl+S")
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.root.quit)
        menubar.add_cascade(label="File", menu=file_menu)
        
        # Edit menu
        edit_menu = tk.Menu(menubar, tearoff=0)
        edit_menu.add_command(label="Undo", command=self.undo)
        edit_menu.add_command(label="Redo", command=self.redo)
        edit_menu.add_separator()
        edit_menu.add_command(label="Cut", command=self.cut)
        edit_menu.add_command(label="Copy", command=self.copy)
        edit_menu.add_command(label="Paste", command=self.paste)
        menubar.add_cascade(label="Edit", menu=edit_menu)
        
        # View menu
        view_menu = tk.Menu(menubar, tearoff=0)
        self.theme_var = tk.IntVar(value=0)
        view_menu.add_radiobutton(label="Dark Theme", variable=self.theme_var, value=0)
        view_menu.add_radiobutton(label="Light Theme", variable=self.theme_var, value=1)
        view_menu.add_separator()
        view_menu.add_command(label="Zoom In", command=self.zoom_in)
        view_menu.add_command(label="Zoom Out", command=self.zoom_out)
        menubar.add_cascade(label="View", menu=view_menu)
        
        # Debug menu
        debug_menu = tk.Menu(menubar, tearoff=0)
        debug_menu.add_command(label="Show AST", command=self.show_ast)
        debug_menu.add_command(label="Show Symbol Table", command=self.show_symbol_table)
        menubar.add_cascade(label="Debug", menu=debug_menu)
        
        self.root.config(menu=menubar)
        
        # Keyboard shortcuts
        self.root.bind("<Control-n>", lambda e: self.new_file())
        self.root.bind("<Control-o>", lambda e: self.load_file())
        self.root.bind("<Control-s>", lambda e: self.save_file())
        self.root.bind("<Control-plus>", lambda e: self.zoom_in())
        self.root.bind("<Control-minus>", lambda e: self.zoom_out())

    def create_widgets(self):
        # Create main panes
        main_pane = ttk.PanedWindow(self.root, orient=tk.HORIZONTAL)
        main_pane.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Left pane: Editor
        editor_frame = ttk.Frame(main_pane)
        main_pane.add(editor_frame, weight=2)
        
        # Editor header
        editor_header = ttk.Frame(editor_frame)
        editor_header.pack(fill=tk.X, padx=5, pady=5)
        
        ttk.Label(editor_header, text="SOURCE CODE", font=self.title_font).pack(side=tk.LEFT)
        
        # Editor toolbar
        toolbar = ttk.Frame(editor_header)
        toolbar.pack(side=tk.RIGHT)
        
        compile_btn = ttk.Button(toolbar, text="▶ Compile", command=self.compile_code)
        compile_btn.pack(side=tk.LEFT, padx=2)
        
        open_btn = ttk.Button(toolbar, text="📂 Open", command=self.load_file)
        open_btn.pack(side=tk.LEFT, padx=2)
        
        save_btn = ttk.Button(toolbar, text="💾 Save", command=self.save_file)
        save_btn.pack(side=tk.LEFT, padx=2)
        
        clear_btn = ttk.Button(toolbar, text="🗑️ Clear", command=self.clear_all)
        clear_btn.pack(side=tk.LEFT, padx=2)
        
        # Editor with line numbers
        editor_container = ttk.Frame(editor_frame)
        editor_container.pack(fill=tk.BOTH, expand=True, padx=5, pady=(0, 5))
        
        # Line numbers
        self.line_numbers = tk.Text(editor_container, width=4, padx=4, pady=4, 
                                   takefocus=0, border=0, background="#333", 
                                   foreground="#999", font=self.text_font)
        self.line_numbers.pack(side=tk.LEFT, fill=tk.Y)
        self.line_numbers.config(state=tk.DISABLED)
        
        # Code editor
        self.code_text = scrolledtext.ScrolledText(editor_container, wrap=tk.NONE, 
                                                 font=self.text_font, padx=10, pady=10,
                                                 bg="#252526", fg="#d4d4d4", 
                                                 insertbackground="white")
        self.code_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        
        # Add scrollbar for line numbers sync
        self.scrollbar = ttk.Scrollbar(editor_container, command=self.on_scroll)
        self.scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        self.code_text.config(yscrollcommand=self.update_scroll)
        
        # Right pane: Output tabs
        output_frame = ttk.Frame(main_pane)
        main_pane.add(output_frame, weight=1)
        
        # Notebook for output tabs
        self.notebook = ttk.Notebook(output_frame)
        self.notebook.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Output console tab
        console_frame = ttk.Frame(self.notebook)
        self.notebook.add(console_frame, text="Console")
        
        self.output_text = scrolledtext.ScrolledText(console_frame, font=self.text_font,
                                                   bg="#1e1e1e", fg="#dcdcaa", 
                                                   insertbackground="white")
        self.output_text.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        self.output_text.config(state=tk.DISABLED)
        
        # AST tab
        ast_frame = ttk.Frame(self.notebook)
        self.notebook.add(ast_frame, text="AST Visualizer")
        
        self.ast_canvas = tk.Canvas(ast_frame, bg="#1e1e1e")
        self.ast_canvas.pack(fill=tk.BOTH, expand=True)
        
        # Symbol table tab
        symbol_frame = ttk.Frame(self.notebook)
        self.notebook.add(symbol_frame, text="Symbol Table")
        
        columns = ("name", "type", "value", "scope")
        self.symbol_tree = ttk.Treeview(symbol_frame, columns=columns, show="headings")
        
        for col in columns:
            self.symbol_tree.heading(col, text=col.capitalize())
            self.symbol_tree.column(col, width=100)
        
        scrollbar = ttk.Scrollbar(symbol_frame, orient=tk.VERTICAL, 
                                 command=self.symbol_tree.yview)
        self.symbol_tree.configure(yscrollcommand=scrollbar.set)
        
        self.symbol_tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Status bar
        status_frame = ttk.Frame(self.root, height=25)
        status_frame.pack(fill=tk.X, padx=5, pady=(0, 5))
        
        self.status_var = tk.StringVar(value="Ready")
        status_label = ttk.Label(status_frame, textvariable=self.status_var, 
                                font=self.status_font, padding=5)
        status_label.pack(side=tk.LEFT)
        
        self.cursor_var = tk.StringVar(value="Ln 1, Col 1")
        cursor_label = ttk.Label(status_frame, textvariable=self.cursor_var, 
                               font=self.status_font, padding=5)
        cursor_label.pack(side=tk.RIGHT)
        
        # Initialize editor
        self.update_line_numbers()
        self.setup_syntax_highlighting()
        self.code_text.event_add("<<Modified>>", "<KeyRelease>", "<ButtonRelease>")
        self.code_text.bind("<Motion>", self.update_cursor_position)
        
        # Load demo code
        self.load_demo_code()

    def load_demo_code(self):
        demo_code = """function main() {
    int x = 10;
    float y = 3.14;
    string name = "Compiler";
    
    if (x > 5) {
        print("x is greater than 5");
    } else {
        print("x is 5 or less");
    }
    
    for (int i = 0; i < 3; i = i + 1) {
        print(i);
    }
    
    print("Program completed");
    return 0;
}"""
        self.code_text.delete("1.0", tk.END)
        self.code_text.insert(tk.END, demo_code)
        self.update_line_numbers()
        self.highlight_syntax()

    def setup_syntax_highlighting(self):
        # Configure tags for syntax highlighting
        self.code_text.tag_configure("keyword", foreground="#569cd6", font=self.text_font)
        self.code_text.tag_configure("type", foreground="#4ec9b0", font=self.text_font)
        self.code_text.tag_configure("string", foreground="#ce9178", font=self.text_font)
        self.code_text.tag_configure("number", foreground="#b5cea8", font=self.text_font)
        self.code_text.tag_configure("comment", foreground="#6a9955", font=self.text_font)
        self.code_text.tag_configure("operator", foreground="#d4d4d4", font=self.text_font)
        self.code_text.tag_configure("function", foreground="#dcdcaa", font=self.text_font)
        
        # Error highlighting - using 6-digit hex color
        self.code_text.tag_configure("error", background="#ff5555")
        self.code_text.tag_configure("error_line", background="#ff5555")
        
        # Current line highlighting
        self.code_text.tag_configure("current_line", background="#2a2d2e")
        self.highlight_current_line()

    def highlight_current_line(self, event=None):
        self.code_text.tag_remove("current_line", "1.0", tk.END)
        
        # Get current line
        cursor_pos = self.code_text.index(tk.INSERT)
        cursor_line = cursor_pos.split('.')[0]
        
        # Highlight current line
        self.code_text.tag_add("current_line", f"{cursor_line}.0", f"{cursor_line}.end")
        
        # Update cursor position
        col = cursor_pos.split('.')[1]
        self.cursor_var.set(f"Ln {cursor_line}, Col {int(col)+1}")

    def update_cursor_position(self, event=None):
        self.highlight_current_line()
        return "break"

    def on_scroll(self, *args):
        self.code_text.yview(*args)
        self.line_numbers.yview(*args)
        self.highlight_current_line()

    def update_scroll(self, *args):
        self.line_numbers.yview_moveto(args[0])
        # Call the scrollbar's set method directly
        self.scrollbar.set(*args)
        self.highlight_current_line()

    def update_line_numbers(self, event=None):
        # Get current line count
        lines = self.code_text.get("1.0", "end-1c").split("\n")
        line_count = len(lines)
        
        # Update line numbers
        self.line_numbers.config(state=tk.NORMAL)
        self.line_numbers.delete("1.0", tk.END)
        
        for i in range(1, line_count + 1):
            self.line_numbers.insert(tk.END, f"{i}\n")
        
        # Highlight error lines
        self.highlight_errors()
        
        self.line_numbers.config(state=tk.DISABLED)
        self.code_text.edit_modified(False)
        return "break"

    def on_code_change(self, event=None):
        self.update_line_numbers()
        self.highlight_syntax()
        return "break"

    def highlight_syntax(self):
        # Remove previous highlighting
        for tag in ["keyword", "type", "string", "number", "comment", "operator", "function"]:
            self.code_text.tag_remove(tag, "1.0", tk.END)
        
        # Define syntax patterns
        syntax_rules = [
            (r'//.*?$', "comment", tk.END),
            (r'/\*.*?\*/', "comment", tk.END),
            (r'\b(int|float|string|bool|return|if|else|while|for|print|function)\b', "keyword"),
            (r'\b(main)\b', "function"),
            (r'".*?"', "string"),
            (r'\b\d+(\.\d+)?\b', "number"),
            (r'[+\-*/=<>!&|]', "operator"),
            (r'[{}();,\[\]]', "operator"),
        ]
        
        # Apply highlighting
        for pattern, tag, *args in syntax_rules:
            start = "1.0"
            while True:
                count_var = tk.IntVar()
                start = self.code_text.search(pattern, start, stopindex=tk.END, 
                                            regexp=True, count=count_var)
                if not start:
                    break
                    
                length = count_var.get()
                end = self.code_text.index(f"{start} + {length}c")
                self.code_text.tag_add(tag, start, end)
                start = end
                
        # Highlight current line
        self.highlight_current_line()

    def highlight_errors(self):
        # Clear previous errors
        self.code_text.tag_remove("error_line", "1.0", tk.END)
        
        # Highlight error lines
        for line in self.error_lines:
            self.code_text.tag_add("error_line", f"{line}.0", f"{line}.end")

    def compile_code(self):
        if self.compiling:
            return
            
        # Clear previous errors
        self.error_lines = []
        self.highlight_errors()
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.DISABLED)
        self.status_var.set("Compiling...")
        
        # Write code to file
        code = self.code_text.get("1.0", tk.END)
        with open("input.txt", "w") as f:
            f.write(code)
        
        # Run compilation in a separate thread
        self.compiling = True
        threading.Thread(target=self.run_compilation, daemon=True).start()

    def run_compilation(self):
        try:
            # Clear previous files
            for f in ["lex.yy.c", "compiler.tab.c", "compiler.tab.h", "compiler", "output"]:
                if os.path.exists(f):
                    os.remove(f)
            
            # Run compilation steps
            steps = [
                ("Flex", ["flex", "compiler.l"]),
                ("Bison", ["bison", "-d", "compiler.y"]),
                ("Compiling", ["gcc", "lex.yy.c", "compiler.tab.c", "ast.c", "-o", "compiler", "-lfl"]),
                ("Running", ["./compiler"])
            ]
            
            self.output_text.config(state=tk.NORMAL)
            self.output_text.delete("1.0", tk.END)
            
            # Run each step
            for step_name, command in steps:
                self.status_var.set(f"{step_name}...")
                self.append_output(f">> {step_name}...\n", "#569cd6")
                
                result = subprocess.run(command, capture_output=True, text=True)
                
                if result.returncode != 0:
                    self.append_output(result.stderr, "#f44747")
                    self.parse_errors(result.stderr)
                    self.status_var.set(f"Error in {step_name}")
                    break
                else:
                    self.append_output(result.stdout, "#dcdcaa")
            
            # If all steps succeeded
            if result.returncode == 0:
                self.status_var.set("Compilation successful!")
                self.append_output("\n>> Program output:\n", "#569cd6")
                
                # Visualize AST
                self.visualize_ast()
                self.populate_symbol_table()
                
        except Exception as e:
            self.append_output(f"Error: {str(e)}", "#f44747")
            self.status_var.set("Compilation failed")
        finally:
            self.compiling = False

    def parse_errors(self, error_output):
        # Extract error lines from compiler output
        self.error_lines = []
        # Updated error pattern to capture Bison line numbers
        error_pattern = r"line (\d+):|Error at line (\d+)|\.y:(\d+)\.\d+"
        
        for line in error_output.split('\n'):
            match = re.search(error_pattern, line)
            if match:
                # Check which group matched
                if match.group(1):
                    error_line = int(match.group(1))
                elif match.group(2):
                    error_line = int(match.group(2))
                elif match.group(3):
                    error_line = int(match.group(3))
                else:
                    continue
                
                self.error_lines.append(error_line)
                self.append_output(line + "\n", "#f44747")
                
                # Add clickable error
                self.output_text.tag_config(f"error_{error_line}", foreground="#ff6e6e", 
                                          underline=True)
                self.output_text.tag_bind(f"error_{error_line}", "<Button-1>", 
                                        lambda e, line=error_line: self.jump_to_line(line))
            else:
                self.append_output(line + "\n", "#f44747")
        
        # Highlight errors in editor
        self.highlight_errors()
        
        # Jump to first error
        if self.error_lines:
            self.jump_to_line(self.error_lines[0])

    def jump_to_line(self, line):
        self.code_text.see(f"{line}.0")
        self.code_text.mark_set(tk.INSERT, f"{line}.0")
        self.highlight_current_line()

    def append_output(self, text, color):
        self.output_text.config(state=tk.NORMAL)
        self.output_text.insert(tk.END, text, ("color", color))
        self.output_text.tag_config("color", foreground=color)
        self.output_text.see(tk.END)
        self.output_text.config(state=tk.DISABLED)

    def visualize_ast(self):
        try:
            # Generate sample AST visualization
            dot = graphviz.Digraph(comment='AST')
            dot.attr('node', shape='box', style='filled', color='#1e1e1e', 
                    fontcolor='#d4d4d4', fillcolor='#252526')
            
            # Sample AST structure
            dot.node('P', 'Program')
            dot.node('M', 'main()')
            dot.node('D1', 'Declaration\nx: int = 10')
            dot.node('D2', 'Declaration\ny: float = 3.14')
            dot.node('D3', 'Declaration\nname: string = "Compiler"')
            dot.node('I', 'If')
            dot.node('C', 'Condition\nx > 5')
            dot.node('T', 'Then\nprint("x is greater than 5")')
            dot.node('E', 'Else\nprint("x is 5 or less")')
            dot.node('F', 'For Loop')
            dot.node('D4', 'Declaration\ni: int = 0')
            dot.node('C2', 'Condition\ni < 3')
            dot.node('U', 'Update\ni = i + 1')
            dot.node('B', 'Block\nprint(i)')
            dot.node('R', 'Return 0')
            
            dot.edges([
                ('P', 'M'), ('M', 'D1'), ('M', 'D2'), ('M', 'D3'), ('M', 'I'), ('M', 'F'), ('M', 'R'),
                ('I', 'C'), ('I', 'T'), ('I', 'E'),
                ('F', 'D4'), ('F', 'C2'), ('F', 'U'), ('F', 'B')
            ])
            
            # Render and display
            dot.format = 'png'
            dot.render('ast', view=False, cleanup=True)
            
            # Display in GUI
            img = Image.open("ast.png")
            img = img.resize((800, 600), Image.LANCZOS)
            self.ast_img = ImageTk.PhotoImage(img)
            
            self.ast_canvas.delete("all")
            self.ast_canvas.create_image(20, 20, anchor=tk.NW, image=self.ast_img)
            
        except Exception as e:
            self.append_output(f"AST Visualization Error: {str(e)}\n", "#f44747")

    def populate_symbol_table(self):
        # Clear previous data
        for item in self.symbol_tree.get_children():
            self.symbol_tree.delete(item)
        
        # Add sample symbol table data
        symbols = [
            ("main", "function", "void", "global"),
            ("x", "int", "10", "main"),
            ("y", "float", "3.14", "main"),
            ("name", "string", '"Compiler"', "main"),
            ("i", "int", "0", "for loop"),
        ]
        
        for symbol in symbols:
            self.symbol_tree.insert("", tk.END, values=symbol)

    def show_ast(self):
        self.notebook.select(1)

    def show_symbol_table(self):
        self.notebook.select(2)

    def new_file(self):
        self.code_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.DISABLED)
        self.error_lines = []
        self.highlight_errors()
        self.update_line_numbers()
        self.status_var.set("New file created")
        self.code_text.focus()

    def load_file(self):
        filepath = filedialog.askopenfilename(filetypes=[
            ("Custom Language Files", "*.cl"),
            ("C Files", "*.c"),
            ("Text Files", "*.txt"),
            ("All Files", "*.*")
        ])
        
        if filepath:
            try:
                with open(filepath, "r") as f:
                    content = f.read()
                    self.code_text.delete("1.0", tk.END)
                    self.code_text.insert(tk.END, content)
                
                self.update_line_numbers()
                self.highlight_syntax()
                self.status_var.set(f"Loaded: {os.path.basename(filepath)}")
                
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load file:\n{str(e)}")

    def save_file(self):
        filepath = filedialog.asksaveasfilename(
            defaultextension=".cl",
            filetypes=[
                ("Custom Language Files", "*.cl"),
                ("C Files", "*.c"),
                ("Text Files", "*.txt"),
                ("All Files", "*.*")
            ]
        )
        
        if filepath:
            try:
                with open(filepath, "w") as f:
                    f.write(self.code_text.get("1.0", tk.END))
                
                self.status_var.set(f"Saved: {os.path.basename(filepath)}")
                
            except Exception as e:
                messagebox.showerror("Error", f"Failed to save file:\n{str(e)}")

    def clear_all(self):
        self.code_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        self.output_text.config(state=tk.DISABLED)
        self.error_lines = []
        self.highlight_errors()
        self.update_line_numbers()
        self.status_var.set("Cleared editor and output")
        self.code_text.focus()

    def undo(self):
        try:
            self.code_text.edit_undo()
        except:
            pass

    def redo(self):
        try:
            self.code_text.edit_redo()
        except:
            pass

    def cut(self):
        self.code_text.event_generate("<<Cut>>")

    def copy(self):
        self.code_text.event_generate("<<Copy>>")

    def paste(self):
        self.code_text.event_generate("<<Paste>>")

    def zoom_in(self):
        size = self.text_font.cget("size") + 1
        self.text_font.configure(size=size)
        self.update_line_numbers()

    def zoom_out(self):
        size = max(8, self.text_font.cget("size") - 1)
        self.text_font.configure(size=size)
        self.update_line_numbers()

if __name__ == "__main__":
    root = tk.Tk()
    app = CompilerGUI(root)
    root.mainloop()