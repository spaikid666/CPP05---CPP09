#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "[ERROR]: The number of arguments is invalid." << std::endl;
		exit(1);
	}

	BitcoinExchange be;

	be.loadDataBase("./data.csv");
	be.checkFile(argv[1]);
	
	/* Print the database 
	be.printDataBase();
	*/
}