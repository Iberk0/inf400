%{
#include "main.h"
#include "lexer.h"

#include <kiraz/ast/Operator.h>
#include <kiraz/ast/Literal.h>

#include <kiraz/token/Literal.h>

int yyerror(const char *msg);
extern std::shared_ptr<Token> curtoken;
extern int yylineno;
%}

%token OP_LPAREN
%token OP_RPAREN

%token OP_PLUS
%token OP_MINUS
%token OP_DIVF
%token OP_MULT


%token OP_COMMA
%token OP_ASSIGN
%token OP_LBRACE
%token OP_RBRACE
%token OP_SCOLON

%token L_INTEGER
%token IDENTIFIER
%token TYPE_ANNOT
%token KW_FUNC
%token KW_LET
%token COLON

%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIVF

%token    REJECTED



%%


stmt: 
    func_stmt
    | let_stmt
    | addsub
    ;

func_stmt:
    KW_FUNC IDENTIFIER OP_LPAREN arg_list OP_RPAREN COLON TYPE_ANNOT OP_LBRACE scope OP_RBRACE  { $$ == Node::add<ast::Func>($2, $4, $7, $9);}
    ;

arg_list:
    
    | arg_list OP_COMMA arg_declaration
    | arg_declaration
    ;

arg_declaration:
    IDENTIFIER COLON TYPE_ANNOT
    ;

scope:
    stmt OP_SCOLON scope
    | stmt OP_SCOLON
    ;

let_stmt:
    KW_LET IDENTIFIER COLON TYPE_ANNOT
    | KW_LET IDENTIFIER COLON TYPE_ANNOT OP_ASSIGN stmt
    ;

assignment_stmt:
    IDENTIFIER OP_ASSIGN stmt { $$ = Node::add<ast::OpAssign>($1, $3); }
    ;
    


addsub:
    muldiv
    | OP_LPAREN addsub OP_RPAREN { $$ = $2;}
    | stmt OP_PLUS stmt  { $$ = Node::add<ast::OpAdd>($1,$3);}
    | stmt OP_MINUS stmt { $$ = Node::add<ast::OpSub>($1,$3);}
    ;

muldiv:
    posneg  
    | stmt OP_MULT stmt { $$ = Node::add<ast::OpMult>($1,$3);}
    | stmt OP_DIVF stmt { $$ = Node::add<ast::OpDivF>($1,$3);}
    ;

posneg:
    L_INTEGER { $$ = Node::add<ast::Integer>(curtoken);}
    | OP_PLUS stmt  { $$ = Node::add<ast::SignedNode>(OP_PLUS,$2);}
    | OP_MINUS stmt { $$ = Node::add<ast::SignedNode>(OP_MINUS,$2);}
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
