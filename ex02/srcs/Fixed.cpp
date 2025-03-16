/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:35:22 by bsengeze          #+#    #+#             */
/*   Updated: 2025/03/16 14:32:07 by bsengeze         ###   ########.fr       */
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

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
  return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
  return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
  return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
  return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
  return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
  return this->value != other.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
  Fixed result;
  result.setRawBits(this->value + other.value);
  return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
  Fixed result;
  result.setRawBits(this->value - other.value);
  return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
  Fixed result;
  long temp = (long)this->value * (long)other.value;
  result.setRawBits((int)(temp >> fractionalBits));
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
  Fixed result;
  if (other.value == 0)
  {
    std::cerr << "Error: Division by zero" << std::endl;
    return result;
  }
  long temp = ((long)this->value << fractionalBits) / (long)other.value;
  result.setRawBits((int)temp);
  return result;
}

// Increment/Decrement operators
Fixed &Fixed::operator++()
{
  this->value++;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed temp(*this);
  ++(*this);
  return temp;
}

Fixed &Fixed::operator--()
{
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed temp(*this);
  --(*this);
  return temp;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
  return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
  return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
  return (a > b) ? a : b;
}
