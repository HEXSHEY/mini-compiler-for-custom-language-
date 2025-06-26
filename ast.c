#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Symbol table structure
typedef struct Symbol {
    char* name;
    int type;
    void* value;
    struct Symbol* next;
} Symbol;

Symbol* symbol_table = NULL;

// Helper function to find a symbol
Symbol* find_symbol(char* name) {
    Symbol* current = symbol_table;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Helper function to add a symbol
void add_symbol(char* name, int type, void* value) {
    Symbol* sym = find_symbol(name);
    if (!sym) {
        sym = malloc(sizeof(Symbol));
        sym->name = strdup(name);
        sym->type = type;
        sym->value = value;
        sym->next = symbol_table;
        symbol_table = sym;
    } else {
        // Update existing symbol
        if (sym->value) free(sym->value);
        sym->value = value;
        sym->type = type;
    }
}

// Evaluate expression
void* eval_expr(ASTNode* node) {
    if (!node) return NULL;
    
    switch (node->node_type) {
        case NUM_NODE:
            return node->value;
        case FLOAT_NODE:
            return node->value;
        case STR_NODE: {
            // Remove quotes from string literal
            char* str_val = (char*)node->value;
            if (str_val[0] == '"' && str_val[strlen(str_val)-1] == '"') {
                char* unquoted = strdup(str_val + 1);
                unquoted[strlen(unquoted)-1] = '\0';
                return unquoted;
            }
            return strdup(str_val);
        }
        case BOOL_NODE:
            return node->value;
        case VAR_NODE: {
            Symbol* sym = find_symbol((char*)node->value);
            return sym ? sym->value : NULL;
        }
        case BINOP_NODE: {
            int* left_val = eval_expr(node->left);
            int* right_val = eval_expr(node->right);
            int* result = malloc(sizeof(int));
            char* op = (char*)node->value;
            
            if (strcmp(op, "+") == 0) {
                *result = *left_val + *right_val;
            } else if (strcmp(op, "-") == 0) {
                *result = *left_val - *right_val;
            } else if (strcmp(op, "*") == 0) {
                *result = *left_val * *right_val;
            } else if (strcmp(op, "/") == 0) {
                *result = *left_val / *right_val;
            } else if (strcmp(op, ">") == 0) {
                *result = *left_val > *right_val;
            } else if (strcmp(op, "<") == 0) {
                *result = *left_val < *right_val;
            } else if (strcmp(op, ">=") == 0) {
                *result = *left_val >= *right_val;
            } else if (strcmp(op, "<=") == 0) {
                *result = *left_val <= *right_val;
            } else if (strcmp(op, "==") == 0) {
                *result = *left_val == *right_val;
            } else if (strcmp(op, "!=") == 0) {
                *result = *left_val != *right_val;
            } else if (strcmp(op, "&&") == 0) {
                *result = *left_val && *right_val;
            } else if (strcmp(op, "||") == 0) {
                *result = *left_val || *right_val;
            }
            return result;
        }
        case UNARYOP_NODE: {
            int* operand = eval_expr(node->left);
            int* result = malloc(sizeof(int));
            char* op = (char*)node->value;
            
            if (strcmp(op, "-") == 0) {
                *result = -(*operand);
            } else if (strcmp(op, "!") == 0) {
                *result = !(*operand);
            }
            return result;
        }
        default:
            return NULL;
    }
}

// Execute AST
void execute_ast(ASTNode* node) {
    if (!node) return;
    
    switch (node->node_type) {
        case PROGRAM_NODE:
            execute_ast(node->left);
            break;
            
        case STMT_LIST:
            execute_ast(node->left);
            execute_ast(node->right);
            break;
            
        case DECL_NODE: {
            // Handle variable declaration
            char* var_name = (char*)node->value;
            add_symbol(var_name, node->data_type, NULL);
            if (node->left) { // Initialization
                void* value = eval_expr(node->left);
                add_symbol(var_name, node->data_type, value);
            }
            break;
        }
        
        case ASSIGN_NODE: {
            // Handle variable assignment
            char* var_name = (char*)node->value;
            void* value = eval_expr(node->left);
            add_symbol(var_name, TYPE_INT, value);
            break;
        }
        
        case PRINT_NODE: {
            // Handle print statements
            void* value = eval_expr(node->left);
            if (value) {
                if (node->left->node_type == STR_NODE) {
                    printf("%s\n", (char*)value);
                } else if (node->left->node_type == NUM_NODE) {
                    printf("%d\n", *(int*)value);
                } else if (node->left->node_type == FLOAT_NODE) {
                    printf("%f\n", *(double*)value);
                } else if (node->left->node_type == BOOL_NODE) {
                    printf("%s\n", *(int*)value ? "true" : "false");
                } else if (node->left->node_type == VAR_NODE) {
                    Symbol* sym = find_symbol((char*)node->left->value);
                    if (sym) {
                        if (sym->type == TYPE_STRING) {
                            printf("%s\n", (char*)sym->value);
                        } else if (sym->type == TYPE_INT) {
                            printf("%d\n", *(int*)sym->value);
                        } else if (sym->type == TYPE_FLOAT) {
                            printf("%f\n", *(double*)sym->value);
                        } else if (sym->type == TYPE_BOOL) {
                            printf("%s\n", *(int*)sym->value ? "true" : "false");
                        }
                    }
                }
            }
            break;
        }
        
        case IF_NODE: {
            // Basic if statement
            int* condition = eval_expr(node->left);
            if (condition && *condition) {
                execute_ast(node->right);
            }
            break;
        }
        
        case IF_ELSE_NODE: {
            // If-else statement
            int* condition = eval_expr(node->left);
            if (condition && *condition) {
                execute_ast(node->right);
            } else {
                execute_ast((ASTNode*)node->value);
            }
            break;
        }
        
        case FOR_NODE: {
            // For loop execution
            execute_ast(node->left);  // Initialization
            
            while (1) {
                // Evaluate condition
                int* condition_val = eval_expr(node->right);
                if (!condition_val || !*condition_val) break;
                
                // Execute body
                execute_ast((ASTNode*)node->value);
                
                // Execute update
                execute_ast(node->extra);
            }
            break;
        }
        
        default:
            // Recursively execute children
            execute_ast(node->left);
            execute_ast(node->right);
    }
}

ASTNode* create_ast_node(NodeType type, ASTNode* left, ASTNode* right, void* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = type;
    node->data_type = TYPE_INT;
    node->left = left;
    node->right = right;
    node->extra = NULL;  // Initialize extra to NULL
    node->value = value;
    return node;
}