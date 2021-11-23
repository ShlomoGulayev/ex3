#include <iostream>

#include "Poly.h"

//-----------------------------------------------------------------------------
//Poly constructor
Poly::Poly()
{
	m_list.insert(Rational(), -1);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
<<<<<<< HEAD
//Poly constructor
Poly::Poly(const Rational scalar)
=======
Poly::Poly(const Rational& scalar)
>>>>>>> 673013b522efc255a2a211ec246c8bb3802a0d71
{
	int power = (scalar == Rational()) ? -1 : 0;
	m_list.insert(scalar, power);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
<<<<<<< HEAD
//Poly constructor
Poly::Poly(const Rational scalar, int power)
=======
Poly::Poly(const Rational& scalar, const int power)
>>>>>>> 673013b522efc255a2a211ec246c8bb3802a0d71
{
	m_list.insert(scalar, power);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
//Poly constructor
Poly::Poly(const std::vector<Rational>& vec)
{
	int power = vec.size() - 1;
	for (int i = 0; i < vec.size() ; i++)
	{
		if (vec[i].get_numerator() != 0)
			m_list.insert(vec[i], power);
		power--;
	}
	if (m_list.getSize() == 0)
		m_list.insert(0, -1);
	m_size = vec.size();
}
//-----------------------------------------------------------------------------
//Poly constructor
Poly::Poly(const Poly& polynom)
	:m_list(polynom.m_list), m_size(polynom.m_size)
{}
//-----------------------------------------------------------------------------
//operator - (p1 = p2)
Poly& Poly::operator=(const Poly& polynom)
{
	if (this == &polynom)
		return *this;
	m_list.~List();

	for (int i = polynom.getDeg(); i >= -1; i--)
	{
		if (polynom.isPowerInList(i))
			m_list.insert(polynom[i], i);
	}
	m_size = polynom.m_size;
	return *this;
}
//-----------------------------------------------------------------------------
//returns the size of the lists
unsigned int Poly::getSize() const
{
	return m_size;
}
//-----------------------------------------------------------------------------
//returns the degree of the Poly
int Poly::getDeg() const
{
	return m_list.getPowerHead();
}
//-----------------------------------------------------------------------------
//returns the Rational of a given Power
 Rational Poly::getRational(const int power) const
{
	return m_list.getRational(power);
}
//-----------------------------------------------------------------------------
<<<<<<< HEAD
 //returns the Power of a given Rational
int Poly::getPower(const Rational r) const
{
	return m_list.getPower(r);
}

//-----------------------------------------------------------------------------
//checks if a given Power is in the List
bool Poly::isPowerInList(const int index) const
{
	return m_list.isPowerInList(index);
}

//-----------------------------------------------------------------------------
//checks if a given Rational is in the List
bool Poly::isRationalInList(const Rational r) const
{
	return m_list.isRationalInList(r);
=======
bool Poly::isPowerInList(const int power) const
{
	return m_list.isPowerInList(power);
>>>>>>> 673013b522efc255a2a211ec246c8bb3802a0d71
}
//-----------------------------------------------------------------------------
//checks if a Node of a given Power is the last
bool Poly::isLastNode(const int power) const
{
	return m_list.isLastNode(power);
}
//-----------------------------------------------------------------------------
//operator << (output)
ostream& operator<<(ostream& os, const Poly& poly)
{
	for (int i = poly.getDeg(); i >= -1; i--)
	{
		if (poly.isPowerInList(i))
		{
			if (i <= 0)
				os << poly.getRational(i);
			else if (poly.isLastNode(i))
				os <<poly.getRational(i) << "X^" << i;
			else
				os << poly.getRational(i) << "X^" << i << " + ";
		}
	}
	return os;
}

//-----------------------------------------------------------------------------
//operator == (boolean check if p1 = p2)
bool operator==(const Poly& p1, const Poly& p2)
{
	if (p1.getDeg() == p2.getDeg())
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//operator != (boolean check if p1 != p2)
bool operator!=(const Poly& p1, const Poly& p2)
{
	return !(p1 == p2);
}

//-----------------------------------------------------------------------------
//operator < (boolean check if p1 degree < p2 degree)
bool operator<(const Poly& p1, const Poly& p2)
{
	if (p1.getDeg() < p2.getDeg())
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//operator <= (boolean check if p1 degree <= p2 degree)
bool operator<=(const Poly& p1, const Poly& p2)
{
	if (p1 < p2 || p1 == p2)
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//operator > (boolean check if p1 degree > p2 degree)
bool operator>(const Poly& p1, const Poly& p2)
{
	if (!(p1 <= p2))
		return true;
	return false;
}

//-----------------------------------------------------------------------------
//operator >= (boolean check if p1 degree >= p2 degree)
bool operator>=(const Poly& p1, const Poly& p2)
{
	if (!(p1 < p2))
		return true;
	return false;
}

//-----------------------------------------------------------------------------
<<<<<<< HEAD
//operator [] (returns the Rational of a given Power)
Rational Poly::operator[](int power)
=======

Rational Poly::operator[](const int power) const
>>>>>>> 673013b522efc255a2a211ec246c8bb3802a0d71
{
	if (m_list.isPowerInList(power))
	{
		return m_list.getRational(power);
	}
	return Rational();
}

<<<<<<< HEAD
//-----------------------------------------------------------------------------
=======
//-----------------------------------------------------------------------------

Rational& Poly::operator()(const Rational& r)
{
	int degree = m_list.getPowerHead();
	Rational sum;
	while (degree >= 0)
	{
		if (m_list.isPowerInList(degree))
		{
			Rational r_power = r;
			for (int i = 0; i < degree - 1; i++)
			{
				r_power*=r;
			}
			if (degree == 0)
				sum += m_list.getRational(degree);
			else
				sum += m_list.getRational(degree) * r_power;
		}
		degree--;
	}
	return sum;
}

//-----------------------------------------------------------------------------
Poly operator+(const Poly& poly1, const Poly& poly2)
{
	std::vector<Rational> vec;
	int degree = (poly1.getDeg() > poly2.getDeg()) ? poly1.getDeg() : poly2.getDeg();
	while (degree >= 0)
	{
		if (poly1.isPowerInList(degree) && poly2.isPowerInList(degree))
		{
			Rational r = poly1[degree] + poly2[degree];
			vec.push_back(r);
		}
		else if (poly1.isPowerInList(degree))
			vec.push_back(poly1[degree]);
		else if (poly2.isPowerInList(degree))
			vec.push_back(poly2[degree]);
		else 
			vec.push_back(Rational());
		degree--;
	}
	return Poly(vec);
}
//-----------------------------------------------------------------------------
Poly operator-(const Poly& poly1, const Poly& poly2)
{
	Poly tmp(poly2 * -1);
	return poly1 + tmp;
}

//-----------------------------------------------------------------------------
Poly operator*(const Poly& poly1, const Poly& poly2)
{
	int biggest_degree = poly1.getDeg() + poly2.getDeg();
	int degree_1 = poly1.getDeg();
	std::vector<Rational> vec;
	vec.resize(biggest_degree+1);
	
	while (degree_1 >= 0)
	{
		if (poly1.isPowerInList(degree_1))
		{
			int degree_2 = poly2.getDeg();
			while (degree_2 >= 0)
			{
				if (poly2.isPowerInList(degree_2))
				{
					int index = biggest_degree - (degree_1 + degree_2);
					vec[index] += poly1[degree_1] * poly2[degree_2];
				}
				degree_2--;
			}
		}
		degree_1--;
	}
	return Poly(vec);
}
//-----------------------------------------------------------------------------
Poly operator*(const Poly& poly1, const int& scalar)
{
	Poly poly2(scalar);
	return poly1 * poly2;
}
//-----------------------------------------------------------------------------
Poly operator*(const int& scalar, const Poly& poly1)
{
	Poly poly2(scalar);
	return poly1 * poly2;
}
//-----------------------------------------------------------------------------
Poly& operator+=(Poly& poly1, const Poly& poly2)
{
	return poly1 = poly1 + poly2;
}
//-----------------------------------------------------------------------------
Poly& operator-=(Poly& poly1, const Poly& poly2)
{
	return poly1 = poly1 - poly2;
}
//-----------------------------------------------------------------------------
Poly& operator*=(Poly& poly1, const Poly& poly2)
{
	return poly1 = poly1 * poly2;
}
>>>>>>> 673013b522efc255a2a211ec246c8bb3802a0d71
