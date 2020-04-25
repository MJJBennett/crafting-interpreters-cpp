#ifndef EXPRESSION_LOX_H
#define EXPRESSION_LOX_H

#include <vector>
#include "tokens.h"

struct Expression
{
};

struct AssignExpr;
struct BinaryExpr;
struct CallExpr;
struct GetExpr;
struct GroupingExpr;
struct LiteralExpr;
struct LogicalExpr;
struct SetExpr;
struct SuperExpr;
struct ThisExpr;
struct UnaryExpr;
struct VariableExpr;

template<typename T>
struct Visitor
{
	T visitAssignExpr(const AssignExpr& expr);
	T visitBinaryExpr(const BinaryExpr& expr);
	T visitCallExpr(const CallExpr& expr);
	T visitGetExpr(const GetExpr& expr);
	T visitGroupingExpr(const GroupingExpr& expr);
	T visitLiteralExpr(const LiteralExpr& expr);
	T visitLogicalExpr(const LogicalExpr& expr);
	T visitSetExpr(const SetExpr& expr);
	T visitSuperExpr(const SuperExpr& expr);
	T visitThisExpr(const ThisExpr& expr);
	T visitUnaryExpr(const UnaryExpr& expr);
	T visitVariableExpr(const VariableExpr& expr);
};

struct AssignExpr : public Expression
{
public:
	AssignExpr(Token name, const Expression* value)
		: m_name(name), m_value(value)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitAssignExpr(*this);
	}

private:
	const Token m_name;
	const Expression* m_value;
};

struct BinaryExpr : public Expression
{
public:
	BinaryExpr(const Expression* left, Token op, const Expression* right)
		: m_left(left), m_op(op), m_right(right)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitBinaryExpr(*this);
	}

private:
	const Expression* m_left;
	const Token m_op;
	const Expression* m_right;
};

struct CallExpr : public Expression
{
public:
	CallExpr(const Expression* callee, Token paren, std::vector<const Expression*> arguments)
		: m_callee(callee), m_paren(paren), m_arguments(std::move(arguments))
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitCallExpr(*this);
	}

private:
	const Expression* m_callee;
	const Token m_paren;
	const std::vector<const Expression*> m_arguments;
};

struct GetExpr : public Expression
{
public:
	GetExpr(const Expression* object, Token name)
		: m_object(object), m_name(name)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitGetExpr(*this);
	}

private:
	const Expression* m_object;
	const Token m_name;
};

struct GroupingExpr : public Expression
{
public:
	GroupingExpr(const Expression* expression)
		: m_expression(expression)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitGroupingExpr(*this);
	}

private:
	const Expression* m_expression;
};

struct LiteralExpr : public Expression
{
public:
	LiteralExpr(Literal value)
		: m_value(value)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitLiteralExpr(*this);
	}

private:
	const Literal m_value;
};

struct LogicalExpr : public Expression
{
public:
	LogicalExpr(const Expression* left, Token op, const Expression* right)
		: m_left(left), m_op(op), m_right(right)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitLogicalExpr(*this);
	}

private:
	const Expression* m_left;
	const Token m_op;
	const Expression* m_right;
};

struct SetExpr : public Expression
{
public:
	SetExpr(const Expression* object, Token name, const Expression* value)
		: m_object(object), m_name(name), m_value(value)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitSetExpr(*this);
	}

private:
	const Expression* m_object;
	const Token m_name;
	const Expression* m_value;
};

struct SuperExpr : public Expression
{
public:
	SuperExpr(Token keyword, Token method)
		: m_keyword(keyword), m_method(method)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitSuperExpr(*this);
	}

private:
	const Token m_keyword;
	const Token m_method;
};

struct ThisExpr : public Expression
{
public:
	ThisExpr(Token keyword)
		: m_keyword(keyword)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitThisExpr(*this);
	}

private:
	const Token m_keyword;
};

struct UnaryExpr : public Expression
{
public:
	UnaryExpr(Token op, const Expression* right)
		: m_op(op), m_right(right)
	{
	}

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitUnaryExpr(*this);
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

	template<typename T>
	T accept(Visitor<T> visitor)
	{
		return visitor.visitVariableExpr(*this);
	}

private:
	const Token m_name;
};

#endif  // EXPRESSION_LOX_H
