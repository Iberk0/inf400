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
%token KW_IMPORT KW_FUNC KW_IF KW_WHILE KW_CLASS KW_LET KW_ELSE
%token OP_PLUS OP_MINUS OP_MULT OP_DIVF OP_ASSIGN
%token OP_LPAREN OP_RPAREN OP_LBRACE OP_RBRACE
%token OP_SCOLON OP_COLON OP_COMMA
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
    | while_stmt OP_SCOLON
    | import_stmt
    | if_stmt OP_SCOLON
    ;

expr_stmt:
    expr OP_SCOLON 
    ;

class_decl:
    KW_CLASS literal OP_LBRACE class_body OP_RBRACE 
    { $$ = Node::add<ast::Class>($2, $4); }
    ;


class_body:
    class_member    { 
            auto member = Node::add<ast::ClassBody>();
            member->add_statement($1);
            $$ = member;
        }
    | class_body class_member
    {
        auto body = std::dynamic_pointer_cast<ast::ClassBody>($1);
        body->add_statement($2);
        $$ = body;
    }
    | { $$ = Node::add<ast::ClassBody>(std::vector<Node::Ptr>{}); }
    ;

class_member:
    let_stmt  
    | func_decl OP_SCOLON
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
    | KW_FUNC literal OP_LPAREN func_args OP_RPAREN OP_LBRACE scope OP_RBRACE 
    { $$ = Node::add<ast::Func>($2, $4, nullptr, $8); }
    ;



import_stmt:
    KW_IMPORT literal OP_SCOLON
    { $$ = Node::add<ast::Import>($2); }
    ;

func_args:
    /* empty */
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
    
while_stmt:
    KW_WHILE OP_LPAREN expr OP_RPAREN OP_LBRACE scope OP_RBRACE
    { $$ = Node::add<ast::While>($3, $6); }
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
    relational_expr 
    | assign_expr OP_ASSIGN relational_expr { $$ = Node::add<ast::OpAssign>($1, $3); }
    ;

relational_expr:
    add_expr
    | relational_expr OP_LESS add_expr { $$ = Node::add<ast::OpLess>($1, $3); }
    | relational_expr OP_LESSEQ add_expr { $$ = Node::add<ast::OpLessEq>($1, $3); }
    | relational_expr OP_GREATER add_expr { $$ = Node::add<ast::OpGreater>($1, $3); }
    | relational_expr OP_GREATEREQ add_expr { $$ = Node::add<ast::OpGreaterEq>($1, $3); }
    | relational_expr OP_EQUAL add_expr { $$ = Node::add<ast::OpEqual>($1, $3); }
    | relational_expr OP_NOT_EQUAL add_expr { $$ = Node::add<ast::OpNotEqual>($1, $3); }
    ;

add_expr:
    mult_expr
    | add_expr OP_PLUS mult_expr { $$ = Node::add<ast::OpPlus>($1, $3); }
    | add_expr OP_MINUS mult_expr { $$ = Node::add<ast::OpMinus>($1, $3); }
    ;

mult_expr:
    unary_expr
    | mult_expr OP_MULT unary_expr { $$ = Node::add<ast::OpMult>($1, $3); }
    | mult_expr OP_DIVF unary_expr { $$ = Node::add<ast::OpDivF>($1, $3); }
    ;

unary_expr:
    OP_MINUS unary_expr { $$ = Node::add<ast::Signed>(OP_MINUS, $2); }
    | OP_PLUS unary_expr { $$ = Node::add<ast::Signed>(OP_PLUS, $2); }
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
