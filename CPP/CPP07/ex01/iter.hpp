#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename U>
void iter(T *a, std::size_t size, U f) {
	if (!a || !size || !f)
	{
		std::cout << "Error! Invalid argument" << std::endl;
		return ;
	}
	for (std::size_t i = 0; i < size; ++i) {
		f(a[i]);
	}
}

#endif
