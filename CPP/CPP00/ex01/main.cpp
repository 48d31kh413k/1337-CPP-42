#include "main.hpp"

int		main(void)
{
	bool			working;
	Phonebook		phonebook;
	std::string		command;

	working = true;
	while (working)
	{
		std::cout << "Please enter a command. (ADD, SEARCH OR EXIT) : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (-1);
		if (!command.compare("ADD") && (phonebook.add()) < 0)
			break ;
		else if (!command.compare("SEARCH") && (phonebook.display_phonebook() < 0))
			break ;
		else if (!command.compare("EXIT"))
			working = false;
	}
	return (0);
}