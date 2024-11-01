#ifndef KIRAZ_AST_LITERAL_H
#define KIRAZ_AST_LITERAL_H

#include <kiraz/Node.h>

namespace ast {
class Integer : public Node {
public:
// TODO
};

class Identifier : public Node {
public:
    Identifier(Token::Ptr);
    
    std::string as_string() const override {return fmt::format("Id({})",m_name);}

private:
    std::string m_name;
};

class SignedNode : public Node {
public:
// TODO

};
}

#endif
