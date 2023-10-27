#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {

	BitcoinExchange b;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <filename>"  << std::endl;
		return 1;
	}
	b.readDataCSV();
	b.readDataTXT(argv[1]);
	return 0;
}

