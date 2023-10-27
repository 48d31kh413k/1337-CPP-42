#include "whatever.hpp"
#include <iostream>


int main()
{
    int a = 5;
    int b = 10;

    std::cout << "Before Swap a = " << a << " b = " << b << std::endl;
    swap(a,b);
    std::cout << "After Swap a = " << a << " b = " << b << std::endl;
    std::cout << "MIN = "  << min(a,b) << std::endl;
    std::cout << "MAX = " << max(a,b) << std::endl;
}