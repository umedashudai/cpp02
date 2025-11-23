/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:13:25 by shuu              #+#    #+#             */
/*   Updated: 2025/11/22 17:20:32 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int _value;
        static int const _bits;
    public:
        Fixed(void);
        Fixed(Fixed const &copy);
        ~Fixed(void);
        Fixed   &operator=(Fixed const &copy) const;
        Fixed   operator+(Fixed const &copy) const;
        Fixed   operator-(Fixed const &copy) const;
        Fixed	operator*(Fixed const &copy) const;
		Fixed	operator/(Fixed const &copy) const;
        bool    operator==(Fixed const &copy) const;
        bool	operator!=(Fixed const &copy) const;
		bool	operator<=(Fixed const &copy) const;
		bool	operator>=(Fixed const &copy) const;
		bool	operator<(Fixed const &copy) const;
		bool	operator>(Fixed const &copy) const;
        Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int value);
		Fixed	operator--(int value);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif