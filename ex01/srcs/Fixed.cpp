/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:35:22 by bsengeze          #+#    #+#             */
/*   Updated: 2025/03/13 13:08:32 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
  std::cout << "Int constructor called" << std::endl;
  value = integer << fractionalBits;
}

Fixed::Fixed(const float floatingPoint)
{
  std::cout << "Float constructor called" << std::endl;
  value = roundf(floatingPoint * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
  {
    this->value = other.value;
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return value; }

void Fixed::setRawBits(int const raw) { value = raw; }

float Fixed::toFloat(void) const
{
  return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const { return value >> fractionalBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
  os << fixed.toFloat();
  return os;
}
