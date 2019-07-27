#ifndef TOKENS_DEF
#define TOKENS_DEF

#include <string>

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

    EOF 
}

class Token
{
public:
    Token() = delete; // This is probably wrong but it's definitely a little funny
    // Basically what this should do is force the user to initialize this class via
    // aggregate initialization, which means we can avoid initializing the member
    // variables ourselves, and we no longer need to provide a constructor.

    const TokenType type;
    const std::string lexeme;
    const void* literal;
    const int line;
};

#endif // TOKENS_DEF
