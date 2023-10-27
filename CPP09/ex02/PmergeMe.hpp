#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <list>
#include <climits>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);

		bool	isDuplicate(int num, int arr[], int size);
		bool	isNumber(char *arg);
		bool	isValid(int argc, char *argv[]);
		void	mergeInsertionSort(std::vector<int>& arr);
		void	mergeInsertionSort(std::list<int>& arr);

};


#endif
