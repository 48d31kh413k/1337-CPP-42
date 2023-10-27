#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	Animal* array[100];
	for (int i = 0; i < 100; ++i) {
		if (i < 50) array[i] = new Dog();
		else array[i] = new Cat();
	}
	for (int i = 0; i < 100; ++i) {
		delete array[i];
	}
	//system("leaks DeepCopy");
}
