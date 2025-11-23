/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:21:47 by shuu              #+#    #+#             */
/*   Updated: 2025/11/23 15:23:08 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int _value;
        static int const _bits;
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &copy);
        ~Fixed(void);
        Fixed   &operator=(const Fixed  &copy);
        Fixed operator+(const Fixed &copy);
        Fixed operator-(const Fixed &copy);
        Fixed operator*(const Fixed &copy);
        Fixed operator/(const Fixed &copy);
        bool operator==(const Fixed &copy) const;
        bool operator!=(const Fixed &copy) const;
        bool operator>(const Fixed &copy) const;
        bool operator<(const Fixed &copy) const;
        bool operator>=(const Fixed &copy) const;
        bool operator<=(const Fixed &copy) const;
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);
        static Fixed &min(Fixed &f1, Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
