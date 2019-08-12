#ifndef TOKENS_DEF
#define TOKENS_DEF

#include <string>
#include <iostream>
#include <variant>

using Literal = std::variant<std::string, double, std::monostate>;

// Token enum copied from Crafting Interpreters
enum class TokenType
{
    // Single-character tokens.                      
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR, 

    // One or two character tokens.                  
    BANG, BANG_EQUAL,                                
    EQUAL, EQUAL_EQUAL,                              
    GREATER, GREATER_EQUAL,                          
    LESS, LESS_EQUAL,                                

    // Literals.                                     
    IDENTIFIER, STRING, NUMBER,                      

    // Keywords.                                     
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,  
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,    

    EOFILE 
};

namespace {
using std::to_string;
std::string to_string(TokenType tokentype)
{
    switch (tokentype)
    {
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::DOT: return "DOT";
        case TokenType::MINUS: return "MINUS";
        case TokenType::PLUS: return "PLUS";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::SLASH: return "SLASH";
        case TokenType::STAR: return "STAR";
        case TokenType::BANG: return "BANG";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESS: return "LESS";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::STRING: return "STRING";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::AND: return "AND";
        case TokenType::CLASS: return "CLASS";
        case TokenType::ELSE: return "ELSE";
        case TokenType::FALSE: return "FALSE";
        case TokenType::FUN: return "FUN";
        case TokenType::FOR: return "FOR";
        case TokenType::IF: return "IF";
        case TokenType::NIL: return "NIL";
        case TokenType::OR: return "OR";
        case TokenType::PRINT: return "PRINT";
        case TokenType::RETURN: return "RETURN";
        case TokenType::SUPER: return "SUPER";
        case TokenType::THIS: return "THIS";
        case TokenType::TRUE: return "TRUE";
        case TokenType::VAR: return "VAR";
        case TokenType::WHILE: return "WHILE";
        case TokenType::EOFILE: return "EOFILE";
        default: return "";
    }
}
}

class Token
{
    friend std::ostream& operator<<(std::ostream&, const Token&);
public:
    Token() = delete; // This is probably wrong but it's definitely a little funny
    // Basically what this should do is force the user to initialize this class via
    // aggregate initialization, which means we can avoid initializing the member
    // variables ourselves, and we no longer need to provide a constructor.

    const TokenType type;
    const std::string lexeme;
    const Literal literal;
    const unsigned int line;
};

std::ostream& operator<<(std::ostream&, const Token&);

#endif // TOKENS_DEF
