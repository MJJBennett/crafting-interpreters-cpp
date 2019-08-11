#include "scanner.h"

std::vector<Token>& Scanner::scan_tokens()
{
    while(m_current != m_source.end())
    {
        m_start = m_current;
        scan_token();
    }
    m_tokens.emplace_back(Token{TokenType::EOFILE, "", nullptr, m_line});
    return m_tokens;
}

void Scanner::scan_token()
{
    const auto c = *m_current;
    std::advance(m_current, 1);
    switch (c) {
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
    }
}

void Scanner::add_token(TokenType t)
{
    add_token(t, nullptr);
}

void Scanner::add_token(TokenType t, void* literal)
{
    std::string text(m_start, m_current);
    m_tokens.emplace_back(Token{t, text, literal, m_line});
}
