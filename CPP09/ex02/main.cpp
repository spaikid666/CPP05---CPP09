#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1 || argc > 3001)
	{
		std::cout << "[ERROR]: The number of arguments are invalid." << std::endl;
		return 1;
	}
	
	std::vector<int> vec;
	std::deque<int> deq;

	try
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];

			for (size_t j = 0; j < str.length(); j++)
			{
				if (!std::isdigit(str[j]))
				{
					std::string error = "[ERROR]: Invalid character found. Only positive integers allowed.";
					throw std::runtime_error(error);
				}
			}

			long val = std::atol(argv[i]);
			if (val < 0 || val > INT_MAX)
			{
				std::string error = "[ERROR]: Number out of range.";
				throw std::runtime_error(error);
			}

			vec.push_back(static_cast<int>(val));
			deq.push_back(static_cast<int>(val));
		}
	}
	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	PmergeMe sequence(vec, deq);

	std::cout << "Unsorted Sequence: ";
	sequence.printUseq();
	std::cout << "Sorted Sequence: ";
	sequence.printSseq();
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << sequence.getVtime() << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << sequence.getDtime() << " us" << std::endl;

	return 0;	
}