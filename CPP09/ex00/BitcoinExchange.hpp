#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <map>
#include <cstdlib>
#include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		std::map<std::string, float> getDataBase();

		void checkFile(const char* filePath);
		void fileExtension(const std::string& filePath, std::string ext);
		void fileNotEmpty(const std::string& filePath);
		void loadDataBase(const std::string& dbPath);
		void printDataBase() const;

	private:
		std::map<std::string, float> _database;
};

#endif