%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);
extern int yylineno;
extern FILE *yyin;

void yyerror(const char *s);

// Global AST root
ASTNode* program_root = NULL;

%}

%union {
    int num;
    double fnum;
    char* str;
    ASTNode* node;
    int type_code;
}

%token <num> NUMBER
%token <fnum> FLOATNUM
%token <str> ID STRINGLIT
%token INT FLOAT STRINGTYPE BOOL TRUE FALSE
%token RETURN IF ELSE WHILE FOR PRINT FUNCTION
%token EQ NEQ GE LE GT LT ASSIGN PLUS MINUS MUL DIV AND OR NOT
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

// Operator precedence (lowest to highest)
%nonassoc IF
%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left MUL DIV
%nonassoc NOT UMINUS

%type <node> program stmt_list stmt expr decl assign
%type <node> if_stmt while_stmt for_stmt print_stmt return_stmt
%type <node> function_decl function_call
%type <type_code> type

%start program

%%

program: 
    function_decl { program_root = $1; }
    | stmt_list { program_root = create_ast_node(PROGRAM_NODE, $1, NULL, NULL); }
    ;

stmt_list:
    stmt { $$ = create_ast_node(STMT_LIST, $1, NULL, NULL); }
    | stmt_list stmt { $$ = create_ast_node(STMT_LIST, $1, $2, NULL); }
    ;

stmt:
    decl SEMICOLON { $$ = $1; }
    | assign SEMICOLON { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | print_stmt SEMICOLON { $$ = $1; }
    | return_stmt SEMICOLON { $$ = $1; }
    | function_call SEMICOLON { $$ = $1; }
    | expr SEMICOLON { $$ = $1; }
    ;

decl:
    type ID { 
        ASTNode* node = create_ast_node(DECL_NODE, NULL, NULL, $2);
        node->data_type = $1;
        $$ = node;
    }
    | type ID ASSIGN expr { 
        ASTNode* node = create_ast_node(DECL_NODE, $4, NULL, $2);
        node->data_type = $1;
        $$ = node;
    }
    ;

assign:
    ID ASSIGN expr { $$ = create_ast_node(ASSIGN_NODE, $3, NULL, $1); }
    ;

expr:
    ID { $$ = create_ast_node(VAR_NODE, NULL, NULL, $1); }
    | NUMBER { 
        int* num_val = malloc(sizeof(int));
        *num_val = $1;
        $$ = create_ast_node(NUM_NODE, NULL, NULL, num_val); 
    }
    | FLOATNUM { 
        double* fnum_val = malloc(sizeof(double));
        *fnum_val = $1;
        $$ = create_ast_node(FLOAT_NODE, NULL, NULL, fnum_val); 
    }
    | STRINGLIT { $$ = create_ast_node(STR_NODE, NULL, NULL, $1); }
    | TRUE { 
        int* bool_val = malloc(sizeof(int));
        *bool_val = 1;
        $$ = create_ast_node(BOOL_NODE, NULL, NULL, bool_val); 
    }
    | FALSE { 
        int* bool_val = malloc(sizeof(int));
        *bool_val = 0;
        $$ = create_ast_node(BOOL_NODE, NULL, NULL, bool_val); 
    }
    | function_call { $$ = $1; }
    | LPAREN expr RPAREN { $$ = $2; }
    | expr PLUS expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "+"); }
    | expr MINUS expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "-"); }
    | expr MUL expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "*"); }
    | expr DIV expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "/"); }
    | expr EQ expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "=="); }
    | expr NEQ expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "!="); }
    | expr GT expr { $$ = create_ast_node(BINOP_NODE, $1, $3, ">"); }
    | expr LT expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "<"); }
    | expr GE expr { $$ = create_ast_node(BINOP_NODE, $1, $3, ">="); }
    | expr LE expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "<="); }
    | expr AND expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "&&"); }
    | expr OR expr { $$ = create_ast_node(BINOP_NODE, $1, $3, "||"); }
    | NOT expr { $$ = create_ast_node(UNARYOP_NODE, $2, NULL, "!"); }
    | MINUS expr %prec UMINUS { $$ = create_ast_node(UNARYOP_NODE, $2, NULL, "-"); }
    ;

if_stmt:
    IF LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        $$ = create_ast_node(IF_NODE, $3, $6, NULL);
    }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE {
        $$ = create_ast_node(IF_ELSE_NODE, $3, $6, $10);
    }
    ;

while_stmt:
    WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        $$ = create_ast_node(WHILE_NODE, $3, $6, NULL);
    }
    ;

for_stmt:
    FOR LPAREN decl SEMICOLON expr SEMICOLON assign RPAREN LBRACE stmt_list RBRACE {
        ASTNode* for_node = create_ast_node(FOR_NODE, $3, $5, $10);
        for_node->extra = $7;  // Store update in extra field
        $$ = for_node;
    }
    ;

print_stmt:
    PRINT LPAREN expr RPAREN { $$ = create_ast_node(PRINT_NODE, $3, NULL, NULL); }
    ;

return_stmt:
    RETURN expr { $$ = create_ast_node(RETURN_NODE, $2, NULL, NULL); }
    ;

function_decl:
    FUNCTION ID LPAREN RPAREN LBRACE stmt_list RBRACE {
        $$ = create_ast_node(FUNC_DECL_NODE, $6, NULL, $2);
    }
    ;

function_call:
    ID LPAREN RPAREN { $$ = create_ast_node(FUNC_CALL_NODE, NULL, NULL, $1); }
    ;

type:
    INT { $$ = TYPE_INT; }
    | FLOAT { $$ = TYPE_FLOAT; }
    | STRINGTYPE { $$ = TYPE_STRING; }
    | BOOL { $$ = TYPE_BOOL; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}

int main() {
    yyin = fopen("input.txt", "r");
    if (!yyin) {
        perror("input.txt");
        return 1;
    }
    yyparse();
    fclose(yyin);
    
    // Generate and execute code
    if (program_root) {
        execute_ast(program_root);
    }
    
    return 0;
}