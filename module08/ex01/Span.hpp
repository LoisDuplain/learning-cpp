#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <climits>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_vector;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		virtual ~Span();

		Span	&operator=(Span const &src);

		std::vector<int> const	&getVector() const;

		void	addNumber(int nb);
		void	addNumber(std::vector<int> vec);

		int		shortestSpan();
		int		longestSpan();

		class SpanFullException : public std::exception
		{
			public:
				SpanFullException() {};
				virtual ~SpanFullException() throw() {};
				virtual const char	*what() const throw() { return "Span is full."; };
		};
		class SpanTooSmallException : public std::exception
		{
			public:
				SpanTooSmallException() {};
				virtual ~SpanTooSmallException() throw() {};
				virtual const char	*what() const throw() { return "Span is empty or contains only one value."; };
		};
};
std::ostream	&operator<<(std::ostream &o, Span &src);