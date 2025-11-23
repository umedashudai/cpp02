/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:50:14 by shuu              #+#    #+#             */
/*   Updated: 2025/11/23 15:23:20 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    
    {
        Fixed f1(2);
		Fixed f2(8);

		std::cout << "" << std::endl;

		std::cout << "f1: " << f1 << std::endl;
		std::cout << "f2: " << f2 << std::endl;
		std::cout << "-- Min --" << std::endl;
		std::cout << Fixed::min(f1, f2) << std::endl;
		std::cout << "-- Max --" << std::endl;
		std::cout << Fixed::max(f1, f2) << std::endl;

		if (f1 < f2)
			std::cout << "< test passed" << std::endl;
		if (f1 <= f2)
			std::cout << "<= test passed" << std::endl;
		if (!(f1 > f2))
			std::cout << "> test passed" << std::endl;
		if (!(f1 >= f2))
			std::cout << ">= test passed" << std::endl;
		if (!(f1 == f2))
			std::cout << "== test passed" << std::endl;
		if (f1 != f2)
			std::cout << "!= test passed" << std::endl;

		std::cout << "" << std::endl;
		Fixed f3 = f1 + f2;
		std::cout << "f3(f1 + f2): " << f3<< std::endl;
		f3 = f1 - f2;
		std::cout << "f3(f1 - f2): " << f3<< std::endl;
		f3 = f1 * f2;
		std::cout << "f3(f1 * f2): " << f3<< std::endl;
		f3 = f1 / f2;
		std::cout << "f3(f1 / f2): " << f3<< std::endl;

		f3++;
		std::cout << "increment f3: " << f3 << std::endl;
		f3--;
		std::cout << "decrement f3: " << f3 << std::endl;		
	}
	{
		std::cout << std::endl;
		std::cout << "basic tests --------------" << std::endl;
		Fixed a;
		Fixed c( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << "a   = " << a << std::endl;
		std::cout << "a++ = " << ++a << std::endl;
		std::cout << "a   = " << a << std::endl;
		std::cout << "a++ = " <<  a++ << std::endl;
		std::cout << std::endl;
		std::cout << "a        = " << a << std::endl;
		std::cout << "b(const) = " << b << std::endl;
		std::cout << "c        = " << b << std::endl;
		std::cout << "const max(a,b) =   " << Fixed::max(a,b) << std::endl;
		std::cout << "      max(a,c) =   " << Fixed::max(a,c) << std::endl;
	}
	return (0);
}
