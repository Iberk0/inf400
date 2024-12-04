#include "Literal.h"
#include <cassert>
#include <kiraz/token/Literal.h>
#include <kiraz/Compiler.h>
#include <iostream>
#include "Operator.h"


namespace ast {

Integer::Integer(Token::Ptr t) : Node(L_INTEGER){
        assert(t->get_id() == L_INTEGER);
        auto token_int = std::static_pointer_cast<const token::Integer>(t);
        auto base = token_int->get_base();
        try
        {
            m_value = std::stoll(token_int->get_value(), nullptr, base);
        }
        catch(std::out_of_range &e)
        {
            
        }

    }

Node::Ptr Integer::compute_stmt_type(SymbolTable &st) {
    auto int_type_entry = st.get_symbol("Integer64");
    if (!int_type_entry) {
        return set_error("Type 'Integer64' is not defined");
    }
    set_stmt_type(int_type_entry.stmt);
    return nullptr;
}

Node::Ptr Signed::compute_stmt_type(SymbolTable &st) {
    if (auto ret = m_operand->compute_stmt_type(st)) {
        return ret;
    }
    set_stmt_type(m_operand->get_stmt_type());
    return nullptr;
}

StringLiteral::StringLiteral(Token::Ptr t) : Node(L_STRING){
    assert(t->get_id() == L_STRING);
    auto token_str = std::static_pointer_cast<const token::StringLiteral>(t);
    m_value = token_str->get_value();
   

}

Node::Ptr StringLiteral::compute_stmt_type(SymbolTable &st) {
    auto str_type_entry = st.get_symbol("String");
    if (!str_type_entry) {
        return set_error("Type 'String' is not defined");
    }
    set_stmt_type(str_type_entry.stmt);
    return nullptr;
}

Identifier::Identifier(Token::Ptr t) : Node(IDENTIFIER) {
    assert(t->get_id() == IDENTIFIER);
    auto token_Identifier = std::static_pointer_cast<const token::Identifier>(t);
    m_name = token_Identifier->get_name();
}


Node::Ptr Identifier::compute_stmt_type(SymbolTable &st) {
    auto ste = st.get_symbol(m_name);
    std::cout << "/* message */" << std::endl;
    if (!ste || !ste.stmt) {
        return set_error(FF("Identifier '{}' is not found", m_name));
    }
    
    auto statement = ste.stmt;
    if(ste.stmt->get_stmt_type()){
        set_stmt_type(ste.stmt->get_stmt_type());
    }
    else{
        set_stmt_type(ste.stmt);
    }
    
    std::cout << "Identifier'dan çıktık. Identifier'ı ekledik" << std::endl;
    return nullptr;
}




Node::Ptr Let::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr FuncArg::compute_stmt_type(SymbolTable &st) {

    return nullptr;
}

Node::Ptr FuncArgs::compute_stmt_type(SymbolTable &st) {

    return nullptr;
}

Node::Ptr Func::add_to_symtab_forward(SymbolTable &st) {
    auto func_name = static_cast<const Identifier &>(*m_name).get_name();

    if (st.get_symbol(func_name)) {
        return set_error(FF("Identifier '{}' is already in symtab", func_name));
    }

    st.add_symbol(func_name, shared_from_this());
    return nullptr;
}

Node::Ptr Func::compute_stmt_type(SymbolTable &st) {
    if (auto ret = Node::compute_stmt_type(st)) {
        return ret;
    }
    std::cout << "func girdik"<< std::endl;
    if (st.get_scope_type() != ScopeType::Module && st.get_scope_type() != ScopeType::Class) {
        return set_error("Misplaced function definition");
    }
    std::cout << "func scope kontrol ettik"<< std::endl;
    auto return_type_name = static_cast<const Identifier &>(*m_return_type).get_name();
    std::cout << "return type name aldık"<< std::endl;
    auto ste = st.get_symbol(return_type_name);
    std::cout << m_return_type->as_string()<< std::endl;
    if (m_return_type) {
        if (!ste || !ste.stmt) {
            return set_error(FF("Return type '{}' of function '{}' is not found", strip_type(return_type_name), get_name_str()));
        }
    }else {
        m_return_type = ste.stmt;
    }
    std::cout << "func rettype bitti"<< std::endl;
    ScopeType scope_type;
    if (st.get_scope_type() == ScopeType::Class) {
        scope_type = ScopeType::Method;
    } else {
        scope_type = ScopeType::Func;
    }
    std::cout << "func scope type aldık"<< std::endl;

    auto scope = st.enter_scope(scope_type, shared_from_this());
    std::cout << "func scope girdik"<< std::endl;
    if (m_args && m_args->is_funcarg_list()) {
        std::cout << "func arg girdik"<< std::endl;
        auto args = static_cast<const FuncArgs &>(*m_args).get_arguments();
        std::set<std::string> arg_names;
        
        for (const auto &arg : args) {
            std::cout << "argları dönüyz"<< std::endl;
            auto arg_name_node = static_cast<const FuncArg &>(*arg).get_name();
            auto arg_name = static_cast<const Identifier &>(*arg_name_node).get_name();
            std::cout << "arg name aldık"<< std::endl;
            std::cout << arg_name<< std::endl;
            if (arg_names.count(arg_name)) {
                return set_error(FF("Identifier '{}' in argument list of function '{}' is already in symtab", arg_name, get_name_str()));
            }
            arg_names.insert(arg_name);

            if (st.get_symbol(arg_name)) {
                return set_error(FF("Identifier '{}' in argument list of function '{}' is already in symtab", arg_name, get_name_str()));
            }
            std::cout << "arg name sembol baktık"<< std::endl;
            st.add_symbol(arg_name, arg);
            std::cout << "argname sembol ekledik"<< std::endl;
            auto arg_type_node = static_cast<const FuncArg &>(*arg).get_type();
            auto arg_type_name = static_cast<const Identifier &>(*arg_type_node).get_name();
            auto ste = st.get_symbol(arg_type_name);
            if (!ste) {
                return set_error(FF("Identifier '{}' in type of argument '{}' in function '{}' is not found", arg_type_name, arg_name, get_name_str()));
            }

            static_cast<FuncArg &>(*arg).set_stmt_type(ste.stmt);
        }
    }


    if (m_body) {
    std::cout << "func body girdik"<< std::endl;
    std::cout << m_body->as_string()<< std::endl;
        for(const auto &stmt : static_cast<const NodeList &>(*m_body).get_statements()){
            std::cout << stmt->as_string() << std::endl;
            if (auto ret = stmt->compute_stmt_type(st)) {
                return ret;
            }
        }
        
    }
    std::cout << "func çıktık"<< std::endl;
    return nullptr;
}
Node::Ptr Class::add_to_symtab_forward(SymbolTable &st) {
    auto class_name = static_cast<const Identifier &>(*m_name).get_name();

    if (st.get_symbol(class_name)) {
        return set_error(FF("Identifier '{}' is already in symtab", class_name));
    }

    if (class_name[0] >= 'a' && class_name[0] <= 'z') {
        return set_error(FF("Class name '{}' can not start with an lowercase letter", class_name));
    }

    st.add_symbol(class_name, shared_from_this());
    return nullptr;
}

Node::Ptr Class::compute_stmt_type(SymbolTable &st) {
    std::cout << "class'a girdiK" << std::endl;
    if (auto ret = Node::compute_stmt_type(st)) {
        std::cout << "class'a girdik ret döncek" << std::endl;
        return ret;
    }
    
    if (!st.add_symbol(get_name_str(), shared_from_this())) {
        return set_error(FF("Identifier '{}' is already in symtab", get_name_str()));
    }
    std::cout << "add sembol yaptık" << std::endl;
    if (st.get_scope_type() != ScopeType::Module) {
        return set_error("Misplaced class statement");
    }
    std::cout << "scope kontrolü yapıldı" << std::endl;
    if (!m_symtab) {
        m_symtab = std::make_unique<SymbolTable>(ScopeType::Class);
    }
    
    if (m_base_class) {
        auto base_class_name = static_cast<const Identifier &>(*m_base_class).get_name();
        auto base_class_entry = st.get_symbol(base_class_name);
        if (!base_class_entry || !base_class_entry.stmt->is_class()) {
            return set_error(FF("Type '{}' is not found", base_class_name));
        }

        m_base_class = base_class_entry.stmt;

        auto base_class_symtab = base_class_entry.stmt->get_cur_symtab();
        if (base_class_symtab) {
            for (const auto &symbol : base_class_symtab->symbols) {
                m_symtab->add_symbol(symbol.first, symbol.second);
            }
        }
    }

    if (m_body) {
        std::cout << "class body girdiK" << std::endl;
        auto scope = st.enter_scope(ScopeType::Class, shared_from_this());
        std::cout << "scope açtık" << std::endl;
        for (const auto &stmt : static_cast<const ClassBody &>(*m_body).get_members()) {
            std::cout << "stmt dönüyoz" << std::endl;
            std::cout << stmt->as_string()<< std::endl;
            if (auto ret = stmt->add_to_symtab_forward(st)) {
                return ret;
            }
            if (auto ret = stmt->add_to_symtab_forward(*m_symtab)) {
                return ret;
            }
            if (auto ret = stmt->compute_stmt_type(st)) {
                return ret;
            }
        }
        
    }
    std::cout << "classtan çıkıyoz"<< std::endl;
    return nullptr;
}

Node::Ptr ClassBody::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Node::Ptr Return::compute_stmt_type(SymbolTable &st) {
    if(auto ret = Node::compute_stmt_type(st)){
            return ret;
        }
    auto scope = st.get_scope_type();
    if(scope == ScopeType::Module || scope == ScopeType::Class){
        return set_error("Misplaced return statement");
    }
    return nullptr;
}

Node::Ptr While::compute_stmt_type(SymbolTable &st) {
    if(auto ret = Node::compute_stmt_type(st)){
            return ret;
        }
    auto scope = st.get_scope_type();
    if(scope == ScopeType::Module || scope == ScopeType::Class){
        return set_error("Misplaced while statement");
    }
    return nullptr;
}

Node::Ptr If::compute_stmt_type(SymbolTable &st) {
    if(auto ret = Node::compute_stmt_type(st)){
            return ret;
        }
    auto scope = st.get_scope_type();
    if(scope == ScopeType::Module || scope == ScopeType::Class){
        return set_error("Misplaced if statement");
    }
    return nullptr;
}

Node::Ptr Call::compute_stmt_type(SymbolTable &st) {
    
    return nullptr;
}

Node::Ptr Module::add_to_symtab_forward(SymbolTable &st) {
    
    return nullptr;
}

Node::Ptr ast::Module::compute_stmt_type(SymbolTable &st) {
    if(auto ret = Node::compute_stmt_type(st)){
        return ret;
    }
    if(!m_symtab){
        m_symtab = std::make_unique<SymbolTable>(ScopeType::Module);
        
    }
    auto parent_scope = st.get_cur_symtab();
    if (parent_scope) {
        for (auto it = parent_scope->symbols.begin(); it != parent_scope->symbols.end(); ++it) {
            const auto &symbol_name = it->first;
            const auto &symbol_node = it->second;
            m_symtab->add_symbol(symbol_name, symbol_node);
        }
    }
    if(m_body){
        auto scope = st.enter_scope(ScopeType::Module, shared_from_this());
        for(const auto &stmt : static_cast<const NodeList &>(*m_body).get_statements()){
            if(auto ret = stmt->add_to_symtab_forward(st)){
                return ret;
            }

            if(auto ret = stmt->add_to_symtab_forward(*m_symtab)){
                return ret;
            }

        }
        for(const auto &stmt : static_cast<const NodeList &>(*m_body).get_statements()){
            if(auto ret = stmt->add_to_symtab_ordered(st)){
                return ret;
            }

            if(auto ret = stmt->add_to_symtab_ordered(*m_symtab)){
                return ret;
            }
            if (auto ret = stmt->compute_stmt_type(st)) {
                return ret;
            }
            
        }
    } 
    set_stmt_type(st.get_symbol("Module"));
    return nullptr;  
}

Node::Ptr Import::compute_stmt_type(SymbolTable &st) {

    return nullptr;
}

}

