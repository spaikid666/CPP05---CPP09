#include "utils.hpp"

bool validArg(const std::string& str)
{
	if (str.empty())
		return false;
	else if (isChar(str) == true || isDigit(str) == true || isFloat(str) == true || isDouble(str) == true || pseudoLiterals(str) == true)
		return true;
	else
		return false;
}

bool isChar(const std::string& str)
{
    if (str.size() != 1)
        return false;
    unsigned char c = static_cast<unsigned char>(str[0]);
    return (std::isprint(c) != 0 && std::isdigit(c) == 0);
}

bool isDigit(const std::string& str)
{
	std::string::size_type i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
	
	for (; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool isFloat(const std::string& str)
{
    std::string::size_type i = 0;
    bool seenDot = false;
    bool seenDigit = false;

    if (str.empty())
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    if (str[str.size() - 1] != 'f')
        return false;

    for (; i < str.size() - 1; i++)
    {
        unsigned char c = static_cast<unsigned char>(str[i]);

        if (c == '.')
        {
            if (seenDot)
                return false;
            seenDot = true;
        }
        else if (std::isdigit(c))
        {
            seenDigit = true;
        }
        else
            return false;
    }

    if (!seenDigit)
        return false;

    return true;
}

bool isDouble(const std::string& str)
{
    std::string::size_type i = 0;
    bool seenDot = false;
    bool seenDigit = false;

    if (str.empty())
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    for (; i < str.size(); i++)
    {
        unsigned char c = static_cast<unsigned char>(str[i]);

        if (c == '.')
        {
            if (seenDot)
                return false;
            seenDot = true;
        }
        else if (std::isdigit(c))
        {
            seenDigit = true;
        }
        else
            return false;
    }

	if (!seenDot)
        return false;

    if (!seenDigit)
        return false;

    return true;
}

bool pseudoLiterals(const std::string& str)
{
	if (str == "-inff" || str == "+inf" || str == "nanf" || str == "-inf" || str == "nan")
		return true;
	return false;
}

void displayChars(const std::string& str)
{
	bool displayable = true;
	//print the char form
	for (std::string::size_type i = 0; i < str.size() ; i++)
	{
		if (!(str[i] >= 36) && !(str[i] <= 136))
		{
			displayable = false;
			break;
		}
	}
	if (displayable == true)
		std::cout << "char :" << str;
	else
		std::cout << "char: Non displayable";
}

void displayInst(const std::string& str)
{
	//print the int form
	if (isDigit(str))
		std::cout << "int :" << str;
}

void displayDoubles(const std::string& str)
{
	std::string temp = str.substr(0, str.size() - 1);

	if (isDigit(temp) && str[str.size() - 1] == 'f')
	{
		//print the number and if its a float print it without the f
	}

}

void displayFloats(const std::string& str)
{
	std::string temp = str.substr(0, str.size() - 1);

	if (isDigit(temp) && std::isalpha(str.size() - 1) == 'f')
	{
		displayDoubles(str);
		std::cout << "f";
	}
}

void displayPseudoLiterals(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || str == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (str == "+inf" || str == "+inff")
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: -inff" << std::endl;
	if (str == "nan" || str == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (str == "+inf" || str == "+inff")
		std::cout << "double: +inff" << std::endl;
	else
		std::cout << "double: -inff" << std::endl;
}