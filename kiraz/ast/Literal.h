#ifndef KIRAZ_AST_LITERAL_H
#define KIRAZ_AST_LITERAL_H

#include <kiraz/Node.h>
#include <kiraz/Compiler.h>
#include <vector>
#include <set>
#include <memory>
#include <regex>


namespace ast {

inline std::string extract_id(const std::string& input) {
    size_t start_pos = input.find("Id(");
    if (start_pos == std::string::npos) {
        return "";  
    }
    start_pos += 3;  
    size_t end_pos = input.find(')', start_pos);
    if (end_pos == std::string::npos) {
        return "";  
    }
    return input.substr(start_pos, end_pos - start_pos);
}

inline std::string strip_type(const std::string& as_string_output) {
    
    std::regex re("\\(([^)]+)\\)"); 
    std::smatch match;
    
    if (std::regex_search(as_string_output, match, re)) {
        return match[1]; 
    }
    return as_string_output;
}

class Module : public Node {
public:
    Module(const Node::Ptr& t) : Node(0), m_body(t) {}
    std::string as_string() const override { return fmt::format("Module({})", m_body->as_string()); }


    Node::Ptr get_body() const { return m_body; }
    SymbolTable* get_symtab() const { return m_symtab.get(); }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
    Node::Ptr add_to_symtab_forward(SymbolTable &st) override;

private:
    Node::Ptr m_body;
    std::unique_ptr<SymbolTable> m_symtab;
};

class NodeList : public Node {
public:
    NodeList() : Node(), m_statements{} {}

    NodeList(const std::vector<Node::Ptr>& statements)
        : Node(), m_statements(statements) {}

    std::string as_string() const override {
        if (m_statements.empty()) {
            return "[]";
        }
        std::string result = "[";
        if (m_statements.size() == 1) {
            result += m_statements[0]->as_string();
            result += "]";
            return result;
        }

        for (const auto& stmt : m_statements) {
            result += stmt->as_string() + ", ";
        }
        if (!m_statements.empty()) {
            result.erase(result.size() - 2);
        }

        result += "]";
        return result;
    }

    void add_statement(Node::Ptr statement) {
        m_statements.push_back(statement);
    }

    
    const std::vector<Node::Ptr>& get_statements() const { return m_statements; }
    bool is_stmt_list() const override { return true; }

private:
    std::vector<Node::Ptr> m_statements;
};

class Integer : public Node {
public:
    Integer(Token::Ptr);

    std::string as_string() const override { return fmt::format("Int({})", m_value); }

    
    int64_t get_value() const { return m_value; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    int64_t m_value;
};

class Signed : public Node {
public:
    Signed(int op, Node::Ptr operand) : Node(L_INTEGER), m_operator(op), m_operand(operand) {}
    std::string as_string() const override {
        std::string sign = (m_operator == OP_PLUS) ? "OP_PLUS" : "OP_MINUS";
        return fmt::format("Signed({}, {})", sign, m_operand->as_string());
    }

    
    int get_operator() const { return m_operator; }
    Node::Ptr get_operand() const { return m_operand; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    int m_operator;
    Node::Ptr m_operand;
};

class Identifier : public Node {
public:
    Identifier(Token::Ptr);
    Identifier(const std::string& name) : Node(IDENTIFIER), m_name(name) {}
    std::string as_string() const override { return fmt::format("Id({})", m_name); }

    
    const std::string& get_name() const { return m_name; }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;

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

   
    const std::string& get_value() const { return m_value; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    std::string m_value;
};

class Let : public Node {
public:
    Let(const Node::Ptr& name, const Node::Cptr& type, const Node::Ptr& init)
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

    
    Node::Ptr get_name() const { return m_name; }
    Node::Cptr get_type() const { return m_type; }
    Node::Ptr get_init() const { return m_init; }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr m_name;
    Node::Cptr m_type;
    Node::Ptr m_init;
};

class Import : public Node {
public:
    Import(const Node::Ptr &name) : Node(KW_IMPORT), m_name(name) {}

