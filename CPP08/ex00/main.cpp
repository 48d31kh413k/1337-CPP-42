#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>

template <typename T>
void	test(T& container)
{
	try
	{
		for (int i = 4; i <= 6; i++)
		{
			std::cout << "Search Value: " << i << " -> "<< std::flush;
			typename T::iterator it = easyfind(container, i);
			std::cout <<  "Found Value: " <<  *it <<  std::endl;
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cout <<  e.what() <<  std::endl;
	}
}

int main() {

	int myArray[] = {1, 2, 3, 4, 5};

	std::cout << "[ Vector ]" << std::endl;
	std::vector<int> myVector(myArray, myArray + sizeof(myArray) / sizeof(int));
	test(myVector);

	return 0;
}

