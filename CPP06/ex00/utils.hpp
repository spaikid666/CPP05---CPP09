#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cctype>
#include <string>

enum LiteralType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO,
    TYPE_INVALID
};

static LiteralType detectType(const std::string& str)
{
    if (str.empty()) return TYPE_INVALID;
    if (pseudoLiterals(str)) return TYPE_PSEUDO;
    if (isChar(str))         return TYPE_CHAR;
    if (isDigit(str))        return TYPE_INT;
    if (isFloat(str))        return TYPE_FLOAT;
    if (isDouble(str))       return TYPE_DOUBLE;
    return TYPE_INVALID;
}

bool validArg(const std::string& str);

bool pseudoLiterals(const std::string& str);
bool isChar(const std::string& str);
bool isDigit(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);

void displayPseudoLiterals(const std::string& str);
void displayChar(const std::string& str);
void displayInt(const std::string& str);
void displayDouble(const std::string& str);
void displayFloat(const std::string& str);

#endif