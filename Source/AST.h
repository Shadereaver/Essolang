#pragma once

#include <vector>
#include <string>


enum class NodeType
{
	Program,
	NumericLiteral,
	Identifier,
	BinaryExpr,
};

struct Stmt
{
	NodeType Kind;
};

struct Program : Stmt
{
	Program();

	std::vector<Stmt*> Body;
};

struct Expr : Stmt {};

struct BinaryExpr : Expr
{
	BinaryExpr();

	Expr Left;
	Expr Right;
	std::string Operator;
};

struct Identifier : Expr
{
	Identifier(std::string symbol);

	std::string Symbol;
};

struct NumericLiteral : Expr
{
	NumericLiteral(float value);

	float Value;
};