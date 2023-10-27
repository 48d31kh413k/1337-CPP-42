#ifndef __FIXED_HPP
#define __FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
   public:
    Fixed(void);
    Fixed(const int a);
    Fixed(const float b);
    Fixed(const Fixed& other);
    Fixed &operator=(const Fixed &other);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed& min(Fixed& c, Fixed& d);
		static Fixed& max(Fixed& c, Fixed& d);
		static const Fixed& min(const Fixed& c, const Fixed& d);
		static const Fixed& max(const Fixed& c, const Fixed& d);

   private:
    int             _fpvalue;
    static const int _nbfb = 8;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed& i);
#endif
