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
//Poly constructor
Poly::Poly(const Rational& scalar)
{
	int power = (scalar == Rational()) ? -1 : 0;
	m_list.insert(scalar, power);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
//Poly constructor
Poly::Poly(const Rational& scalar, const int power)
{
	m_list.insert(scalar, power);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
//Poly constructor
Poly::Poly(const std::vector<Rational>& vec)
{
	int power = (int)vec.size() - 1;
	for (int i = 0; i < vec.size() ; i++)
	{
		if (vec[i].get_numerator() != 0)
			m_list.insert(vec[i], power);
		power--;
	}
	if (m_list.getSize() == 0)
		m_list.insert(0, -1);
	m_size =(unsigned int)vec.size();
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
void Poly::insert(const Rational& r, const int power)
{
	m_list.insert(r, power);
	m_size = m_list.getSize();
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
//returns if a given power is in the list
bool Poly::isPowerInList(const int power) const
{
	return m_list.isPowerInList(power);
}
//-----------------------------------------------------------------------------
//checks if a given Node is the last (using a Power)
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
//operator [] (returns a Rational of a given Power)
Rational Poly::operator[](const int power) const
{
	if (m_list.isPowerInList(power))
	{
		return m_list.getRational(power);
	}
	return Rational();
}

//-----------------------------------------------------------------------------
//operator () (calculates the result if we set X)
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
//operator + (p1 + p2)
Poly operator+(const Poly& poly1, const Poly& poly2)
{
	Poly tmp;
	int degree = (poly1.getDeg() > poly2.getDeg()) ? poly1.getDeg() : poly2.getDeg();
	while (degree >= 0)
	{
		if (poly1.isPowerInList(degree) && poly2.isPowerInList(degree))
		{
			Rational r = poly1[degree] + poly2[degree];
			if(r != 0)
				tmp.insert(r, degree);
		}
		else if (poly1.isPowerInList(degree))
			tmp.insert(poly1[degree], degree);
		else if (poly2.isPowerInList(degree))
			tmp.insert(poly2[degree], degree);
		degree--;
	}
	return tmp;
}
//-----------------------------------------------------------------------------
//operator - (p1 - p2)
Poly operator-(const Poly& poly1, const Poly& poly2)
{
	Poly tmp(poly2 * -1);
	return poly1 + tmp;
}

//-----------------------------------------------------------------------------
//operator * (p1 * p2)
Poly operator*(const Poly& poly1, const Poly& poly2)
{
	Poly tmp;
	int degree_1 = poly1.getDeg();
	
	while (degree_1 >= 0)
	{
		if (poly1.isPowerInList(degree_1))
		{
			int degree_2 = poly2.getDeg();
			while (degree_2 >= 0)
			{
				if (poly2.isPowerInList(degree_2))
				{
					Rational r = poly1[degree_1] * poly2[degree_2];
					if(r != 0)
						tmp.insert(r, degree_1 + degree_2);
				}
				degree_2--;
			}
		}
		degree_1--;
	}
	return tmp;
}
//-----------------------------------------------------------------------------
//operator * (p1 * Scalar)
Poly operator*(const Poly& poly1, const int& scalar)
{
	Poly poly2(scalar);
	return poly1 * poly2;
}
//-----------------------------------------------------------------------------
//operator * (Scalar + p1)
Poly operator*(const int& scalar, const Poly& poly1)
{
	Poly poly2(scalar);
	return poly1 * poly2;
}
//-----------------------------------------------------------------------------
//operator += (p1 += p2)
Poly& operator+=(Poly& poly1, const Poly& poly2)
{
	return poly1 = poly1 + poly2;
}
//-----------------------------------------------------------------------------
//operator -= (p1 -= p2)
Poly& operator-=(Poly& poly1, const Poly& poly2)
{
	return poly1 = poly1 - poly2;
}
//-----------------------------------------------------------------------------
//operator -= (p1 -= p2)
Poly& operator*=(Poly& poly1, const Poly& poly2)
{
	return poly1 = poly1 * poly2;
}