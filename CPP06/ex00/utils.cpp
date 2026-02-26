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

    if (str.empty())
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    if (i == str.size())
        return false;

    for (; i < str.size(); i++)
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;

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
            seenDigit = true;
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
            seenDigit = true;
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

// =====================
// Type detection
// =====================

LiteralType detectType(const std::string& s)
{
    if (s.empty()) return T_INVALID;
    if (pseudoLiterals(s)) return T_PSEUDO;
    if (isChar(s)) return T_CHAR;
    if (isDigit(s)) return T_INT;
    if (isFloat(s)) return T_FLOAT;
    if (isDouble(s)) return T_DOUBLE;
    return T_INVALID;
}

// =====================
// Conversion + printing helpers (kept static inside utils.cpp)
// =====================

static void printPseudo(const std::string& s)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (s == "nan" || s == "nanf")
    {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    else if (s[0] == '-')
    {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
    else
    {
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
}

static void printAllFromDouble(double d)
{
    // char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0.0 || d > 255.0)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    // int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) ||
        d < static_cast<double>(std::numeric_limits<int>::min()) ||
        d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << std::endl;
		
    // float
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (std::isnan(f))
        std::cout << "nanf\n";
    else if (std::isinf(f))
        std::cout << (f < 0 ? "-inff\n" : "+inff\n");
    else
        std::cout << f << "f" << std::endl;

    // double
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf\n" : "+inf\n");
    else
        std::cout << d << std::endl;
}

// =====================
// The single public API used by ScalarConverter
// =====================

void convertAndPrint(const std::string& s)
{
    LiteralType t = detectType(s);

    if (t == T_INVALID)
    {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible"<< std::endl;
		std::cout << "double: impossible" << std::endl;
        return;
    }

    if (t == T_PSEUDO)
    {
        printPseudo(s);
        return;
    }

    errno = 0;
    char *end = 0;
    double d = 0.0;

    if (t == T_CHAR)
    {
        // actual type: char
        char c = s[0];
        d = static_cast<double>(c);
    }
    else if (t == T_INT)
    {
        long v = std::strtol(s.c_str(), &end, 10);
        if (errno != 0 || end == s.c_str() || *end != '\0')
        {
            std::cout << "char: impossible" << std::endl;;
            std::cout << "int: impossible" << std::endl;;
            std::cout << "float: impossible" << std::endl;;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        // actual type: int
        int iv = static_cast<int>(v);
        d = static_cast<double>(iv);
    }
    else if (t == T_FLOAT)
    {
        std::string core = s.substr(0, s.size() - 1);
        double tmp = std::strtod(core.c_str(), &end);
        if (errno != 0 || end == core.c_str() || *end != '\0')
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible"<< std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        float fv = static_cast<float>(tmp);
        d = static_cast<double>(fv);
    }
    else if (t == T_DOUBLE)
    {
        double dv = std::strtod(s.c_str(), &end);
        if (errno != 0 || end == s.c_str() || *end != '\0')
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible"<< std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        d = dv;
    }

    printAllFromDouble(d);
}