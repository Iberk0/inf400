#include "Operator.h"
#include <cassert>
#include <kiraz/Compiler.h>
#include "Literal.h"
#include <iostream>
#include <regex>
namespace ast {

bool is_arithmetic_type(const Node::Cptr &type) {
    auto type_name = strip_type(type->as_string());
    return (type_name == "Integer64");
}


Node::Ptr OpPlus::compute_stmt_type(SymbolTable &st) {
   if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && (strip_type(left_type->as_string()) == "Integer64" || strip_type(left_type->as_string()) == "String")) {
        set_stmt_type(left_type);
        return nullptr;
    } else {
        return set_error(FF("Operator '+' not defined for types '{}' and '{}'", 
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}



Node::Ptr OpMinus::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && is_arithmetic_type(left_type)) {
        set_stmt_type(left_type);
        return nullptr;
    } else {
        return set_error(FF("Operator '-' not defined for types '{}' and '{}'",
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}


Node::Ptr OpMult::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && is_arithmetic_type(left_type)) {
        set_stmt_type(left_type);
        return nullptr;
    } else {
        return set_error(FF("Operator '*' not defined for types '{}' and '{}'",
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}

Node::Ptr OpDivF::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && is_arithmetic_type(left_type)) {
        set_stmt_type(left_type);
        return nullptr;
    } else {
        return set_error(FF("Operator '/' not defined for types '{}' and '{}'",
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}

Node::Ptr OpAssign::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}


Node::Ptr OpEqual::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr OpNotEqual::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr OpLess::compute_stmt_type(SymbolTable &st) {
   return nullptr;
}

Node::Ptr OpLessEq::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr OpGreater::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr OpGreaterEq::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr OpDot::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

} // namespace ast
