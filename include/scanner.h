#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "tokens.h"

class Scanner
{
    using str_itr = std::string::const_iterator;
public:
    Scanner(std::string source) : m_source(std::move(source)), m_start(m_source.begin()), m_current(m_source.begin()) {}
    std::vector<Token>& scan_tokens();
    
private:
    void scan_token();
    void add_token(TokenType t);
    void add_token(TokenType t, void* literal);

private:
    std::string m_source;
    std::vector<Token> m_tokens;

    str_itr m_start;
    str_itr m_current;
    unsigned int m_line = 1;
};

#endif // SCANNER_H
