#ifndef KEYWORDS_LOX_H
#define KEYWORDS_LOX_H

#include "tokens.h"
#include <unordered_map>

const static std::unordered_map<std::string, TokenType> keywords{
    {"and", TokenType::AND},     {"class", TokenType::CLASS},   {"else", TokenType::ELSE},
    {"false", TokenType::FALSE}, {"for", TokenType::FOR},       {"fun", TokenType::FUN},
    {"if", TokenType::IF},       {"nil", TokenType::NIL},       {"or", TokenType::OR},
    {"print", TokenType::PRINT}, {"return", TokenType::RETURN}, {"super", TokenType::SUPER},
    {"this", TokenType::THIS},   {"true", TokenType::TRUE},     {"var", TokenType::VAR},
    {"while", TokenType::WHILE}
};

#endif // KEYWORDS_LOX_H
