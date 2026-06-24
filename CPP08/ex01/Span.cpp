#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size)
{
	this->_storage.reserve(this->_size);
}

Span::Span(const Span& other) {
    this->_size = other._size;
    this->_storage = other._storage;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_size = other._size;
        this->_storage = other._storage;
    }
    return *this;
}

Span::~Span() {}





int Span::getSize()
{
	return _size;
}

std::vector<int> Span::getStorage()
{
	return _storage;
}





void Span::addNumber(int numb)
{
	if (this->_storage.size() >= this->_size)
		throw storageFull();

	else
		this->_storage.push_back(numb);
}

int Span::shortestSpan()
{
	if (_storage.size() <= 1)
		throw noSpan();

	std::vector<int> copy = getStorage();
	int span = INT_MAX;
	int temp = 0;

	std::sort(copy.begin(), copy.end());
	for (size_t i = 0; (i + 1) < copy.size(); i++)
	{
		temp = copy[i + 1] - copy[i];
		if (temp < span)
			span = temp;
	}

	return span;
}

int Span::longestSpan()
{
	if (_storage.size() <= 1)
		throw noSpan();

	int span = *std::max_element(_storage.begin(), _storage.end()) - *std::min_element(_storage.begin(), _storage.end());

	return span;
}