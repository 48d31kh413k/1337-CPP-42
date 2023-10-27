#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <algorithm>
#include <vector>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	typedef typename Container::iterator iterator;

	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack& rhs) : std::stack<T, Container>(rhs) {}
	~MutantStack() {}

	MutantStack& operator=(const MutantStack& rhs) {
		std::stack<T, Container>::operator=(rhs);
		return *this;
	}

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}
};


#endif
