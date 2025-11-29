/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:50:14 by shuu              #+#    #+#             */
/*   Updated: 2025/11/28 15:06:51 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    std::cout << "=== Subject Tests ===" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "\n=== Additional Tests ===" << std::endl;

    std::cout << "\n--- Arithmetic Operators ---" << std::endl;
    Fixed x(10.5f);
    Fixed y(2.5f);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    std::cout << "\n--- Negative Arithmetic ---" << std::endl;
    Fixed neg1(-5.5f);
    Fixed neg2(-2.0f);
    std::cout << "neg1 = " << neg1 << ", neg2 = " << neg2 << std::endl;
    std::cout << "neg1 + neg2 = " << (neg1 + neg2) << std::endl;
    std::cout << "neg1 - neg2 = " << (neg1 - neg2) << std::endl;
    std::cout << "neg1 * neg2 = " << (neg1 * neg2) << std::endl;
    std::cout << "neg1 / neg2 = " << (neg1 / neg2) << std::endl;

    std::cout << "\n--- Comparison Operators ---" << std::endl;
    Fixed c1(42.42f);
    Fixed c2(42.42f);
    Fixed c3(10.5f);
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << std::endl;
    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << std::endl;
    std::cout << "c1 != c3: " << (c1 != c3 ? "true" : "false") << std::endl;
    std::cout << "c1 > c3: " << (c1 > c3 ? "true" : "false") << std::endl;
    std::cout << "c3 < c1: " << (c3 < c1 ? "true" : "false") << std::endl;
    std::cout << "c1 >= c2: " << (c1 >= c2 ? "true" : "false") << std::endl;
    std::cout << "c3 <= c1: " << (c3 <= c1 ? "true" : "false") << std::endl;

    std::cout << "\n--- Increment/Decrement Operators ---" << std::endl;
    Fixed inc(5.0f);
    std::cout << "Initial value: " << inc << std::endl;
    std::cout << "Pre-increment (++inc): " << ++inc << std::endl;
    std::cout << "After pre-increment: " << inc << std::endl;
    std::cout << "Post-increment (inc++): " << inc++ << std::endl;
    std::cout << "After post-increment: " << inc << std::endl;
    std::cout << "Pre-decrement (--inc): " << --inc << std::endl;
    std::cout << "After pre-decrement: " << inc << std::endl;
    std::cout << "Post-decrement (inc--): " << inc-- << std::endl;
    std::cout << "After post-decrement: " << inc << std::endl;

    std::cout << "\n--- Min/Max Functions ---" << std::endl;
    Fixed m1(100.5f);
    Fixed m2(50.25f);
    std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
    std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;
    std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;

    Fixed const cm1(100.5f);
    Fixed const cm2(50.25f);
    std::cout << "const max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;
    std::cout << "const min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;

    std::cout << "\n--- Edge Cases ---" << std::endl;
    Fixed zero(0);
    Fixed one(1);
    Fixed small(0.00390625f);
    std::cout << "zero = " << zero << std::endl;
    std::cout << "zero + one = " << (zero + one) << std::endl;
    std::cout << "zero * one = " << (zero * one) << std::endl;
    std::cout << "small * small = " << (small * small) << std::endl;
    std::cout << "one / small = " << (one / small) << std::endl;

    std::cout << "\n--- Chain Operations ---" << std::endl;
    Fixed v1(10.0f);
    Fixed v2(2.0f);
    Fixed v3(5.0f);
    std::cout << "v1 = " << v1 << ", v2 = " << v2 << ", v3 = " << v3 << std::endl;
    std::cout << "(v1 + v2) * v3 = " << ((v1 + v2) * v3) << std::endl;
    std::cout << "(v1 - v2) / v3 = " << ((v1 - v2) / v3) << std::endl;
    std::cout << "v1 * v2 + v3 = " << (v1 * v2 + v3) << std::endl;

    std::cout << "\n--- Assignment Chain ---" << std::endl;
    Fixed a1, a2, a3;
    a1 = a2 = a3 = Fixed(42.0f);
    std::cout << "a1 = " << a1 << ", a2 = " << a2 << ", a3 = " << a3 << std::endl;

    return 0;
}
