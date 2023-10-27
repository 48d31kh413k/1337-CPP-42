#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stack>


class RPN
{
	private:
		std::stack<int> _stk;

	public:
		RPN();
		~RPN();

		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);

		int		calcRPN(const std::string& strRPN);
		void	processCharOperation(const std::string& token);
		void	processNum(const std::string& token);

};


#endif
