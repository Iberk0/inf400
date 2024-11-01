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
%token KW_IMPORT KW_FUNC KW_IF KW_WHILE KW_CLASS KW_LET KW_ELSE
%token OP_PLUS OP_MINUS OP_MULT OP_DIVF OP_ASSIGN
%token OP_LPAREN OP_RPAREN OP_LBRACE OP_RBRACE
%token OP_SCOLON OP_COLON OP_COMMA
%token OP_LESS OP_LESSEQ OP_GREATER OP_GREATEREQ OP_EQUAL OP_NOT_EQUAL

%%

stmt:
    addsub
    |IDENTIFIER { $$= Node::add<ast::Identifier>(curtoken);}
addsub:
    muldiv
    | OP_LPAREN addsub OP_RPAREN { $$ = $2;}
    | stmt OP_PLUS stmt  { $$ = Node::add<ast::OpPlus>($1,$3);}
    | stmt OP_MINUS stmt { $$ = Node::add<ast::OpMinus>($1,$3);}
    ;

muldiv:
    posneg  
    | stmt OP_MULT stmt { $$ = Node::add<ast::OpMult>($1,$3);}
    | stmt OP_DIVF stmt { $$ = Node::add<ast::OpDivF>($1,$3);}
    ;

posneg:
    L_INTEGER { $$ = Node::add<ast::Integer>(curtoken);}
    | OP_PLUS stmt  { $$ = Node::add<ast::Signed>(OP_PLUS,$2);}
    | OP_MINUS stmt { $$ = Node::add<ast::Signed>(OP_MINUS,$2);}
    ;
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
