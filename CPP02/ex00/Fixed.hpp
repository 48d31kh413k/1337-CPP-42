#ifndef __FIXED_HPP
#define __FIXED_HPP

#include <iostream>
#include <typeinfo>

class Fixed {
   public:
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);

   private:
    int             _fpvalue;
    static const int _nbfb = 8;
};

#endif
