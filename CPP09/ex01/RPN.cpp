#include "RPN.hpp"

/* Orthodox Canonical Form */
RPN::RPN(){}

RPN::RPN(const RPN& rhs) : _stk(rhs._stk) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this == &rhs)
		return *this;
	_stk = rhs._stk;
	return *this;
}

/* Function */
int	RPN::calcRPN(const std::string& strRPN)
{
	if (strRPN.size() > 100000)
		throw std::logic_error("Error: Too many input argv[1]");

	std::istringstream iss(strRPN);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
			processCharOperation(token);
		else
			processNum(token);
	}
	//here
	if (_stk.size() != 1)
		throw std::logic_error("Error: invalid argv[1]");
	return _stk.top();
}

void	RPN::processCharOperation(const std::string& token)
{
	if (_stk.size() < 2)
		throw std::logic_error("Error: bad operands for " + token);
	int operand2 = _stk.top(); _stk.pop();
	int operand1 = _stk.top(); _stk.pop();

	if (token == "+") _stk.push(operand1 + operand2);
	else if (token == "-") _stk.push(operand1 - operand2);
	else if (token == "*") _stk.push(operand1 * operand2);
	else if (token == "/")
	{
		if (operand2 == 0)
			throw std::logic_error("Error: division by zero");
		_stk.push(operand1 / operand2);
	}
}

void	RPN::processNum(const std::string& token)
{
	std::istringstream issToken(token);
	int num;
	if (issToken >> num)
	{
		if (num >= 10)
			throw std::logic_error("Error: over 9 => " + token);
		_stk.push(num);
	}
	else
		throw std::logic_error("Error: invalid token " + token);
}
