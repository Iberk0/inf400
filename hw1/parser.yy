%{
#include "lexer.hpp"

#include <kiraz/ast/Operator.h>
#include <kiraz/ast/Literal.h>

#include <kiraz/token/Literal.h>

int yyerror(const char *msg);
extern std::shared_ptr<Token> curtoken;
extern int yylineno;
%}

%token    REJECTED

%token L_INTEGER L_STRING IDENTIFIER
%token KW_IMPORT KW_FUNC KW_IF KW_WHILE KW_CLASS KW_LET
%token OP_PLUS OP_MINUS OP_MULT OP_DIVF OP_ASSIGN
%token OP_LPAREN OP_RPAREN OP_LBRACE OP_RBRACE
%token OP_SCOLON OP_COLON OP_COMMA
%token OP_LESS OP_LESSEQ OP_GREATER OP_GREATEREQ OP_EQUAL OP_NOT_EQUAL

%%

/* TODO */

stmt: %empty

%%

int yyerror(const char *s) {
    if (curtoken) {
        fmt::print("** Parser Error at {}:{} at token: {}\n",
            yylineno, Token::colno, curtoken->as_string());
    }
    else {
        fmt::print("** Parser Error at {}:{}, null token\n",
            yylineno, Token::colno);
    }
    Token::colno = 0;
    Node::reset_root();
    return 1;
}
