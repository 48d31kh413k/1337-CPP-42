#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
private:
    std::string _in;
    std::string _out;

public:
    Sed();
    ~Sed();

    static int  replace(std::string filename,std::string s1, std::string s2);
};

#endif 