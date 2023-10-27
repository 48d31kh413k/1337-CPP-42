#include "PmergeMe.hpp"

/* Orthodox Canonical Form */
PmergeMe::PmergeMe()
{
	// std::cout << "(PmergeMe) Default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	(void)rhs;
	// std::cout << "(PmergeMe) Copy Constructor called"  << std::endl;
}

PmergeMe::~PmergeMe()
{
	// std::cout << "(PmergeMe) Destructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	// std::cout << "(PmergeMe) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* Function */
bool	PmergeMe::isDuplicate(int num, int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == num)
			return true;
	}
	return false;
}

bool	PmergeMe::isNumber(char *arg)
{
	for (size_t j = 0; j < std::strlen(arg); ++j)
	{
		if (!std::isdigit(arg[j]))
			return true;
	}
	return false;
}

bool	PmergeMe::isValid(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " [num...]" << std::endl;
		return true;
	}
	int numbers[argc - 1];
	int count = 0;

	for (int i = 1; i < argc; ++i)
	{
		char *arg = argv[i];

		if (isNumber(arg))
		{
			std::cerr << "Error: Characters include." << std::endl;
			return true;
		}
		long num = std::atol(arg);
		if (num > INT_MAX || num < 0)
		{
			std::cerr << "only positive integer sequence as argument." << std::endl;
			return true;
		}
		if (isDuplicate(num, numbers, count))
		{
			std::cerr << "Error: There are duplicate numbers." << std::endl;
			return true;
		}
		numbers[count] = static_cast<int>(num);
		++count;
	}
	return false;
}

void	PmergeMe::mergeInsertionSort(std::vector<int>& arr)
{
	size_t n = arr.size();
	if (n <= 1) return;
	std::vector<int> larger, smaller;

	std::cout << "Array init = " << std::endl;
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;
	// Step 1 and Step 2: Pairing and finding larger and smaller elements
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			larger.push_back(std::max(arr[i], arr[i + 1]));
			smaller.push_back(std::min(arr[i], arr[i + 1]));
		} else
			larger.push_back(arr[i]);
	}
	std::cout << "smaller = " << std::endl;
	for (size_t i = 0; i < smaller.size(); i++)
	{
		std::cout <<smaller[i] << ",";
	}
	std::cout << std::endl;
	std::cout << "larger = " << std::endl;
	for (size_t i = 0; i < larger.size(); i++)
	{
		std::cout <<larger[i] << ",";
	}
	std::cout << std::endl;

	// Step 3: Recursively sort the larger elements
	mergeInsertionSort(larger);
	std::cout << "      " << std::endl;
	
	// Step 4: Find the corresponding smaller element for the smallest larger element
	int smallestLarger = larger[0];
	int correspondingSmaller = -1;
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			if (arr[i] == smallestLarger || arr[i + 1] == smallestLarger)
			{
				correspondingSmaller = std::min(arr[i], arr[i + 1]);
				break;
			}
		}
	}
	std::cout << smallestLarger << " s = " << correspondingSmaller << std::endl;
	std::cout << "Array before = " << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;
	arr.clear();
	arr = larger;
	std::cout << "Array after = " << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;
	if (correspondingSmaller != -1)
		arr.insert(arr.begin(), correspondingSmaller);
	std::cout << "Array 2 = " << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;
	std::cout << "smaller 2 = " << std::endl;
	for (size_t i = 0; i < smaller.size(); i++)
	{
		std::cout <<smaller[i] << ",";
	}
	std::cout << std::endl;
	// Step 5: Insert the remaining smaller elements
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		if (smaller[i] != correspondingSmaller)
		{
			std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), smaller[i]);
			arr.insert(it, smaller[i]);
		}
	}
	std::cout << "Array 3 = " << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;
}

void	PmergeMe::mergeInsertionSort(std::list<int>& arr)
{
	size_t n = arr.size();
	if (n <= 1) return;

	std::list<int> larger, smaller;

	// Step 1 and Step 2: Pairing and finding larger and smaller elements
	std::list<int>::iterator it = arr.begin();
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			int first = *it++;
			int second = *it++;
			larger.push_back(std::max(first, second));
			smaller.push_back(std::min(first, second));
		} else
			larger.push_back(*it++);
	}

	// Step 3: Recursively sort the larger elements
	mergeInsertionSort(larger);

	// Step 4: Find the corresponding smaller element for the smallest larger element
	int smallestLarger = larger.front();
	int correspondingSmaller = -1;
	it = arr.begin();
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			int first = *it++;
			int second = *it++;
			if (first == smallestLarger || second == smallestLarger)
			{
				correspondingSmaller = std::min(first, second);
				break;
			}
		}
	}

	arr.clear();
	arr = larger;

	if (correspondingSmaller != -1)
		arr.push_front(correspondingSmaller);

	// Step 5: Insert the remaining smaller elements
	for (std::list<int>::iterator it = smaller.begin(); it != smaller.end(); ++it)
	{
		if (*it != correspondingSmaller)
		{
			std::list<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), *it);
			arr.insert(pos, *it);
		}
	}
}

/*
test case
./PmergeMe 9 3 7 4 8 2 6 5
./PmergeMe 8 1 6 3 7 2 5 4
./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " " `

*/

