#include "Fixed.hpp"


Fixed::Fixed(void) : _fpvalue(0) { 
    std::cout << "Default constructor called"  << std::endl; 
}

Fixed::Fixed(const int a)  { 
    std::cout << "Int constructor called"  << std::endl; 
    this->_fpvalue = a << Fixed::_nbfb;
}

Fixed::Fixed(const float b)  { 
    std::cout << "Float constructor called"  << std::endl;
    this->_fpvalue = roundf(b *(1 << Fixed::_nbfb));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
         _fpvalue = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
    return (_fpvalue);
}

void Fixed::setRawBits(int const raw) {
    _fpvalue = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fpvalue / (1 << Fixed::_nbfb);
}

int Fixed::toInt(void) const {
    return this->_fpvalue >> Fixed::_nbfb;
}

std::ostream &operator<<(std::ostream &os, const Fixed& i) {
	os << i.toFloat();
	return os;
}