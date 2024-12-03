// literal.cpp
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
    return nullptr;
}

Node::Ptr Signed::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

StringLiteral::StringLiteral(Token::Ptr t) : Node(L_STRING){
    assert(t->get_id() == L_STRING);
    auto token_str = std::static_pointer_cast<const token::StringLiteral>(t);
    m_value = token_str->get_value();
   

}

Node::Ptr StringLiteral::compute_stmt_type(SymbolTable &st) {
    return nullptr;
}

Identifier::Identifier(Token::Ptr t) : Node(IDENTIFIER) {
    assert(t->get_id() == IDENTIFIER);
    auto token_Identifier = std::static_pointer_cast<const token::Identifier>(t);
    m_name = token_Identifier->get_name();
}


Node::Ptr Identifier::compute_stmt_type(SymbolTable &st) {
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
   
    return nullptr;
}


Node::Ptr Func::compute_stmt_type(SymbolTable &st) {
    
    return nullptr;
}
Node::Ptr Class::add_to_symtab_forward(SymbolTable &st) {
   
    return nullptr;
}

Node::Ptr Class::compute_stmt_type(SymbolTable &st) {
    if(auto ret = Node::compute_stmt_type(st)){
        return ret;
    }

    if(st.get_scope_type() != ScopeType::Module) {
        return set_error("Misplaced class statement");
    }

    if(auto ste_n = m_name->get_symbol(st)){
        return set_error(FF(""));
    }
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

