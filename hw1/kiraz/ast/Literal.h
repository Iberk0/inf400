#ifndef KIRAZ_AST_LITERAL_H
#define KIRAZ_AST_LITERAL_H

#include <kiraz/Node.h>

namespace ast {
class Module : public Node{
public:
    Module(const Node::Ptr& t) : Node(0), m_body(t) {}
    std::string as_string() const override {return fmt::format("Module([{}])",m_body->as_string());}
private: 
    Node::Ptr m_body;
};

class Let : public Node {
public:
    Let(const Node::Ptr& name, const Node::Ptr& type, const Node::Ptr& init)
        : Node(KW_LET), m_name(name), m_type(type), m_init(init) {}

    std::string as_string() const override {
        std::vector<std::string> components;

        if (m_name) {
            components.push_back(fmt::format("n={}", m_name->as_string()));
        }
        if (m_type) {
            components.push_back(fmt::format("t={}", m_type->as_string()));
        }
        if (m_init) {
            components.push_back(fmt::format("i={}", m_init->as_string()));
        }

        return fmt::format("Let({})", fmt::join(components, ", "));
    }

private:
    Node::Ptr m_name;
    Node::Ptr m_type;
    Node::Ptr m_init;
};

class Integer : public Node {
public:
    Integer(Token::Ptr);
    
    std::string as_string() const override {return fmt::format("Int({})",m_value); }
    
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

class StringLiteral : public Node {
public:
    StringLiteral(Token::Ptr);
    
    std::string as_string() const override { 
        std::string str;
        std::string res;
        if (m_value.length() > 1 && m_value.front() == '\"' && m_value.back() == '\"') {
        str = m_value.substr(1, m_value.length() - 2);
        }
        for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '\\' && i + 1 < str.size()) {
            switch (str[i + 1]) {
                case 'n': res += '\n'; ++i; break;
                default: res += str[i];
            }
        } else {
            res += str[i];
        }
        }
        
        return fmt::format("Str({})", res); 
    }
private:
    std::string m_value;
};

}

#endif
