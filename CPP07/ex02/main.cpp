#include "Array.hpp"

int main( void ) {
	Array<int> x;

	
	std::cout << "size of empty array = "<< x.size() << std::endl << std::endl;;
	Array<int> a(1);
	a[0] = 2;
	Array<int> b(a);
	b[0] = 3;
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	a[0] = 4;
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	std::cout << std::endl;
	Array<int> c;
	c = a;
	std::cout << a[0] << std::endl;
	std::cout << c[0] << std::endl;
	c[0] = 3;
	std::cout << a[0] << std::endl;
	std::cout << c[0] << std::endl;
	a[0] = 1;
	std::cout << a[0] << std::endl;
	std::cout << c[0] << std::endl;
	std::cout << std::endl;

	Array<int> d(5);
	std::cout << "size a: " << a.size() << std::endl;
	std::cout << "size d: " << d.size() << std::endl;
	std::cout << std::endl;
	const Array<int> e(7);
	//e[0] = 9;
	try {
		std::cout << c[3] << std::endl;
	}
	catch (std::exception &a) {
		std::cout << a.what() << std::endl;
	}
	try {
		std::cout << c[-1] << std::endl;
	}
	catch (std::exception &a) {
		std::cout << a.what() << std::endl;
	}
    return 0;
}
