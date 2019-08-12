#include "tokens.h"

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    // We don't << TokenType because C++ doesn't have enum reflection
    os << to_string(token.type) << ' ' << token.lexeme;
    std::visit([&os](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (!std::is_same_v<T, std::monostate>)
        {
            os << ' ' << arg;
        }
    }, token.literal);
    return os;
}
