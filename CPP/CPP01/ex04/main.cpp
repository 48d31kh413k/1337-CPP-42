#include "Sed.hpp"

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		return (1);
	}
	if (Sed::replace(av[1], av[2], av[3])) {
		return 1;
	}
	return 0;
}