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
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto bool_type_entry = st.get_symbol("Boolean");
    if (!bool_type_entry || !bool_type_entry.stmt) {
        return set_error("Type 'Boolean' is not defined");
    }
    set_stmt_type(bool_type_entry.stmt);
    return nullptr;
}


Node::Ptr OpNotEqual::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto bool_type_entry = st.get_symbol("Boolean");
    if (!bool_type_entry || !bool_type_entry.stmt) {
        return set_error("Type 'Boolean' is not defined");
    }
    set_stmt_type(bool_type_entry.stmt);
    return nullptr;
}


Node::Ptr OpLess::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && is_arithmetic_type(left_type)) {
        auto bool_type_entry = st.get_symbol("Boolean");
        if (!bool_type_entry || !bool_type_entry.stmt) {
            return set_error("Type 'Boolean' is not defined");
        }
        set_stmt_type(bool_type_entry.stmt);
        return nullptr;
    } else {
        return set_error(FF("Operator '<' not defined for types '{}' and '{}'",
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}


Node::Ptr OpLessEq::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && is_arithmetic_type(left_type)) {
        auto bool_type_entry = st.get_symbol("Boolean");
        if (!bool_type_entry || !bool_type_entry.stmt) {
            return set_error("Type 'Boolean' is not defined");
        }
        set_stmt_type(bool_type_entry.stmt);
        return nullptr;
    } else {
        return set_error(FF("Operator '<=' not defined for types '{}' and '{}'",
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}

Node::Ptr OpGreater::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && is_arithmetic_type(left_type)) {
        auto bool_type_entry = st.get_symbol("Boolean");
        if (!bool_type_entry || !bool_type_entry.stmt) {
            return set_error("Type 'Boolean' is not defined");
        }
        set_stmt_type(bool_type_entry.stmt);
        return nullptr;
    } else {
        return set_error(FF("Operator '>' not defined for types '{}' and '{}'",
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}

Node::Ptr OpGreaterEq::compute_stmt_type(SymbolTable &st) {
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();

    if (left_type == right_type && is_arithmetic_type(left_type)) {
        auto bool_type_entry = st.get_symbol("Boolean");
        if (!bool_type_entry || !bool_type_entry.stmt) {
            return set_error("Type 'Boolean' is not defined");
        }
        set_stmt_type(bool_type_entry.stmt);
        return nullptr;
    } else {
        return set_error(FF("Operator '>=' not defined for types '{}' and '{}'",
                            strip_type(left_type->as_string()), strip_type(right_type->as_string())));
    }
}

Node::Ptr OpDot::compute_stmt_type(SymbolTable &st) {
    std::cout << "opdota girdik"<< std::endl;
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    

    auto left_type = get_left()->get_stmt_type();
    
    std::cout << "left aldık"<< std::endl;
    auto class_node = std::dynamic_pointer_cast<const Class>(get_left());
    auto module_node = std::dynamic_pointer_cast<const Module>(get_left());
    std::cout << "leftin classını oluşturduk"<< std::endl;
    if (!class_node || !module_node) {
        return set_error(FF("Type '{}' is not a class or a module", strip_type(left_type->as_string())));
    }
    
    
    auto class_symtab = (!class_node) ? module_node->get_symtab() : class_node->get_symtab();
    std::cout << "class symtab aldık"<< std::endl;
    if (!class_symtab) {
        return set_error(FF("Class '{}' has no symbol table", left_type->as_string()));
    }

    auto member_name_node = get_right();
    auto member_name = static_cast<const Identifier &>(*member_name_node).get_name();
    auto member_entry = class_symtab->get_symbol(member_name);
    auto left_name = static_cast<const Identifier &>(*get_left()).get_name();
    if (!member_entry || !member_entry.stmt) {
        return set_error(FF("Identifier '{}.{}' is not found",left_name , member_name));
    }

    set_stmt_type(member_entry.stmt->get_stmt_type());
    return nullptr;
}

} // namespace ast
