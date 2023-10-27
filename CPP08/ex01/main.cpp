#include "Span.hpp"

int main() {
	std::cout << " Single Set Test "<< std::endl;

	Span sp1 = Span(5);
	try
	{
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		std::cout << "shortestSpan: " << sp1.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp1.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "  Multi Set Test " << std::endl;

	Span sp2 = Span(10002);
	try
	{
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(100, 10000);

		std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp2.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << " (Error) Over Size Test " << std::endl;

	Span sp3 = Span(10002);
	try
	{
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(100, 10000);
		sp3.addNumber(1);

		std::cout << "shortestSpan: " << sp3.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp3.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << " (Error) Too Little Size Test " << std::endl;

	Span sp4 = Span(2);
	try
	{
		sp4.addNumber(1);

		std::cout << "shortestSpan: " << sp4.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp4.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

