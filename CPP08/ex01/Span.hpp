#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm> //system maxelement minelenemt sort
#include <limits> //numeric limits


class Span
{
	private:
		std::vector<int>	_vec;
		unsigned int		_maxSize;
	public:
		Span();
		Span(unsigned int N);
		~Span();

		Span(const Span& rhs);
		Span& operator=(const Span& rhs);

		void	addNumber(int value);
		void	addNumber(int value, int num);
		int		shortestSpan();
		int		longestSpan();

};


#endif
