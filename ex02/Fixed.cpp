/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:08:29 by shuu              #+#    #+#             */
/*   Updated: 2025/11/28 14:14:34 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed(void): _value(0) {}

Fixed::Fixed(const int value) : _value(value << _frac_bits) {}

Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _frac_bits)))) {}

Fixed::Fixed(const Fixed &copy) {
    
    if (&copy != this)
        *this = copy;
}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &copy) {

    if (&copy != this)
        this->_value = copy.getRawBits();
    return *this;
}

Fixed  Fixed::operator+(const Fixed &copy) const {
    
    return Fixed(this->toFloat() + copy.toFloat());
}

Fixed   Fixed::operator-(const Fixed &copy) const {

    return Fixed(this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator*(const Fixed &copy) const {

    return Fixed(this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed &copy) const {

    return Fixed(this->toFloat() / copy.toFloat());
}

bool    Fixed::operator==(const Fixed &copy) const {

    return this->toFloat() == copy.toFloat(); 
}

bool	Fixed::operator!=(const Fixed &copy) const {

    return this->toFloat() != copy.toFloat();
}

bool	Fixed::operator<=(const Fixed &copy) const {

    return this->toFloat() <= copy.toFloat();
}

bool	Fixed::operator>=(const Fixed &copy) const {

    return this->toFloat() >= copy.toFloat();
}

bool	Fixed::operator<(const Fixed &copy) const {

    return this->toFloat() < copy.toFloat();
}

bool	Fixed::operator>(const Fixed &copy) const {

    return this->toFloat() > copy.toFloat();
}

Fixed	&Fixed::operator++(void) {

    this->_value += 1;
    return *this;
}

Fixed	&Fixed::operator--(void) {

    this->_value -= 1;
    return *this;
}

Fixed	Fixed::operator++(int) {

    Fixed tmp = *this;

    ++(*this);
    return tmp;
}

Fixed	Fixed::operator--(int) {

    Fixed tmp = *this;

    --(*this);
    return tmp;
}

Fixed &Fixed::min(Fixed &copy1, Fixed &copy2) {

	if (copy1 < copy2)
		return copy1;
	return copy2;
}

Fixed &Fixed::max(Fixed &copy1, Fixed &copy2) {

	if (copy1 > copy2)
		return copy1;
	return copy2;
}

const Fixed	&Fixed::min(const Fixed &copy1, const Fixed &copy2) {
    
    if (copy1 < copy2)
		return (copy1);
	return (copy2);
}

const Fixed	&Fixed::max(const Fixed &copy1, const Fixed &copy2) {

    if (copy1 > copy2)
		return (copy1);
	return (copy2);
}

int Fixed::getRawBits(void) const {

    return this->_value;
}

void Fixed::setRawBits(const int raw) {

    this->_value = raw;
}

float	Fixed::toFloat(void) const {

    return static_cast<float>(this->_value / static_cast<float>(1 << this->_frac_bits));
}

int		Fixed::toInt(void) const {

    return static_cast<int>(this->toFloat());
}

std::ostream	&operator<<(std::ostream &str, const Fixed &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
