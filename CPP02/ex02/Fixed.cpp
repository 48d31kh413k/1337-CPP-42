#include "Fixed.hpp"

Fixed::Fixed(void) : _fpvalue(0) { }
Fixed::Fixed(const int a)  { 
    this->_fpvalue = a << Fixed::_nbfb;
}

Fixed::Fixed(const float b)  { 
    this->_fpvalue = roundf(b *(1 << Fixed::_nbfb));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
         _fpvalue = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(void) {  }

bool Fixed::operator>(const Fixed& other) const {
	return this->_fpvalue > other._fpvalue;
}

bool Fixed::operator<(const Fixed& other) const {
	return other > *this;
}

bool Fixed::operator>=(const Fixed& other) const {
	return !(other > *this);
}

bool Fixed::operator<=(const Fixed& other) const {
	return !(*this > other);
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_fpvalue == other._fpvalue;
}

bool Fixed::operator!=(const Fixed& other) const {
	return !(this->_fpvalue == other._fpvalue);
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed res;

	res._fpvalue = (this->_fpvalue + other._fpvalue);
	return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed res;

	res._fpvalue = (this->_fpvalue - other._fpvalue);
	return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed res(this->toFloat() * other.toFloat());
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed res(this->toFloat() / other.toFloat());
	return res;
}


Fixed& Fixed::operator++() {
	++(this->_fpvalue);
	return (*this);
}

Fixed& Fixed::operator--() {
	--(this->_fpvalue);
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed prev(*this);

	++(this->_fpvalue);
	return prev;
}

Fixed Fixed::operator--(int) {
	Fixed prev(*this);

	--(this->_fpvalue);
	return prev;
}

Fixed& Fixed::min(Fixed& c, Fixed& d) {
	if (c < d) return c;
	return d;
}

Fixed& Fixed::max(Fixed& c, Fixed& d) {
	if (c > d) return c;
	return d;
}

const Fixed& Fixed::min(const Fixed& c, const Fixed& d) {
	if (c < d) return c;
	return d;
}

const Fixed& Fixed::max(const Fixed& c, const Fixed& d) {
	if (c > d) return c;
	return d;
}
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