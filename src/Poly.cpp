#include <iostream>

#include "Poly.h"

//-----------------------------------------------------------------------------
Poly::Poly()
{
	m_list.insert(Rational(0,1), -1);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
Poly::Poly(const Rational scalar)
{
	int power = (scalar == Rational(0, 1)) ? -1 : 0;
	m_list.insert(scalar, power);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
Poly::Poly(const Rational scalar, int power)
{
	power = (scalar == Rational(0, 1)) ? -1 : power;
	m_list.insert(scalar, power);
	m_size = m_list.getSize();
}
//-----------------------------------------------------------------------------
Poly::Poly(const std::vector<Rational>& vec)
{
	int power = vec.size()-1;
	for (int i = 0; i < vec.size() ; i++)
	{
		if (vec[i].get_numerator() != 0)
			m_list.insert(vec[i], power);
		power--;
	}
	m_size = vec.size();
}
//-----------------------------------------------------------------------------
Poly::Poly(const Poly& polynom)
	:m_list(polynom.m_list), m_size(polynom.m_size)
{}
//-----------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& polynom)
{
	if (this == &polynom)
		return *this;
	m_list.~List();

	for (int i = polynom.getDeg(); i >= -1; i--)
	{
		if (polynom.isPowerInList(i))
			m_list.insert(polynom.getRational(i), i);
	}
	m_size = polynom.m_size;
}
//-----------------------------------------------------------------------------
unsigned int Poly::getSize() const
{
	return m_size;
}
//-----------------------------------------------------------------------------
int Poly::getDeg() const
{
	return m_list.getPowerHead();
}
//-----------------------------------------------------------------------------
 Rational Poly::getRational(const int power) const
{
	return m_list.getRational(power);
}
//-----------------------------------------------------------------------------

int Poly::getPower(const Rational r) const
{
	return m_list.getPower(r);
}

//-----------------------------------------------------------------------------
bool Poly::isPowerInList(const int index) const
{
	return m_list.isPowerInList(index);
}

//-----------------------------------------------------------------------------
bool Poly::isRationalInList(const Rational r) const
{
	return m_list.isRationalInList(r);
}
//-----------------------------------------------------------------------------
bool Poly::isLastNode(const int power) const
{
	return m_list.isLastNode(power);
}
//-----------------------------------------------------------------------------
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

bool operator==(const Poly& p1, const Poly& p2)
{
	if (p1.getDeg() == p2.getDeg())
		return true;
	return false;
}

//-----------------------------------------------------------------------------

bool operator!=(const Poly& p1, const Poly& p2)
{
	return !(p1 == p2);
}

//-----------------------------------------------------------------------------

bool operator<(const Poly& p1, const Poly& p2)
{
	if (p1.getPowerHead() < p2.getPowerHead())
		return true;
	return false;
}

//-----------------------------------------------------------------------------

bool operator<=(const Poly& p1, const Poly& p2)
{
	if (p1 < p2 || p1 == p2)
		return true;
	return false;
}

//-----------------------------------------------------------------------------

bool operator>(const Poly& p1, const Poly& p2)
{
	if (!(p1 <= p2))
		return true;
	return false;
}

//-----------------------------------------------------------------------------

bool operator>=(const Poly& p1, const Poly& p2)
{
	if (!(p1 < p2))
		return true;
	return false;
}

//-----------------------------------------------------------------------------

Rational Poly::operator[](int power)
{
	if (m_list.isPowerInList(power))
	{
		return m_list.getRational(power);
	}
	return Rational();
}

//-----------------------------------------------------------------------------

Rational Poly::operator()(Rational r)
{
	if (m_list.isRationalInList(r))
	{
		return m_list.getPower(r);
	}
	return 0;
}

//-----------------------------------------------------------------------------