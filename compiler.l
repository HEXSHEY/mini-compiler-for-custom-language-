%{
#include "ast.h"
#include "compiler.tab.h"
#include <stdlib.h>
#include <string.h>
extern int yylineno;
%}

%option yylineno

ID      [a-zA-Z_][a-zA-Z0-9_]*
NUM     [0-9]+
FLOAT   [0-9]+\.[0-9]+
STRING  \"([^\\\"]|\\.)*\"

%%

"int"       { return INT; }
"float"     { return FLOAT; }
"string"    { return STRINGTYPE; }
"bool"      { return BOOL; }
"true"      { return TRUE; }
"false"     { return FALSE; }
"return"    { return RETURN; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"print"     { return PRINT; }
"function"  { return FUNCTION; }

{ID}        { yylval.str = strdup(yytext); return ID; }
{NUM}       { yylval.num = atoi(yytext); return NUMBER; }
{FLOAT}     { yylval.fnum = atof(yytext); return FLOATNUM; }
{STRING}    { yylval.str = strdup(yytext); return STRINGLIT; }

"=="        { return EQ; }
"!="        { return NEQ; }
">="        { return GE; }
"<="        { return LE; }
">"         { return GT; }
"<"         { return LT; }
"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMICOLON; }
","         { return COMMA; }

[ \t\r]+    ;  // ignore whitespace
\n          ;  // ignore newlines but track line numbers
\/\/.*      ;  // ignore single-line comments
\/\*([^*]|\*+[^*/])*\*+\/ ; // ignore multi-line comments

.           { printf("Unrecognized character: %s at line %d\n", yytext, yylineno); }

%%

int yywrap(void) { return 1; }