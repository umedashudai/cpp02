/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:31:03 by shuu              #+#    #+#             */
/*   Updated: 2025/11/23 15:21:35 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void): _value(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << this->_bits) {

    std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _bits)))) {

    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    
    std::cout << "Copy constructor called" << std::endl;
    if (*this != copy)
        *this = copy;
}

Fixed::~Fixed(void) {

    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    
    std::cout << "Copy assignment operator called" << std::endl;
    if (&copy != this)
        this->_value = copy.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed &copy) {

    return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &copy) {

    return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &copy) {

    return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) {

    return Fixed(this->toFloat() / copy.toFloat());
}

bool Fixed::operator==(const Fixed &copy) const {

    return this->toFloat() == copy.toFloat();
}

bool Fixed::operator!=(const Fixed &copy) const {

    return this->toFloat() != copy.toFloat();
}

bool Fixed::operator>(const Fixed &copy) const {

    return this->toFloat() > copy.toFloat();
}

bool Fixed::operator<(const Fixed &copy) const {

    return this->toFloat() < copy.toFloat();
}

bool Fixed::operator>=(const Fixed &copy) const {

    return this->toFloat() >= copy.toFloat();
}

bool Fixed::operator<=(const Fixed &copy) const {

    return this->toFloat() <= copy.toFloat();
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {

    if (f1 < f2)
        return f1;
    return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {

    if (f1 > f2)
        return f1;
    return f2;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {

    if (f1 < f2)
        return f1;
    return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {

    if (f1 > f2)
        return f1;
    return f2;
}

Fixed& Fixed::operator++(void) {

    this->_value += 1;
    return *this;
}

Fixed& Fixed::operator--(void) {

    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator++(int) {

    Fixed temp = *this;
    ++*this;
    return temp;
}

Fixed Fixed::operator--(int) {

    Fixed temp = *this;
    --*this;
    return temp;
}

int Fixed::getRawBits(void) const {

    return this->_value;
}

void Fixed::setRawBits(int const raw) {

    this->_value = raw;
}

float Fixed::toFloat(void) const {

    return static_cast<float>(this->_value) / static_cast<float>(1 << this->_bits);
}

int Fixed::toInt(void) const {

    return this->_value >> this->_bits;
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed) {

    out << fixed.toFloat();
    return out;
}
