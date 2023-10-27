#include "Span.hpp"

/* Orthodox Canonical Form */
Span::Span()
{
	std::cout << "(Span) Default Constructor called" << std::endl;
}

Span::Span(unsigned int N) :_maxSize(N)
{
	std::cout << "(Span) Constructor called" << std::endl;
}

Span::Span(const Span& rhs) :_vec(rhs._vec), _maxSize(rhs._maxSize)
{
	std::cout << "(Span) Copy Constructor called"  << std::endl;
}

Span::~Span()
{
	std::cout << "(Span) Destructor called" << std::endl;
}

Span& Span::operator=(const Span& rhs)
{
	std::cout << "(Span) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	_vec = rhs._vec;
	_maxSize = rhs._maxSize;
	return *this;
}

/* Function */
void	Span::addNumber(int value)
{
	if (_vec.size() >= _maxSize )
		throw std::runtime_error("Cannot be added to SPAN.");
	_vec.push_back(value);
}

void	Span::addNumber(int value, int num)
{
	if (_vec.size() + num > _maxSize )
		throw std::runtime_error("Cannot be added to SPAN.");
	_vec.insert(_vec.end(), num, value);
}

int	Span::shortestSpan(void)
{
	if (_vec.size() < 2)
		throw std::runtime_error("There is too little content in SPAN.");
	std::sort(_vec.begin(), _vec.end());
	int shortSpan = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end() - 1; it++)
	{
		int span = *(it + 1) - *it;
		shortSpan = span < shortSpan ? span : shortSpan;
	}
	return shortSpan;
}

int		Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::runtime_error("There is too little content in SPAN.");
	return *(std::max_element(_vec.begin(), _vec.end())) - *(std::min_element(_vec.begin(), _vec.end()));
}
