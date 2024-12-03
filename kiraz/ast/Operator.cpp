
#include "Operator.h"


#include "Operator.h"
#include <cassert>
#include <kiraz/Compiler.h>
#include "Literal.h"
#include <iostream>
#include <regex>
namespace ast {




Node::Ptr OpPlus::compute_stmt_type(SymbolTable &st) {
   return nullptr;
}



Node::Ptr OpMinus::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}


Node::Ptr OpMult::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr OpDivF::compute_stmt_type(SymbolTable &st) {
    return nullptr;
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
