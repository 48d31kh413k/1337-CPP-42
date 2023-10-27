#include "main.hpp"

Phonebook::Phonebook()
{
	_number = 0;
}


int		Phonebook::add()
{
	if (_number < 8)
	{
		if (_contacts[_number].fill(_number + 1) < 0)
			return (-1);
		_number++;
	}
	else
		std::cout << "Error! Memory is full." << std::endl;
	return (0);
}


int		Phonebook::select()
{
	int		flag;
	char	*index = new char[2];

	flag = 1;
	std::cout << "Please select an index : ";
	std::cin >> index;
	if (std::cin.eof())
	{
		delete []index;
		return (-1); 
	}
	for (size_t i = 0 ; i < strlen(index) ; i++)
	{
		if (isdigit(index[i]) == 0)
			flag = 0;
	}
	if (!flag || std::cin.fail() || atoi(index) > _number || atoi(index) <= 0)
	{
		std::cout << "Error: Invalid index value." << std::endl;
		delete []index;
		return (1);
	}
	_contacts[atoi(index) - 1].display_detail();
	delete []index;
	return (0);
}

int		Phonebook::display_phonebook()
{
	if (_number == 0)
		std::cout << "Error: Phonebook is empty." << std::endl;
	else
	{
		std::cout << "│     INDEX│FIRST NAME│ LAST NAME│  NICKNAME│" << std::endl;
		for (int i = 0 ; i < _number ; i++)
			_contacts[i].display_list();
		if (select() < 0)
			return (-1);
	}
	return (0);
}