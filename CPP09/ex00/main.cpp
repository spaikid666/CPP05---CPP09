#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "[ERROR]: The number of arguments is invalid." << std::endl;
		exit(1);
	}

	BitcoinExchange be;

	be.checkFile(argv[1]);
	be.loadDataBase("./data.csv");
	
	/* Print the database 
	be.printDataBase();
	*/

	
}