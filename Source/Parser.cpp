#include "Parser.h"

#include "AST.h"
#include "Lexer.h"


Parser::Parser()
{
}

Program* const Parser::ProduceAST(std::ifstream &SourceCode)
{
	_Tokens = Tokenise(SourceCode);

	Program* program = new Program();

	while (NotEOF())
	{
		program->Body.push_back(ParseStmt());
	}

	return program;
}


Stmt* const Parser::ParseStmt()
{
	return ParseExpr();
}

Expr* const Parser::ParseExpr()
{
	return ParsePrimaryExpr();
}

Expr* const Parser::ParsePrimaryExpr()
{
	const TokenType TK = AT().Type;

	switch (TK)
	{
	case TokenType::Identifier:
		return new Identifier{Eat().Value};
	case TokenType::Number:
		return new NumericLiteral{stof(Eat().Value)};
	default:
		throw 2;
	}
}


bool Parser::NotEOF()
{
	return _Tokens[0].Type != TokenType::EoF;
}

Token& Parser::AT()
{
	return _Tokens[0];
}

Token Parser::Eat()
{
	Token prev = AT();
	_Tokens.erase(_Tokens.begin());

	return prev;
}
