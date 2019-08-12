#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "tokens.h"

class Scanner
{
    using str_itr = std::string::const_iterator;

    const static std::string str_unexpected;

public:
    Scanner(std::string source, unsigned int line = 1)
        : m_source(std::move(source)),
          m_start(m_source.begin()),
          m_current(m_source.begin()),
          m_line(line)
    {
    }
    std::vector<Token>& scan_tokens();
    unsigned int line() const { return m_line; }

private:
    void scan_token();
    void add_token(TokenType t);
    void add_token(TokenType t, Literal literal);
    bool match(char expected);

    void consume_string();
    void consume_number();
    void consume_identifier();

    // Safe lookahead functions (returns '\0' in case of m_source.cend())
    [[nodiscard]] char peek() const;
    [[nodiscard]] char peek2() const;

private:
    std::string m_source;
    std::vector<Token> m_tokens;

    str_itr m_start;
    str_itr m_current;
    unsigned int m_line;
};

#endif  // SCANNER_H
