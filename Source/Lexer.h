#pragma once

#include <map>
#include <string>
#include <vector>


enum class TokenType : char
{
	Identifier = 'I',
	Number = 'N',
	Assignment = 'A',
	BinaryOperator = 'B',
	OpenParen = '(',
	CloseParen = ')',
	Comma = ',',
	SemiCollon = ';',
	EoF = -1
};


static std::map<std::string, TokenType> KEYWORDS
{
	{",", TokenType::Comma},
	{";", TokenType::SemiCollon}
};


struct Token
{
	Token(TokenType type, std::string value);

	TokenType Type;
	std::string Value;
};


std::vector<Token> Tokenise(std::ifstream& sourceFile);
