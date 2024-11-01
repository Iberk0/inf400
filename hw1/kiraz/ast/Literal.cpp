#include "Literal.h"
#include <cassert>
#include <kiraz/token/Literal.h>

namespace ast {

Identifier::Identifier(Token::Ptr t) : Node(IDENTIFIER) {
    assert(t->get_id() == IDENTIFIER);
    auto token_Identifier = std::static_pointer_cast<const token::Identifier>(t);
    m_name = token_Identifier->get_name();  // Set m_name to the name from the Token
}
}
