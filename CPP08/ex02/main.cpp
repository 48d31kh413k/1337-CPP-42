#include "MutantStack.hpp"

int main() {

{
	std::cout << " MutantStack " << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "s.size: " << s.size() << std::endl;
	std::cout << "s.top : " << s.top() << std::endl;
}

	std::cout << " vector " << std::endl;
	std::vector<int> mvector;
	mvector.push_back(5);
	mvector.push_back(17);

	std::cout << mvector.back() << std::endl;

	mvector.pop_back();

	std::cout << mvector.size() << std::endl;

	mvector.push_back(3);
	mvector.push_back(5);
	mvector.push_back(737);
	//[...]
	mvector.push_back(0);

	std::vector<int>::iterator it = mvector.begin();
	std::vector<int>::iterator ite = mvector.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::vector<int> s(mvector);
	std::cout << "s.size: " << s.size() << std::endl;
	std::cout << "s.top : " << s.back() << std::endl;

	return 0;
}

