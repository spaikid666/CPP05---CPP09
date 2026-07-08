#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "[ERROR]: The number of arguments is invalid." << std::endl;
		return 1;
	}

	RPN arg(argv[1]);

	std::cout << arg.getResult() << std::endl;
}