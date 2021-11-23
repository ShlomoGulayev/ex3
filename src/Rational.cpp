#include <iostream>
#include "Rational.h"


//-----------------------------------------------------------------------------
Rational::Rational(int numerator, int denumerator)
	:m_numerator(numerator), m_denumerator(denumerator)
{
	setRational(numerator, denumerator);
}
//-----------------------------------------------------------------------------
Rational::Rational(const Rational& r)
	: m_numerator(r.get_numerator()), m_denumerator(r.get_denumerator())
{}
//-----------------------------------------------------------------------------
Rational& Rational::operator=(const Rational& other)
{
	if (this == &other)
		return *this;
	m_numerator = other.get_numerator();
	m_denumerator = other.get_denumerator();
	return *this;
}
//-----------------------------------------------------------------------------
int Rational::get_numerator() const
{
	return m_numerator;
}

//-----------------------------------------------------------------------------
int Rational::get_denumerator() const
{
	return m_denumerator;
}
//-----------------------------------------------------------------------------
void Rational::setRational(int numerator, int denumerator)
{
	if ((numerator > 0 && denumerator < 0) ||
		(numerator < 0 && denumerator < 0))
	{
		numerator *= -1;
		denumerator *= -1;
	}

	m_numerator  = (denumerator == 0) ? 0 : numerator;
	m_denumerator  = (denumerator == 0) ? 1 : denumerator;
	minimize();
}
//-----------------------------------------------------------------------------
void Rational::minimize()
{
	int smaller = (abs(m_numerator) < abs(m_denumerator)) ? m_numerator : m_denumerator;
	while (smaller > 1)
	{
		if (m_numerator % smaller == 0 && m_denumerator % smaller == 0)
		{
			m_numerator/= smaller;
			m_denumerator/= smaller;
			break;
		}
		smaller--;
	}
}
//-----------------------------------------------------------------------------

Rational operator+(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_denumerator() + 
			  r2.get_numerator() * r1.get_denumerator();
	int denumerator = r1.get_denumerator() * r2.get_denumerator();
	return Rational(numerator, denumerator);
}

//-----------------------------------------------------------------------------
Rational operator-(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_denumerator() -
		r2.get_numerator() * r1.get_denumerator();
	int denumerator = r1.get_denumerator() * r2.get_denumerator();
	return Rational(numerator, denumerator);
}
//-----------------------------------------------------------------------------

Rational operator*(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_numerator();
	int denumerator = r1.get_denumerator() * r2.get_denumerator();
	return Rational(numerator, denumerator);
}

//-----------------------------------------------------------------------------

Rational operator/(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_denumerator();
	int denumerator = r1.get_denumerator() * r2.get_numerator();
	return Rational(numerator, denumerator);
}

//-----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Rational& r)
{
	os << r.get_numerator() << "/" << r.get_denumerator();
	return os;
}

//-----------------------------------------------------------------------------

istream& operator>>(istream& is, Rational& r)
{
	int numerator, denumerator;
	is >> numerator;
	is.ignore(1);
	is >> denumerator;
	r.setRational(numerator, denumerator);
	return is;
}

//-----------------------------------------------------------------------------

Rational& operator+=(Rational &r1, const Rational& r2)
{
	return r1 = r1 + r2;
}

//-----------------------------------------------------------------------------

Rational& operator-=(Rational& r1, const Rational& r2)
{
	return r1 = r1 - r2;
}

//-----------------------------------------------------------------------------

Rational& operator/=(Rational& r1, const Rational& r2)
{
	return r1 = r1 / r2;
}

//-----------------------------------------------------------------------------

Rational& operator*=(Rational& r1, const Rational& r2)
{
	return r1 = r1 * r2;
}

//-----------------------------------------------------------------------------

Rational operator-(const Rational& r)
{
	return Rational(-r.get_numerator(), r.get_denumerator());
}

//-----------------------------------------------------------------------------

Rational operator+(const Rational& r)
{
	return Rational(abs(r.get_numerator()), r.get_denumerator());
}

//-----------------------------------------------------------------------------

Rational operator++(Rational& r, int)
{
	Rational r1(1, 1);
	return r += r1;
}

//-----------------------------------------------------------------------------

Rational operator--(Rational& r, int)
{
	Rational r1(1, 1);
	return r -= r1;
}

//-----------------------------------------------------------------------------

bool operator==(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() ==
		   r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator!=(const Rational& r1, const Rational& r2)
{
	return(!(r1 == r2));
}

//-----------------------------------------------------------------------------

bool operator<=(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() <=
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator>=(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() >=
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator>(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() >
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------

bool operator < (const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() <
		r2.get_numerator() / r2.get_denumerator());
}

