#include "Harl.hpp"

void    Harl::debug()
{
    std::cout << "Expressing love for extra bacon in 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
}

void    Harl::info()
{
    std::cout << "Disbelief about extra bacon cost, not enough bacon in burger" << std::endl;
}

void    Harl::warning()
{    
    std::cout << "Request for free extra bacon, as a long-time customer" << std::endl;
}

void    Harl::error()
{
    std::cout << "Unacceptable, request to speak with manager immediately" << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*Function[4])() =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[4] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    for (size_t i = 0; i < sizeof(levels) / sizeof(levels[0]) ; i++)
    {
        if (levels[i] == level)
        {    
            (this->*Function[i])();
                return ;
        }
    }
}
