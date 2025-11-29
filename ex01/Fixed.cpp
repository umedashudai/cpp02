/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:31:03 by shuu              #+#    #+#             */
/*   Updated: 2025/11/27 22:19:03 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed(void): _value(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _frac_bits) {

    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _frac_bits)))) {

    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    
    std::cout << "Copy constructor called" << std::endl;
    if (&copy != this)
        *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    
    std::cout << "Copy assignment operator called" << std::endl;
    if (&copy != this)
        this->_value = copy.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {

    std::cout << "Destructor called" << std::endl;
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

    return this->_value >> this->_frac_bits;
}

std::ostream	&operator<<(std::ostream &str, const Fixed &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
