#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
	srand(time(NULL));
	int i = rand() % 3;
	switch (i) {
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A;
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B;
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C;
		default:
			std::cout << "Unable to generate a new class" << std::endl;
			return NULL;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "Class pointer identified as -> A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "Class pointer identified as -> B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "Class pointer identified as -> C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "Class reference identified as -> A" << std::endl;
		(void)a;
		return ;
	}
	catch (...) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "Class reference identified as -> B" << std::endl;
		(void)b;
		return ;
	}
	catch (...) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "Class reference identified as -> C" << std::endl;
		(void)c;
		return ;
	}
	catch (...) {}
}

int main() {
	Base *instance;
	instance = generate();
	identify(instance);
	identify(*instance);
	return 0;
}
