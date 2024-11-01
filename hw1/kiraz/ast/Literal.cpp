#include "Literal.h"
#include <cassert>
#include <kiraz/token/Literal.h>

namespace ast {

Identifier::Identifier(Token::Ptr t) : Node(IDENTIFIER) {
    assert(t->get_id() == IDENTIFIER);
    auto token_Identifier = std::static_pointer_cast<const token::Identifier>(t);
    m_name = token_Identifier->get_name();  // Set m_name to the name from the Token
}
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
        //BURAYA BİR ŞEYLER EKLENECEK
    }
}
}