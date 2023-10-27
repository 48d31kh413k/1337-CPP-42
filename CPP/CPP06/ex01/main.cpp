#include <stdint.h>
#include "Serializer.hpp"

int main() {
	Serializer *a;
	Data *d = new Data;
	uintptr_t ptr;
	Data *after;
	std::cout << "Data before:       " << d << std::endl;
	ptr = a->serialize(d);
	std::cout << "Data serialized:   " << ptr << std::endl;
	after = a->deserialize(ptr);
	std::cout << "Data deserialized: " << after << std::endl;

	delete d;
}
