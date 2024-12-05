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
    std::cout << "Opassign'a girdik" << std::endl;
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }
    if (auto ret = get_right()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_type = get_left()->get_stmt_type();
    auto right_type = get_right()->get_stmt_type();
    if(left_type && right_type){
        std::cout << "left ve right'ı aldık" << std::endl;
    }
    std::cout << "left ve right'ı aldık" << std::endl;
    std::cout << right_type->as_string() << std::endl;
    std::cout << left_type->as_string() << std::endl;
    if(left_type->is_func() && right_type->is_func()){
        return set_error(FF("Overriding builtin '{}' is not allowed",
                            extract_id(left_type->as_string())));
    }
    if (left_type != right_type) {
        return set_error(FF("Left type '{}' of assignment does not match the right type '{}'",
                            extract_id(left_type->as_string()), extract_id(right_type->as_string())));
    }
    std::cout << "Left type için tip atamadayız" << std::endl;
    std::cout << left_type->as_string() << std::endl;
    set_stmt_type(left_type);
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
    if (auto ret = get_left()->compute_stmt_type(st)) {
        return ret;
    }

    auto left_name = strip_type(get_left()->as_string());
    std::cout << left_name << std::endl;

    auto left_symbol = st.get_symbol(left_name);
    if (!left_symbol.stmt) {
        return set_error(FF("Identifier '{}' is not found", left_name));
    }
    std::cout << left_symbol.stmt->as_string() << std::endl;
    auto left_node = left_symbol.stmt;
    auto left_type = left_node->get_stmt_type();
    std::cout << left_type->as_string() << std::endl;

    SymbolTable *member_symtab = nullptr;
    if (left_type->as_string() == "Id(Class)") {
        auto class_node = std::dynamic_pointer_cast<ast::Class>(std::const_pointer_cast<Node>(left_node));
        if (!class_node) {
            return set_error("Failed to cast to Class");
        }
        member_symtab = class_node->get_symtab();
    } else if (left_type->as_string() == "Id(Module)") {
        auto module_node = std::dynamic_pointer_cast<ast::Module>(std::const_pointer_cast<Node>(left_node));
        if (!module_node) {
            return set_error("Failed to cast to Module");
        }
        
        member_symtab = module_node->get_symtab();
    }
    
    if (!member_symtab) {
        return set_error(FF("Type '{}' has no symbol table", strip_type(left_type->as_string())));
    }

    auto member_name_node = get_right();
    auto member_name = static_cast<const Identifier &>(*member_name_node).get_name();
    std::cout << "buna giriyo mu?" << std::endl;
    auto member_entry = member_symtab->get_symbol(member_name);
    std::cout << "buna giriyo mu?2" << std::endl;

    if (!member_entry.stmt) {
        return set_error(FF("Identifier '{}.{}' is not found", left_name, member_name));
    }
    std::cout << "buna giriyo mu?3" << std::endl;
    auto non_const_member_stmt = std::const_pointer_cast<Node>(member_entry.stmt);
    std::cout << "buna giriyo mu?4" << std::endl;
    std::cout << non_const_member_stmt->as_string() << std::endl;
    if (auto ret = non_const_member_stmt->compute_stmt_type(st)) {
        return ret;
    }
    std::cout << "aaaaaaa" << std::endl;
    set_stmt_type(member_entry.stmt);
    return nullptr;
}

} // namespace ast
