#pragma once
#include <vector>
#include <string>


struct Program;
struct Token;
struct Stmt;
struct Expr;


class Parser
{
public:
	Parser();

	Program* const ProduceAST(std::ifstream &SourceCode);

private:
	std::vector<Token> _Tokens;

	bool NotEOF();
	Stmt* const ParseStmt();
	Expr* const ParseExpr();
	Expr* const ParsePrimaryExpr();
	Token& AT();
	Token Eat();
};