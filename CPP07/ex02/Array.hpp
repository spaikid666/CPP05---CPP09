#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	public:
		Array()
		{
			_size = 0;
			_elements = NULL;
		}

		Array(const unsigned int n)
		{
			_size = n;
			_elements = new T[n]();
		}

		Array(const Array& other)
		{
			this->_size = other._size;
			this->_elements = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				this->_elements[i] = other._elements[i];
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] this->_elements;
				this->_size = other._size;
				T *arr = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					arr[i] = other._elements[i];
				this->_elements = arr;
			}
			return *this;
		}

		T& operator[](unsigned int index)
		{
 			if (index >= _size)
			{
				throw OutOfBoundsException();
			}
  		  return _elements[index];
		}

		const T& operator[](unsigned int index) const
		{
    		if (index >= _size)
			{
       			throw OutOfBoundsException();
   			}
   			return _elements[index];
		}

		~Array()
		{
			delete[] _elements;
		}

		unsigned int getSize () const
		{
			return this->_size;
		}

		class OutOfBoundsException : public std::exception
		{
    		public:
        		virtual const char* what() const throw()
				{
					return "Index is out of bounds";
        		}
		};
		
	private:
		unsigned int _size;
		T* _elements;
};

#endif