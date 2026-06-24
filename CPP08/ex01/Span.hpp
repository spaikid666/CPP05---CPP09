#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <climits>

class storageFull : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "[ERROR]: The container is full.";
		}
};

class noSpan : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "[ERROR]: The Span can't be found.";
		}
};

class Span
{
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& other);
		Span &operator=(const Span& other);
		~Span();

		int getSize();
		std::vector<int> getStorage();

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();

		template<typename Iterator>
		void addNumber(Iterator begin, Iterator end)
		{
			unsigned int distance = std::distance(begin, end);
			if (_storage.size() + distance > _size)
				throw storageFull();
			this->_storage.insert(this->_storage.end(), begin, end);
		}

	private:
		unsigned int _size;
		std::vector<int> _storage;
};

#endif