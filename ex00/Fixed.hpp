/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:13:25 by shuu              #+#    #+#             */
/*   Updated: 2025/11/27 22:18:00 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int _value;
        static const int  _frac_bits;
    public:
        Fixed(void);
        Fixed(const Fixed &copy);
        ~Fixed(void);
        Fixed   &operator=(const Fixed &copy);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
