#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &xpr) : _xpr(xpr)
{
	_result = parseStk(xpr);
}

RPN::RPN(const RPN &other)
{
	_xpr = other._xpr;
	_result = other._result;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_xpr = other._xpr;
		_result = other._result;
	}
	return *this;
}

RPN::~RPN () {}



std::string RPN::getXpr()
{
	return _xpr;
}

int RPN::getResult()
{
	return _result;
}



int RPN::parseStk(const std::string &str)
{
	std::stack<int> stk;

	for (size_t i = 0; i < str.size() ; i++)
	{
		if (str[i] == ' ')
			continue;

		else if (std::isdigit(str[i]))
		{
			int n = str[i] - '0';
			stk.push(n);
		}

		else if (str[i] == '+')
		{
			if (stk.size() < 2)
			{
				std::cerr << "[ERROR]: Invalid expression." << std::endl;
				exit(1);
			}

			int right = stk.top();
			stk.pop();

			int left = stk.top();
			stk.pop();

			stk.push(left + right);
		}

		else if (str[i] == '-')
		{
			if (stk.size() < 2)
			{
				std::cerr << "[ERROR]: Invalid expression." << std::endl;
				exit(1);
			}

			int right = stk.top();
			stk.pop();

			int left = stk.top();
			stk.pop();

			stk.push(left - right);
		}

		else if (str[i] == '*')
		{
			if (stk.size() < 2)
			{
				std::cerr << "[ERROR]: Invalid expression." << std::endl;
				exit(1);
			}

			int right = stk.top();
			stk.pop();

			int left = stk.top();
			stk.pop();

			stk.push(left * right);
		}

		else if (str[i] == '/')
		{
			if (stk.size() < 2)
			{
				std::cerr << "[ERROR]: Invalid expression." << std::endl;
				exit(1);
			}

			int right = stk.top();
			stk.pop();

			int left = stk.top();
			stk.pop();

			if (right != 0)
				stk.push(left / right);
			else
			{
				std::cerr << "[ERROR]: Can't divide by '0'." << std::endl;
				exit(1);
			}
		}

		else
		{
			std::cerr << "[ERROR]: Invalid character: '" << str[i] << "'." << std::endl;
			exit(1);
		}
	}

	if (stk.size() != 1)
	{
		std::cerr << "[ERROR]: Invalid expression format." << std::endl;
		exit(1);
	}

	return stk.top();
}