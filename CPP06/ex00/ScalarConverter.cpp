#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {}

ScalarConverter::~ScalarConverter () {}

void ScalarConverter::convert(const std::string& str)
{
    switch (detectType(str))
    {
        case TYPE_PSEUDO:
            displayPseudoLiterals(str);
            break;
        case TYPE_CHAR:
            displayChar(str);
            break;
        case TYPE_INT:
            displayInt(str);
            break;
        case TYPE_FLOAT:
            displayFloat(str);
            break;
        case TYPE_DOUBLE:
            displayDouble(str);
            break;
        default:
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            break;
    }
}