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

bool BitcoinExchange::checkDate(std::string& date)
{
	if (date.size() != 10)
        return false;

	if (date[4] != '-' || date[7] != '-')
        return false;

	for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

	if (date[5] > '1' || (date[5] == '1' && date[6] > '2') || (date[8] > '3') || (date[8] == '3' && date[9] > '1') || (date[5] == '0' && date[6] == '2' && date[8] > '2'))
		return false;

	return true;
}

bool BitcoinExchange::checkPrice(double price)
{
	if (price < 0)
	{
		std::cerr << "[ERROR]: not a positive number." << std::endl; 
		return false;
	}	
	if (price > 1000)
	{
		std::cerr << "[ERROR]: too large a number." << std::endl; 
		return false;
	}
	return true;
}

void BitcoinExchange::fileFormat(const std::string& filePath)
{
	std::ifstream userDB(filePath.c_str());
	std::string line;

	std::getline(userDB, line);
	if (line != "date | value")
	{
		std::cerr << "[ERROR]: The file '" << filePath << "' has an invalid format." << std::endl;
		exit(1);
	}

	while (std::getline(userDB, line))
	{
			size_t separator = line.find(" | ");

		if (separator == std::string::npos)
		{
			std::cerr << "[ERROR]: bad input => " << line << std::endl;
			continue;
		}

			std::string dateString = line.substr(0, separator);

		if (!checkDate(dateString))
		{
			std::cerr << "[ERROR]: bad input => " << dateString << std::endl;
			continue;
		}

		std::string priceString = line.substr(separator + 3);
        char* endPtr;
        double price = std::strtod(priceString.c_str(), &endPtr);

		if (*endPtr != '\0' && *endPtr != '\n')
		{
			std::cerr << "[ERROR]: bad input => " << priceString << std::endl;
			continue;
		}

		if (!checkPrice(price))
		{
			continue;
		}
		
		std::map<std::string, float>::iterator it = this->_database.lower_bound(dateString);

        if (it == this->_database.begin() && it->first != dateString)
		{
            std::cerr << "[ERROR]: Date is too early for database." << std::endl;
            continue;
        }

        if (it == this->_database.end() || it->first != dateString)
		{
            --it; 
        }

        std::cout << dateString << " => " << price << " = " << (price * it->second) << std::endl;
	}
}

void BitcoinExchange::checkFile(const char* filePath)
{
	fileExtension(filePath, ".txt");
	fileNotEmpty(filePath);
	fileFormat(filePath);
}

void BitcoinExchange::loadDataBase(const std::string& dbPath)
{
	std::ifstream db(dbPath.c_str());
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
		{
			std::cerr << "[ERROR]: The file '" << dbPath << "' has an invalid format." << std::endl;
			exit(1);
		}
		dateString = line.substr(0, comma);
		priceString = line.substr(comma + 1);
		price = atof(priceString.c_str());
		this->_database[dateString] = price;
	}
}