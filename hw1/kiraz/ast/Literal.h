#ifndef KIRAZ_AST_LITERAL_H
#define KIRAZ_AST_LITERAL_H

#include <kiraz/Node.h>

namespace ast {
class Integer : public Node {
public:
    Integer(Token::Ptr);
    
    std::string as_string() const override {return fmt::format("Integer({})",m_value); }

private:
    int64_t m_value;
};

class Signed : public Node {
public:
    Signed(int op, Node::Cptr operand) : Node(L_INTEGER), m_operator(op), m_operand(operand) {}
    std::string as_string() const override {
        std::string sign = (m_operator == 260) ? "OP_PLUS" : "OP_MINUS";
        return fmt::format("Signed({}, {})", sign, m_operand->as_string());
    }
private:
    int m_operator;
    Node::Cptr m_operand;
};
class Identifier : public Node {
public:
    Identifier(Token::Ptr);
    
    std::string as_string() const override {return fmt::format("Id({})",m_name);}

private:
    std::string m_name;
};

}

#endif
