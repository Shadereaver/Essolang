#include "Lexer.h"

#include <regex>
#include <fstream>


Token::Token(TokenType type, std::string value)
{
	Type = type;
	Value = value;
}


std::vector<Token> Tokenise(std::ifstream& sourceFile)
{
	std::vector<Token> Tokens;
	std::string sre = "(";

	{
	std::string est = 
		"\\s+|"
		"\\n+|"
		"\\t+";

	std::string ist =
		"\\(|"
		"\\)|"
		"=|"
		",|"
		"-|"
		"\\+|"
		"/|"
		"\\*|"
		";";

	sre.append(est);
	sre.append(")|(");
	sre.append(ist);
	sre.append(")");
	}

	std::regex re = std::regex(sre);
	std::string source;

	while (std::getline(sourceFile, source))
	{
		std::sregex_token_iterator it{source.begin(), source.end(), re, {-1,2}};
		std::vector<std::string> src{it,{}};
		src.erase(std::remove_if(src.begin(), src.end(), [](std::string& s){return s.size() == 0;}), src.end());

		for (std::string elem : src)
		{
			if (elem == "(") Tokens.emplace_back(TokenType::OpenParen, elem);
			else if (elem == ")") Tokens.emplace_back(TokenType::CloseParen, elem);
			else if (elem == "=") Tokens.emplace_back(TokenType::Assignment, elem);
			else if (elem == "+" || elem == "-" || elem == "*" || elem == "/") Tokens.emplace_back(TokenType::BinaryOperator, elem);
			else if (elem.find_first_of("0123456789") != std::string::npos && elem.find_first_not_of("0123456789") == std::string::npos) Tokens.emplace_back(TokenType::Number, elem);
			else if (elem.find_first_of("0123456789") == std::string::npos)
			{
				if (KEYWORDS.count(elem))
				{
					Tokens.emplace_back(KEYWORDS.at(elem), elem);
				}
				else Tokens.emplace_back(TokenType::Identifier, elem);
			}
			else throw 1;
		}
	}

	Tokens.emplace_back(TokenType::EoF, "EOF");

	return Tokens;
}


