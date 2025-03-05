#include "AST.h"

Program::Program()
{
	Kind = NodeType::Program;
}

BinaryExpr::BinaryExpr()
{
	Kind = NodeType::BinaryExpr;
}

Identifier::Identifier(std::string symbol)
{
	Kind = NodeType::Identifier;
	Symbol = symbol;
}

NumericLiteral::NumericLiteral(float value)
{
	Kind = NodeType::NumericLiteral;
	Value = value;
}
