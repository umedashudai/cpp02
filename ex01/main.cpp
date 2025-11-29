/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:50:14 by shuu              #+#    #+#             */
/*   Updated: 2025/11/28 14:05:09 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    std::cout << "=== Subject Tests ===" << std::endl;
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "\n=== Additional Tests ===" << std::endl;

    std::cout << "\n--- Zero and Small Values ---" << std::endl;
    Fixed zero(0);
    Fixed small(0.00390625f);
    std::cout << "Zero: " << zero << " -> int: " << zero.toInt() << std::endl;
    std::cout << "Small (1/256): " << small << " -> int: " << small.toInt() << std::endl;

    std::cout << "\n--- Negative Values ---" << std::endl;
    Fixed negative(-42.42f);
    Fixed negInt(-100);
    std::cout << "Negative float: " << negative << " -> int: " << negative.toInt() << std::endl;
    std::cout << "Negative int: " << negInt << " -> int: " << negInt.toInt() << std::endl;

    std::cout << "\n--- Large Values ---" << std::endl;
    Fixed large(1000000);
    Fixed largeFloat(99999.99f);
    std::cout << "Large int: " << large << " -> int: " << large.toInt() << std::endl;
    std::cout << "Large float: " << largeFloat << " -> int: " << largeFloat.toInt() << std::endl;

    std::cout << "\n--- Fractional Parts ---" << std::endl;
    Fixed frac1(0.5f);
    Fixed frac2(0.25f);
    Fixed frac3(0.75f);
    Fixed frac4(1.99f);
    std::cout << "0.5: " << frac1 << " -> int: " << frac1.toInt() << std::endl;
    std::cout << "0.25: " << frac2 << " -> int: " << frac2.toInt() << std::endl;
    std::cout << "0.75: " << frac3 << " -> int: " << frac3.toInt() << std::endl;
    std::cout << "1.99: " << frac4 << " -> int: " << frac4.toInt() << std::endl;

    std::cout << "\n--- Copy and Assignment ---" << std::endl;
    Fixed original(123.456f);
    Fixed copied(original);
    Fixed assigned;
    assigned = original;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copied: " << copied << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    std::cout << "\n--- Edge Cases ---" << std::endl;
    Fixed minusOne(-1);
    Fixed justAboveZero(0.01f);
    Fixed justBelowZero(-0.01f);
    std::cout << "-1: " << minusOne << " -> int: " << minusOne.toInt() << std::endl;
    std::cout << "0.01: " << justAboveZero << " -> int: " << justAboveZero.toInt() << std::endl;
    std::cout << "-0.01: " << justBelowZero << " -> int: " << justBelowZero.toInt() << std::endl;

    std::cout << "\n--- Float Precision Test ---" << std::endl;
    Fixed pi(3.14159f);
    Fixed e(2.71828f);
    std::cout << "Pi: " << pi << " -> back to float: " << pi.toFloat() << std::endl;
    std::cout << "e: " << e << " -> back to float: " << e.toFloat() << std::endl;

    return 0;
}
