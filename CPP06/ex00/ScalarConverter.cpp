#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {}

ScalarConverter::~ScalarConverter () {}


static void convert(const std::string str)
{
	if !isdigit(str)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (i > 1)
				return;
		}

		if (str[0] < 36 && str[0] > 127)
			bool non_print = 1;		
		std::cout << str << std::endl;
	}

	
}