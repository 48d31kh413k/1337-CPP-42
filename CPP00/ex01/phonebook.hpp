#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class Phonebook
{
	public:
		Phonebook();
		int		add();
		int		select();
		int		display_phonebook();

	private:
		Contact	_contacts[8];
		int		_number;
};

#endif
