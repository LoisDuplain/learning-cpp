#include "Span.hpp"

Span::Span(): _n(0)
{
}
Span::Span(unsigned int n): _n(n)
{
}
Span::Span(Span const &src)
{
	*this = src;
}
Span::~Span()
{
}

std::vector<int> const	&Span::getVector() const
{
	return _vector;
}

void	Span::addNumber(int nb)
{
	if (_vector.size() >= _n)
		throw SpanFullException();
		
	_vector.insert(_vector.end(), nb);
}
void	Span::addNumber(std::vector<int> vec)
{
	if (_vector.size() >= _n)
		throw SpanFullException();
	_vector.insert(_vector.end(), vec.begin(), vec.begin() + _n - _vector.size());
}

int	Span::shortestSpan()
{
	if (_n <= 1)
		throw SpanTooSmallException();
	
	std::vector<int> tmp = _vector;

	std::sort(tmp.begin(), tmp.end());
	unsigned int min_span = UINT_MAX;

	for (std::vector<int>::iterator it = tmp.begin(); it < tmp.end(); it++)
	{
		if (*(it + 1)
			&& min_span > (unsigned int)(*(it + 1) - *it))
			min_span = (unsigned int)(*(it + 1) - *it);
	}
	
	return min_span;
}
int	Span::longestSpan()
{
	if (_n <= 1)
		throw SpanTooSmallException();
	
	int min = *std::min_element(_vector.begin(), _vector.end());
	int max = *std::max_element(_vector.begin(), _vector.end());
	return max - min;
}

Span	&Span::operator=(Span const &src)
{
	_n = src._n;
	_vector.clear();
	_vector.insert(_vector.begin(), src._vector.begin(), src._vector.end());
	return *this;
}
std::ostream	&operator<<(std::ostream &o, Span &src)
{
	int i = 0;
	std::vector<int> srcVec = src.getVector();
	for (std::vector<int>::iterator it = srcVec.begin(); it < srcVec.end(); it++)
	{
		o << "Vector at " << i << " = " << *it;
		if (it != srcVec.end() - 1)
			o << std::endl;
		i++;
	}
	return o;
}