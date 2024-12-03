#ifndef KIRAZ_AST_OPERATOR_H
#define KIRAZ_AST_OPERATOR_H
#include <cassert>
#include <kiraz/Node.h>

namespace ast {

class OpBinary : public Node {
protected:
    explicit OpBinary(int op, const Node::Ptr &left, const Node::Ptr &right)
        : Node(op), m_left(left), m_right(right) {
            assert(left);
            assert(right);
        }
public:
    auto get_left() const { return m_left; }
    auto get_right() const { return m_right; }
    
    std::string as_string() const override {
        assert(get_left());
        assert(get_right());
        std::string opstr;
        switch (get_id())
        {
        case OP_PLUS:
            opstr = "Add";
            break;
        case OP_MINUS:
            opstr = "Sub";
            break;
        case OP_DIVF:
            opstr = "DivF";
            break;
        case OP_MULT:
            opstr = "Mult";
            break;
        case OP_ASSIGN:
            opstr = "Assign";
            break;
        case OP_EQUAL:
            opstr = "OpEq";
            break;
        case OP_NOT_EQUAL:
            opstr = "OpNEq";
            break;
        case OP_LESS:
            opstr = "OpLt";
            break;
        case OP_LESSEQ:
            opstr = "OpLe";
            break;
        case OP_GREATER:
            opstr = "OpGt";
            break;
        case OP_GREATEREQ:
            opstr = "OpGe";
            break;
        case OP_DOT:
            opstr = "Dot";
            break;
        default:
            break;
        }
        return fmt::format("{}(l={}, r={})", opstr, get_left()->as_string(), get_right()->as_string());
    }

    Node::Ptr compute_stmt_type(SymbolTable &st) override = 0;

private:
    Node::Ptr m_left, m_right;
};

class OpPlus : public OpBinary {
public:
    OpPlus(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_PLUS, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpMinus : public OpBinary {
public:
    OpMinus(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_MINUS, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpDivF : public OpBinary {
public:
    OpDivF(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_DIVF, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpMult : public OpBinary {
public:
    OpMult(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_MULT, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpAssign : public OpBinary {
public:
    OpAssign(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_ASSIGN, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpEqual : public OpBinary {
public:
    OpEqual(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_EQUAL, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpNotEqual : public OpBinary {
public:
    OpNotEqual(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_NOT_EQUAL, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpLess : public OpBinary {
public:
    OpLess(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_LESS, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpLessEq : public OpBinary {
public:
    OpLessEq(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_LESSEQ, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpGreater : public OpBinary {
public:
    OpGreater(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_GREATER, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpGreaterEq : public OpBinary {
public:
    OpGreaterEq(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_GREATEREQ, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};

class OpDot : public OpBinary {
public:
    OpDot(const Node::Ptr &left, const Node::Ptr &right) : OpBinary(OP_DOT, left, right) {}
    Node::Ptr compute_stmt_type(SymbolTable &st) override;
};
}

#endif // KIRAZ_AST_OPERATOR_H

