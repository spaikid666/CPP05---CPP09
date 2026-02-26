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

// --- validation / detection (your style) ---
bool validArg(const std::string& str);

bool isChar(const std::string& str);
bool isDigit(const std::string& str);   // signed int literal (name kept for you)
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);
bool pseudoLiterals(const std::string& str);

// --- type enum + high-level conversion/printing ---
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

// One function that does exactly what the subject says (parse -> cast -> print)
void convertAndPrint(const std::string& s);





void displayPseudoLiterals(const std::string& str);
void displayChar(const std::string& str);
void displayInt(const std::string& str);
void displayDouble(const std::string& str);
void displayFloat(const std::string& str);

#endif