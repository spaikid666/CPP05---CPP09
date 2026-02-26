#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter () {}

void ScalarConverter::convert(const std::string& literal)
{
    convertAndPrint(literal);
}