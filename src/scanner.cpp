#include "scanner.h"
#include <algorithm>
#include "interpreter.h"

const std::string Scanner::str_unexpected = "Unexpected character: ";

std::vector<Token>& Scanner::scan_tokens()
{
    while (m_current != m_source.cend())
    {
        m_start = m_current;
        scan_token();
    }
    m_tokens.emplace_back(Token{TokenType::EOFILE, "", std::monostate{}, m_line});
    return m_tokens;
}

void Scanner::scan_token()
{
    const auto c = *m_current;
    std::advance(m_current, 1);
    switch (c)
    {
        case '(': add_token(TokenType::LEFT_PAREN); break;
        case ')': add_token(TokenType::RIGHT_PAREN); break;
        case '{': add_token(TokenType::LEFT_BRACE); break;
        case '}': add_token(TokenType::RIGHT_BRACE); break;
        case ',': add_token(TokenType::COMMA); break;
        case '.': add_token(TokenType::DOT); break;
        case '-': add_token(TokenType::MINUS); break;
        case '+': add_token(TokenType::PLUS); break;
        case ';': add_token(TokenType::SEMICOLON); break;
        case '*': add_token(TokenType::STAR); break;
        case '!': add_token(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
        case '=': add_token(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
        case '<': add_token(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS); break;
        case '>': add_token(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;
        case '/':
            if (match('/'))
            {
                // We'll do this the nice C++ way.
                m_current = std::find(m_current, m_source.cend(), '\n');
            }
            else
            {
                add_token(TokenType::SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t': break;
        case '\n': m_line++; break;
        case '"': consume_string(); break;
        default: Interpreter::error(m_line, str_unexpected + c); break;
    }
}

void Scanner::consume_string()
{
    // Consume until we hit the next string token
    m_current = std::find(m_current, m_source.cend(), '"');
    // This may skip \n tokens - find_if might fix this

    // Unterminated string.
    if (m_current == m_source.cend())
    {
        Interpreter::error(m_line, "Unterminated string.");
        return;
    }
    std::advance(m_current, 1);

    // Trim the surrounding quotes.
    add_token(TokenType::STRING, std::string(m_start + 1, m_current - 1));
}

bool Scanner::match(char expected)
{
    if (m_current == m_source.cend()) return false;
    if (*m_current != expected) return false;

    std::advance(m_current, 1);
    return true;
}

void Scanner::add_token(TokenType t) { add_token(t, std::monostate{}); }

void Scanner::add_token(TokenType t, Literal literal)
{
    std::string text(m_start, m_current);
    m_tokens.emplace_back(Token{t, text, literal, m_line});
}
