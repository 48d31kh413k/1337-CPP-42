#include "ScalarConverter.hpp"


int main(int argc, char **argv) {

	ScalarConverter *a = new ScalarConverter;
	if (argc != 2) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
	a->convert(argv[1]);
}