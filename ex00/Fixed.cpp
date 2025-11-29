/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:31:03 by shuu              #+#    #+#             */
/*   Updated: 2025/11/27 22:17:42 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed(void): _value(0) {

    std::cout << "Default constructor called" << std::endl;
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

    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(const int raw) {

    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}