    std::string as_string() const override {
        return fmt::format("Import({})", m_name->as_string());
    }

    
    Node::Ptr get_name() const { return m_name; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr m_name;
};

class FuncArg : public Node {
public:
    FuncArg(const Node::Ptr &name, const Node::Cptr &type)
        : Node(IDENTIFIER), m_name(name), m_type(type) {}

    std::string as_string() const override {
        return fmt::format("FArg(n={}, t={})", m_name->as_string(), m_type->as_string());
    }

    
    Node::Ptr get_name() const { return m_name; }
    Node::Cptr get_type() const { return m_type; }

    
    void set_stmt_type(const Node::Cptr &type) { Node::set_stmt_type(type); }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr m_name;
    Node::Cptr m_type;
};

class FuncArgs : public Node {
public:
    FuncArgs() : Node(), m_arguments{} {}

    FuncArgs(const std::vector<Node::Ptr>& statements)
        : Node(), m_arguments(statements) {}

    std::string as_string() const override {
        if (m_arguments.empty()) {
            return "[]";
        }
        std::string result = "FuncArgs([";
        if (m_arguments.size() == 1) {
            result += m_arguments[0]->as_string();
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
    bool is_funcarg_list() const override { return true; }
    void add_statement(Node::Ptr statement) {
        m_arguments.push_back(statement);
    }

    
    const std::vector<Node::Ptr>& get_arguments() const { return m_arguments; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    std::vector<Node::Ptr> m_arguments;
};

class Func : public Node {
public:
    Func(const Node::Ptr &name, const Node::Ptr &args, const Node::Cptr &ret_type, const Node::Ptr &body)
        : Node(KW_FUNC), m_name(name), m_args(args), m_return_type(ret_type), m_body(body) {}
    
    
    std::string as_string() const override {
        std::string return_type_str = m_return_type ? m_return_type->as_string() : "None";
        std::string m_body_str = m_body ? m_body->as_string() : "";
        return fmt::format("Func(n={}, a={}, r={}, s={})",
                           m_name->as_string(),
                           m_args->as_string(),
                           return_type_str,
                           m_body_str);
    }
    bool is_func() const override { return true; }

    
    Node::Ptr get_name() const { return m_name; }
    Node::Ptr get_args() const { return m_args; }
    Node::Cptr get_return_type() const { return m_return_type; }
    Node::Ptr get_body() const { return m_body; }
    const std::string &get_name_str() const { return static_cast<const Identifier &>(*m_name).get_name(); }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;
    Node::Ptr add_to_symtab_forward(SymbolTable &st) override;

private:
    Node::Ptr m_name;
    Node::Ptr m_args;
    Node::Cptr m_return_type;
    Node::Ptr m_body;
};

class Class : public Node {
public:
    Class(const Node::Ptr &name, const Node::Cptr &base_class, const Node::Ptr &body)
        : Node(KW_CLASS), m_name(name), m_base_class(base_class), m_body(body) {}
    Class(const Node::Ptr &name, const Node::Ptr &body)
        : Node(KW_CLASS), m_name(name), m_base_class(nullptr), m_body(body) {}
    Class(const Node::Ptr &name)
        : Node(KW_CLASS), m_name(name), m_base_class(nullptr), m_body(nullptr) {}

    std::string as_string() const override {
        if(!m_base_class){
        return fmt::format("Class(n={}, s={})",
                           m_name->as_string(),
                           m_body ? m_body->as_string() : "[]");
        }
        else {
            std::string base_class_str = m_base_class ? m_base_class->as_string() : "[]";
            return fmt::format("Class(n={}, s={})",
                           m_name->as_string(),
                           m_body ? m_body->as_string() : "[]");
        }
    }

    std::shared_ptr<Scope> get_cur_symtab() const {
        return m_symtab ? m_symtab->get_cur_symtab() : nullptr;
    }
    
   
    Node::Cptr get_base_class() const { return m_base_class; }
    SymbolTable* get_symtab() const { return m_symtab.get(); }
    
    Node::Ptr get_name() const { return m_name; }
    const std::string &get_name_str() const { return static_cast<const Identifier &>(*m_name).get_name(); }
    Node::Ptr get_body() const { return m_body; }
    bool is_class() const override { return true; }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
    Node::Ptr add_to_symtab_forward(SymbolTable &st) override;

private:
    Node::Ptr m_name;
    Node::Cptr m_base_class;
    Node::Ptr m_body;
    std::unique_ptr<SymbolTable> m_symtab;
};

class ClassBody : public Node {
public:
    ClassBody() : Node(), m_members{} {}

    ClassBody(const std::vector<Node::Ptr>& statements)
        : Node(), m_members(statements) {}

    std::string as_string() const override {
        if (m_members.empty()) {
            return "[]";
        }
        std::string result = "[";
        if (m_members.size() == 1) {
            result += m_members[0]->as_string();
            result += "]";
            return result;
        }

        for (const auto& stmt : m_members) {
            result += stmt->as_string() + ", ";
        }
        if (!m_members.empty()) {
            result.erase(result.size() - 2);
        }

        result += "]";
        return result;
    }

    void add_statement(Node::Ptr statement) {
        m_members.push_back(statement);
    }

    
    const std::vector<Node::Ptr>& get_members() const { return m_members; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    std::vector<Node::Ptr> m_members;
};

class While : public Node {
public:
    While(const Node::Ptr& condition, const Node::Ptr& body)
        : Node(KW_WHILE), m_condition(condition), m_body(body) {}

    std::string as_string() const override {
        return fmt::format("While(?={}, repeat={})", m_condition->as_string(), m_body->as_string());
    }

    
    Node::Ptr get_condition() const { return m_condition; }
    Node::Ptr get_body() const { return m_body; }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr m_condition;
    Node::Ptr m_body;
};

class If : public Node {
public:
    If(const Node::Ptr &condition, const Node::Ptr &then_body, const Node::Ptr &else_body)
        : Node(KW_IF), m_condition(condition), m_then_body(then_body), m_else_body(else_body) {}

    std::string as_string() const override {
        std::string else_str = m_else_body ? m_else_body->as_string() : "[]";
        return fmt::format("If(?={}, then={}, else={})",
                           m_condition->as_string(),
                           m_then_body->as_string(),
                           else_str);
    }

   
    Node::Ptr get_condition() const { return m_condition; }
    Node::Ptr get_then_body() const { return m_then_body; }
    Node::Ptr get_else_body() const { return m_else_body; }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr m_condition;
    Node::Ptr m_then_body;
    Node::Ptr m_else_body;
};

class Call : public Node {
public:
    Call(const Node::Ptr &expr, const Node::Ptr &args)
        : Node(0), m_expr(expr), m_args(args) {}
    Call(const Node::Ptr &expr)
        : Node(0), m_expr(expr), m_args(nullptr) {}

    std::string as_string() const override {
        return fmt::format("Call(n={}, a={})", m_expr->as_string(), m_args ? m_args->as_string() : "[]");
    }


    Node::Ptr get_expr() const { return m_expr; }
    Node::Ptr get_args() const { return m_args; }

    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr m_expr, m_args;
};

class Return : public Node {
public:
    Return(const Node::Ptr &body) : Node(KW_RETURN), m_body(body) {}

    std::string as_string() const override {
        return fmt::format("Return({})", m_body->as_string());
    }


    Node::Ptr get_body() const { return m_body; }
    Node::Ptr compute_stmt_type(SymbolTable &st) override;

private:
    Node::Ptr m_body;
};


} 

#endif // KIRAZ_AST_LITERAL_H

