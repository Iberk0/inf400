%{
#include "lexer.hpp"

#include <kiraz/ast/Operator.h>
#include <kiraz/ast/Literal.h>
#include <kiraz/token/Literal.h>

int yyerror(const char *msg);
extern std::shared_ptr<Token> curtoken;
extern int yylineno;
%}

%token REJECTED
%token L_INTEGER L_STRING IDENTIFIER
%token KW_IMPORT KW_FUNC KW_IF KW_WHILE KW_CLASS KW_LET KW_ELSE KW_RETURN
%token OP_PLUS OP_MINUS OP_MULT OP_DIVF OP_ASSIGN
%token OP_LPAREN OP_RPAREN OP_LBRACE OP_RBRACE
%token OP_SCOLON OP_COLON OP_COMMA OP_DOT
%token OP_LESS OP_LESSEQ OP_GREATER OP_GREATEREQ OP_EQUAL OP_NOT_EQUAL

%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIVF
%right OP_ASSIGN
%%

program:
    stmt_list {$$ = Node::add<ast::Module>($1);}
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
    expr_stmt
    | let_stmt
    | func_decl  OP_SCOLON
    | class_decl OP_SCOLON
    | if_stmt   OP_SCOLON
    | while_stmt OP_SCOLON
    | import_stmt
    | call_stmt OP_SCOLON 
    | return_stmt OP_SCOLON
    ;

expr_stmt:
    expr OP_SCOLON 
    ;

class_decl:
    KW_CLASS literal OP_LBRACE stmt_list OP_RBRACE 
    { $$ = Node::add<ast::Class>($2, $4); }
    |KW_CLASS literal OP_LBRACE OP_RBRACE { $$ = Node::add<ast::Class>($2);}
    ;

let_stmt:
    KW_LET literal OP_ASSIGN expr OP_SCOLON
    { $$ = Node::add<ast::Let>($2, nullptr, $4); }
    | KW_LET literal OP_COLON literal OP_ASSIGN expr OP_SCOLON
    { $$ = Node::add<ast::Let>($2, $4, $6); }
    | KW_LET literal OP_COLON literal OP_SCOLON
    { $$ = Node::add<ast::Let>($2, $4, nullptr); }
    ;

func_decl:
    KW_FUNC literal OP_LPAREN func_args OP_RPAREN OP_COLON literal OP_LBRACE scope OP_RBRACE
    { $$ = Node::add<ast::Func>($2, $4, $7, $9); }
    ;

func_args:
    
    { $$ = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{}); }
    | func_arg
    { $$ = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{ $1 }); }
    | func_args OP_COMMA func_arg
    {
        auto args = std::dynamic_pointer_cast<ast::FuncArgs>($1);
        args->add_statement($3);
        $$ = args;
    }
    ;

func_arg:
    literal OP_COLON literal
    {
        $$ = Node::add<ast::FuncArg>($1, $3);
    }
    ;

if_stmt:
    KW_IF OP_LPAREN expr OP_RPAREN OP_LBRACE scope OP_RBRACE KW_ELSE else_stmt
    { $$ = Node::add<ast::If>($3, $6, $9); }
    | KW_IF OP_LPAREN expr OP_RPAREN OP_LBRACE scope OP_RBRACE
    { $$ = Node::add<ast::If>($3, $6, nullptr); }
    ;

else_stmt:
    OP_LBRACE scope OP_RBRACE { $$ = $2;}
    | if_stmt
    ;

while_stmt:
    KW_WHILE OP_LPAREN expr OP_RPAREN OP_LBRACE scope OP_RBRACE
    { $$ = Node::add<ast::While>($3, $6); }
    ;

import_stmt:
    KW_IMPORT literal OP_SCOLON
    { $$ = Node::add<ast::Import>($2); }
    ;

call_stmt:
    dot OP_LPAREN call_args OP_RPAREN {
        $$ = Node::add<ast::Call>($1, $3);
    }
    ;

dot:
    literal
    | dot OP_DOT literal { $$ = Node::add<ast::OpDot>($1,$3);}
    ;

call_args:
    { $$ = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{}); }
    | literal
    { $$ = Node::add<ast::FuncArgs>(std::vector<Node::Ptr>{ $1 }); }
    | call_args OP_COMMA literal
    {
        auto args = std::dynamic_pointer_cast<ast::FuncArgs>($1);
        args->add_statement($3);
        $$ = args;
    }

return_stmt:
    KW_RETURN return_value           { $$ = Node::add<ast::Return>($2);}
    ;

return_value:
    call_stmt          
    | compare_expr            
    ;
scope:
    { $$ = Node::add<ast::NodeList>(std::vector<Node::Ptr>{}); }
    |stmt { 
            auto nodeList = Node::add<ast::NodeList>();
            nodeList->add_statement($1);
            $$ = nodeList;
        }
    | stmt_list stmt { 
            $$ = $1;
            std::dynamic_pointer_cast<ast::NodeList>($$)->add_statement($2);
        }
    ;


expr:
    assign_expr
    ;

assign_expr:
    compare_expr 
    | compare_expr OP_ASSIGN compare_expr { $$ = Node::add<ast::OpAssign>($1, $3); }
    ;

compare_expr:
    addsub
    | compare_expr OP_LESS addsub { $$ = Node::add<ast::OpLess>($1, $3); }
    | compare_expr OP_LESSEQ addsub { $$ = Node::add<ast::OpLessEq>($1, $3); }
    | compare_expr OP_GREATER addsub { $$ = Node::add<ast::OpGreater>($1, $3); }
    | compare_expr OP_GREATEREQ addsub { $$ = Node::add<ast::OpGreaterEq>($1, $3); }
    | compare_expr OP_EQUAL addsub { $$ = Node::add<ast::OpEqual>($1, $3); }
    | compare_expr OP_NOT_EQUAL addsub { $$ = Node::add<ast::OpNotEqual>($1, $3); }
    ;

addsub:
    muldiv
    | addsub OP_PLUS muldiv { $$ = Node::add<ast::OpPlus>($1, $3); }
    | addsub OP_MINUS muldiv { $$ = Node::add<ast::OpMinus>($1, $3); }
    ;

muldiv:
    posneg
    | muldiv OP_MULT posneg { $$ = Node::add<ast::OpMult>($1, $3); }
    | muldiv OP_DIVF posneg { $$ = Node::add<ast::OpDivF>($1, $3); }
    ;

posneg:
    OP_MINUS posneg { $$ = Node::add<ast::Signed>(OP_MINUS, $2); }
    | OP_PLUS posneg { $$ = Node::add<ast::Signed>(OP_PLUS, $2); }
    | OP_LPAREN expr OP_RPAREN { $$ = $2; } 
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
    } else {
        fmt::print("** Parser Error at {}:{}, null token\n",
                   yylineno, Token::colno);
    }
    Token::colno = 0;
    Node::reset_root();
    return 1;
}
