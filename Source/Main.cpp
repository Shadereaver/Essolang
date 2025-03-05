#include <iostream>
#include <fstream>

#include "Parser.h"


int main()
{
	std::ifstream sourceFile("Source/IN.txt");

	sourceFile.exceptions(std::ios_base::badbit);

	if (not sourceFile)
	{
		throw std::ios_base::failure("File does not exist");
	}


	std::unique_ptr<Parser> parser = std::make_unique<Parser>();

	Program* const program = parser->ProduceAST(sourceFile);

	std::cout << program;
}