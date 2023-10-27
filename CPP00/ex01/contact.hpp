#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact
{
	public:
		Contact();
		int		fill(int index);
		void	display_list();
		void	display_detail();

	private:
		int				_index;
		std::string		_infos[5];
		std::string		_fields[5];
};

#endif