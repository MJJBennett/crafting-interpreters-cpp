#ifndef EXPRESSION_LOX_H
#define EXPRESSION_LOX_H

#include "tokens.h"

struct Expression
{
};

struct BinaryExpr : public Expression
{
public:
    BinaryExpr(const Expression* left, Token op, const Expression* right)
        : m_left(left), m_op(std::move(op)), m_right(right)
    {
    }

private:
    const Expression* m_left;
    const Token m_op;
    const Expression* m_right;
};

struct AssignExpr : public Expression
{
public:
    AssignExpr(Token name, const Expression* value)
        : m_name(std::move(name)), m_value(value)
    {
    }

private:
    const Token m_name;
    const Expression* m_value;
};

struct BinaryExpr : public Expression
{
public:
    BinaryExpr(const Expression* left, Token op, const Expression* right)
        : m_left(left), m_op(std::move(op)), m_right(right)
    {
    }

private:
    const Expression* m_left;
    const Token m_op;
    const Expression* m_right;
};

#endif  // EXPRESSION_LOX_H
