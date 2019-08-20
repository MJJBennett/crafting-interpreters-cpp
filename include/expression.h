#ifndef EXPRESSION_LOX_H
#define EXPRESSION_LOX_H

#include "tokens.h"

struct Expression
{
};

struct UnaryExpr : public Expression
{
public:
	UnaryExpr(Token op, const Expression* right)
		: m_op(op), m_right(right)
	{
	}

private:
	const Token m_op;
	const Expression* m_right;
};

struct VariableExpr : public Expression
{
public:
	VariableExpr(Token name)
		: m_name(name)
	{
	}

private:
	const Token m_name;
};

struct BinaryExpr : public Expression
{
public:
	BinaryExpr(const Expression* left, Token op, const Expression* right)
		: m_left(left), m_op(op), m_right(right)
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
		: m_name(name), m_value(value)
	{
	}

private:
	const Token m_name;
	const Expression* m_value;
};

struct ThisExpr : public Expression
{
public:
	ThisExpr(Token keyword)
		: m_keyword(keyword)
	{
	}

private:
	const Token m_keyword;
};

struct SuperExpr : public Expression
{
public:
	SuperExpr(Token keyword, Token method)
		: m_keyword(keyword), m_method(method)
	{
	}

private:
	const Token m_keyword;
	const Token m_method;
};

struct SetExpr : public Expression
{
public:
	SetExpr(const Expression* object, Token name, const Expression* value)
		: m_object(object), m_name(name), m_value(value)
	{
	}

private:
	const Expression* m_object;
	const Token m_name;
	const Expression* m_value;
};

struct LogicalExpr : public Expression
{
public:
	LogicalExpr(const Expression* left, Token op, const Expression* right)
		: m_left(left), m_op(op), m_right(right)
	{
	}

private:
	const Expression* m_left;
	const Token m_op;
	const Expression* m_right;
};

#endif  // EXPRESSION_LOX_H
