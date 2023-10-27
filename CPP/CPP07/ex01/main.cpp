#include "iter.hpp"

template<typename T>
void print(T a) {
	std::cout << a << std::endl;
	return ;
}

int main(void) {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string aray[5] = {"Benguerir", "Khouribga", "MED", "1337", "42",};
	iter(array, 10, print<int>);
	iter(aray, 5, print<std::string>);
}