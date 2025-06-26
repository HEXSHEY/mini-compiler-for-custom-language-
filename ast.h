#ifndef AST_H
#define AST_H

// Define type constants to avoid conflicts
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_STRING 3
#define TYPE_BOOL 4

typedef enum {
    PROGRAM_NODE,
    STMT_LIST,
    DECL_NODE,
    ASSIGN_NODE,
    BINOP_NODE,
    UNARYOP_NODE,
    VAR_NODE,
    NUM_NODE,
    FLOAT_NODE,
    STR_NODE,
    BOOL_NODE,
    IF_NODE,
    IF_ELSE_NODE,
    WHILE_NODE,
    FOR_NODE,
    PRINT_NODE,
    RETURN_NODE,
    FUNC_DECL_NODE,
    FUNC_CALL_NODE
} NodeType;

typedef struct ASTNode {
    NodeType node_type;
    int data_type;
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* extra;  // Add extra field for for-loop update
    void* value;
} ASTNode;

ASTNode* create_ast_node(NodeType type, ASTNode* left, ASTNode* right, void* value);
void execute_ast(ASTNode* node);

#endif