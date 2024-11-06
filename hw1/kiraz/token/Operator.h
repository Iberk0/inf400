#ifndef KIRAZ_TOKEN_OPERATOR_H
#define KIRAZ_TOKEN_OPERATOR_H

#include <kiraz/Token.h>

namespace token {
class Operator : public Token {
public:
    Operator(int type) : Token(type) {}
    
};

class OpPlus : public Operator {
public:
    OpPlus() : Operator(OP_PLUS) {}
    std::string as_string() const override { return "OP_PLUS"; }
};

class OpMinus : public Operator {
public:
    OpMinus() : Operator(OP_MINUS) {}
    std::string as_string() const override { return "OP_MINUS"; }
};

class OpMult : public Operator {
public:
    OpMult() : Operator(OP_MULT) {}
    std::string as_string() const override { return "OP_MULT"; }
};

class OpDivF : public Operator {
public:
    OpDivF() : Operator(OP_DIVF) {}
    std::string as_string() const override { return "OP_DIVF"; }
};

class OpAssign : public Operator {
public:
    OpAssign() : Operator(OP_ASSIGN) {}
    std::string as_string() const override { return "OP_ASSIGN"; }
};

class OpLparen : public Operator {
public:
    OpLparen() : Operator(OP_LPAREN) {}
    std::string as_string() const override { return "OP_LPAREN"; }
};

class OpRparen : public Operator {
public:
    OpRparen() : Operator(OP_RPAREN) {}
    std::string as_string() const override { return "OP_RPAREN"; }
};

class OpLbrace : public Operator {
public:
    OpLbrace() : Operator(OP_LBRACE) {}
    std::string as_string() const override { return "OP_LBRACE"; }
};

class OpRbrace : public Operator {
public:
    OpRbrace() : Operator(OP_RBRACE) {}
    std::string as_string() const override { return "OP_RBRACE"; }
};

class OpScolon : public Operator {
public:
    OpScolon() : Operator(OP_SCOLON) {}
    std::string as_string() const override { return "OP_SCOLON"; }
};

class OpColon : public Operator {
public:
    OpColon() : Operator(OP_COLON) {}
    std::string as_string() const override { return "OP_COLON"; }
};

class OpComma : public Operator {

public:

    OpComma() : Operator(OP_COMMA) {}

    std::string as_string() const override { return "OP_COMMA"; }

};

class OpLess : public Operator {

public:

    OpLess() : Operator(OP_LESS) {}

    std::string as_string() const override { return "OP_LESS"; }

};

class OpLessEq : public Operator {

public:

    OpLessEq() : Operator(OP_LESSEQ) {}

    std::string as_string() const override { return "OP_LESSEQ"; }

};

class OpGreater : public Operator {

public:

    OpGreater() : Operator(OP_GREATER) {}

    std::string as_string() const override { return "OP_GREATER"; }

};

class OpGreaterEq : public Operator {

public:

    OpGreaterEq() : Operator(OP_GREATEREQ) {}

    std::string as_string() const override { return "OP_GREATEREQ"; }

};

class OpEqual : public Operator {

public:

    OpEqual() : Operator(OP_EQUAL) {}

    std::string as_string() const override { return "OP_EQUAL"; }

};

class OpNotEqual : public Operator {

public:

    OpNotEqual() : Operator(OP_NOT_EQUAL) {}

    std::string as_string() const override { return "OP_NOT_EQUAL"; }

};

class OpDot : public Operator {
public:
    OpDot() : Operator(OP_DOT) {}

    std::string as_string() const override {return "OP_DOT";}
};

}

#endif
