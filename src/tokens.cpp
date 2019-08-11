#include "tokens.h"

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    // We don't << TokenType because C++ doesn't have enum reflection
    os << to_string(token.type) << ' ' << token.lexeme;
    return os;
}
