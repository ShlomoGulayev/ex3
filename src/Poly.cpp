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
unsigned int Poly::getSize() const
{
	return m_size;
}
//-----------------------------------------------------------------------------
int Poly::getPowerHead() const
{
	return m_list.getPowerHead();
}
//-----------------------------------------------------------------------------
 Rational Poly::getRational(const int power) const
{
	return m_list.getRational(power);
}
//-----------------------------------------------------------------------------
bool Poly::isPowerInList(const int index) const
{
	return m_list.isPowerInList(index);
}
//-----------------------------------------------------------------------------
bool Poly::isLastNode(const int power) const
{
	return m_list.isLastNode(power);
}
//-----------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Poly& poly)
{
	for (int i = poly.getPowerHead(); i >= -1; i--)
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
	if (p1.getPowerHead() == p2.getPowerHead())
		return true;
	return false;
}

//-----------------------------------------------------------------------------

bool operator!=(const Poly& p1, const Poly& p2)
{
	return !(p1 == p2);
}