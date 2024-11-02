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
%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIVF

%%

program:
        stmt_list { $$ = Node::add<ast::Module>($1);  }
        ;
stmt_list:
        stmt { 
            auto nodeList = Node::add<ast::NodeList>();
            nodeList->add_statement($1);
            $$ = nodeList;
        }
        | stmt_list stmt { 
            $$ = $1;
            std::dynamic_pointer_cast<ast::NodeList>($$)->add_statement($2);
        }
        ;
stmt:
    expr OP_SCOLON 
    | let_stmt 
    ;         
let_stmt:
    KW_LET literal OP_ASSIGN expr OP_SCOLON
    { $$ = Node::add<ast::Let>($2, nullptr, $4); }
    | KW_LET literal OP_COLON literal OP_ASSIGN expr OP_SCOLON
    { $$ = Node::add<ast::Let>($2, $4, $6); }
    | KW_LET literal OP_COLON literal OP_SCOLON
    { $$ = Node::add<ast::Let>($2, $4, nullptr); }
    ;

expr:
    expr OP_PLUS expr { $$ = Node::add<ast::OpPlus>($1, $3); }
    | expr OP_MINUS expr { $$ = Node::add<ast::OpMinus>($1, $3); }
    | expr OP_MULT expr { $$ = Node::add<ast::OpMult>($1, $3); }
    | expr OP_DIVF expr { $$ = Node::add<ast::OpDivF>($1, $3); }
    | expr OP_LESS expr { $$ = Node::add<ast::OpLess>($1, $3); }
    | expr OP_LESSEQ expr { $$ = Node::add<ast::OpLessEq>($1, $3); }
    | expr OP_GREATER expr { $$ = Node::add<ast::OpGreater>($1, $3); }
    | expr OP_GREATEREQ expr { $$ = Node::add<ast::OpGreaterEq>($1, $3); }
    | expr OP_EQUAL expr { $$ = Node::add<ast::OpEqual>($1, $3); }
    | expr OP_NOT_EQUAL expr { $$ = Node::add<ast::OpNotEqual>($1, $3); }
    | expr OP_ASSIGN expr { $$ = Node::add<ast::OpAssign>($1, $3); }
    | OP_LPAREN expr OP_RPAREN { $$ = $2; }
    | OP_MINUS expr { $$ = Node::add<ast::Signed>(OP_MINUS, $2); }
    | OP_PLUS expr { $$ = Node::add<ast::Signed>(OP_PLUS, $2); }
    | literal
    ;


literal:
    L_INTEGER { $$ = Node::add<ast::Integer>(curtoken); }
    | L_STRING { $$ = Node::add<ast::StringLiteral>(curtoken); }
    | IDENTIFIER { $$ = Node::add<ast::Identifier>(curtoken); }
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