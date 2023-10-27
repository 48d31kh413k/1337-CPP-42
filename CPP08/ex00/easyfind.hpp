#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // for std::find
#include <stdexcept> // for std::runtime_error


template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw std::runtime_error("Value not found");
	}

	return it;
}

#endif
