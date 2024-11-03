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

class NodeList : public Node {
public:
    NodeList() : Node(), m_statements{} {}

    NodeList(const std::vector<Node::Ptr>& statements)
        : Node(), m_statements(statements) {}

    std::string as_string() const override {
        if (m_statements.size() == 1) {
            return m_statements[0]->as_string();
        }

        std::string result = "NodeList(";
        for (const auto& stmt : m_statements) {
            result += stmt->as_string() + ", ";
        }
        if (!m_statements.empty()) {
            result.erase(result.size() - 2); 
        }
        if (m_statements.empty()){
            return "";
        }
        result += ")";
        return result;
    }

    void add_statement(Node::Ptr statement) {
        m_statements.push_back(statement);
    }
    private:
    std::vector<Node::Ptr> m_statements;
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
class Import : public Node {
public:
    Import(const Node::Ptr &name) : Node(KW_IMPORT), m_name(name) {}

    std::string as_string() const override {
        return fmt::format("Import({})", m_name->as_string());
    }

private:
    Node::Ptr m_name;
};

class FuncArg : public Node {
public:
    FuncArg(const Node::Ptr &name, const Node::Ptr &type)
        : Node(IDENTIFIER), m_name(name), m_type(type) {}

    std::string as_string() const override {
        return fmt::format("FArg(n={}, t={})", m_name->as_string(), m_type->as_string());
    }

private:
    Node::Ptr m_name;
    Node::Ptr m_type;  
};

class FuncArgs : public Node {
public:
    FuncArgs() : Node(), m_arguments{} {}

    FuncArgs(const std::vector<Node::Ptr>& statements)
        : Node(), m_arguments(statements) {}

    std::string as_string() const override {
        if (m_arguments.empty()){
            return "[]";
        }
        std::string result = "FuncArgs([";
        if (m_arguments.size() == 1) {
            result +=  m_arguments[0]->as_string();
            result += "])";
            return result;
        }

        
        for (const auto& stmt : m_arguments) {
            result += stmt->as_string() + ", ";
        }
        if (!m_arguments.empty()) {
            result.erase(result.size() - 2); 
        }
        
        result += "])";
        return result;
    }

    void add_statement(Node::Ptr statement) {
        m_arguments.push_back(statement);
    }

private:
    std::vector<Node::Ptr> m_arguments;
};

class Func : public Node {
public:
    Func(const Node::Ptr &name, const Node::Ptr &args, const Node::Ptr &ret_type, const Node::Ptr &body)
        : Node(KW_FUNC), m_name(name), m_args(args), m_return_type(ret_type), m_body(body) {}

    std::string as_string() const override {
        std::string return_type_str = m_return_type ? m_return_type->as_string() : "None";
        std::string body_str = m_body ? m_body->as_string() : "[]";
        return fmt::format("Func(n={}, a={}, r={}, s=[{}])", 
                           m_name->as_string(), 
                           m_args->as_string(), 
                           return_type_str, 
                           body_str);
    }

private:
    Node::Ptr m_name;        
    Node::Ptr m_args;        
    Node::Ptr m_return_type; 
    Node::Ptr m_body;      
};
}

#endif
