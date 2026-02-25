#include "ScalarConverter.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
	if (!(argc == 2))
	{
		std::cerr << "Please provide one argument" << std::endl;
		return 1;
	}

    std::string literal(argv[1]);

    if (validArg(literal) == false)
    {
        std::cerr << "Please provide a valid argument" << std::endl;
        return 1;
    }

    ScalarConverter::convert(literal);
    return 0;
}