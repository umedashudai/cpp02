/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:21:47 by shuu              #+#    #+#             */
/*   Updated: 2025/11/28 14:12:32 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int _value;
        static const int _frac_bits;
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &copy);
        ~Fixed(void);

        Fixed   &operator=(const Fixed &copy);
        Fixed   operator+(const Fixed &copy) const;
        Fixed   operator-(const Fixed &copy) const;
        Fixed	operator*(const Fixed &copy) const;
		Fixed	operator/(const Fixed &copy) const;
        bool    operator==(const Fixed &copy) const;
        bool	operator!=(const Fixed &copy) const;
		bool	operator<=(const Fixed &copy) const;
		bool	operator>=(const Fixed &copy) const;
		bool	operator<(const Fixed &copy) const;
		bool	operator>(const Fixed &copy) const;
        Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int value);
		Fixed	operator--(int value);

        static Fixed &min(Fixed &copy1, Fixed &copy2);
        static Fixed &max(Fixed &copy1, Fixed &copy2);
        static const Fixed	&min(const Fixed &copy1, const Fixed &copy2);
		static const Fixed	&max(const Fixed &copy1, const Fixed &copy2);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
