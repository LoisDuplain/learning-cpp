#pragma once

#include <iostream>
#include <string>

template<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_len;

	public:
		Array()	:	_array(NULL), _len(0)
		{};
		Array(unsigned int n)	:	_array(new T[n]), _len(n)
		{};
		Array(Array const &src)
		{
			*this = src;
		};
		virtual	~Array()
		{
			delete [] _array;
		};

		Array	&operator=(Array const &src)
		{
			if (_array)
				delete [] _array;
			_array = new T[src._len];
			for (unsigned int i = 0; i < src._len; i++)
				_array[i] = src._array[i];
			_len = src._len;
			return *this;
		};

		T	&operator[](int index) const {
			if (index >= static_cast<int>(_len) || index < 0)
				throw IndexOutOfBoundsException(_len);
			return _array[index];
		};

		unsigned int size() const { return (_len); };

		class IndexOutOfBoundsException : public std::exception
		{
			private:
				unsigned int _len;

				IndexOutOfBoundsException()
				{};
			public:
				IndexOutOfBoundsException(unsigned int len)	:	_len(len)
				{};
				virtual ~IndexOutOfBoundsException() throw()
				{};
				virtual const char	*what() const throw()
				{
					return "Index out of bounds. (start at index: 0, end at index: " << _len - 1 << ", has a length of: " << _len << ")";
				};
		};
};