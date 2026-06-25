#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_database = other._database;
}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}



std::map<std::string, float> BitcoinExchange::getDataBase()
{
	return this->_database;
}


void BitcoinExchange::printDataBase() const
{
    for (std::map<std::string, float>::const_iterator it = _database.begin();
         it != _database.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

void BitcoinExchange::fileExtension(const std::string& filePath, std::string ext)
{
    if (filePath.size() < ext.size())
    {
        std::cerr << "[ERROR]: The file name '" << filePath << "' is too short." << std::endl;
        exit(1);
    }
    
    std::string fileExt = filePath.substr(filePath.size() - ext.size());
    if (fileExt != ext)
    {
        std::cerr << "[ERROR]: The extension '" << fileExt << "' from '" << filePath << "' is not supported, try '" << ext << "'." << std::endl;
        exit(1);
    }
}

void BitcoinExchange::fileNotEmpty(const std::string& filePath)
{
	int fd = open(filePath.c_str(), 0);
	if(fd < 0)
	{
		std::cerr << "[ERROR]: '" << filePath << "' doesn't exist or is not accessible." << std::endl;
		exit(1);
	}
	char c;
	if(!read(fd, &c, 1))
	{
		std::cerr << "[ERROR]: The file '" << filePath << "' is empty." << std::endl;
		exit(1);
	}
	close(fd);
}

void BitcoinExchange::checkFile(const char* filePath)
{
	fileExtension(filePath, ".txt");
	fileNotEmpty(filePath);
}

void BitcoinExchange::loadDataBase(const std::string& dbPath)
{
	std::ifstream db(dbPath);
	if (!db.good())
	{
		std::cerr << "[ERROR]: The data base failed to open." << std::endl;
		exit(1);
	}
	std::string line;
	size_t comma;
	std::string dateString;
	std::string priceString;
	float price;

	std::getline(db, line);
	while (std::getline(db, line))
	{
		comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		dateString = line.substr(0, comma);
		priceString = line.substr(comma + 1);
		price = atof(priceString.c_str());
		this->_database[dateString] = price;
	}
}