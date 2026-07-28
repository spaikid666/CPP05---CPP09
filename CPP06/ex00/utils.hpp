#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>

bool validArg(const std::string& str);

bool isChar(const std::string& str);
bool isDigit(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);
bool pseudoLiterals(const std::string& str);

enum LiteralType
{
    T_CHAR,
    T_INT,
    T_FLOAT,
    T_DOUBLE,
    T_PSEUDO,
    T_INVALID
};

LiteralType detectType(const std::string& s);

void convertAndPrint(const std::string& s);

void displayPseudoLiterals(const std::string& str);
void displayChar(const std::string& str);
void displayInt(const std::string& str);
void displayDouble(const std::string& str);
void displayFloat(const std::string& str);

#endif