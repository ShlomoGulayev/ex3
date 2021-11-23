#include <iostream>
#include "Rational.h"


//-----------------------------------------------------------------------------
//Rational constructor 
Rational::Rational(int numerator, int denumerator)
	:m_numerator(numerator), m_denumerator(denumerator)
{
	setRational(numerator, denumerator);
}
//-----------------------------------------------------------------------------
//Rational copy constructor 
Rational::Rational(const Rational& r)
	: m_numerator(r.get_numerator()), m_denumerator(r.get_denumerator())
{}
//-----------------------------------------------------------------------------
//operator = (r1 = r2)
Rational& Rational::operator=(const Rational& other)
{
	if (this == &other)
		return *this;
	m_numerator = other.get_numerator();
	m_denumerator = other.get_denumerator();
	return *this;
}
//-----------------------------------------------------------------------------
//returns the numerator
int Rational::get_numerator() const
{
	return m_numerator;
}
//-----------------------------------------------------------------------------
//returns the denumerator
int Rational::get_denumerator() const
{
	return m_denumerator;
}
//-----------------------------------------------------------------------------
//set Rational values (also changes numerator to be negative instead of denumerator
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
//finds the bigest divider and minimize the rational
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
//operator + (r1 + r2)
Rational operator+(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_denumerator() + 
			  r2.get_numerator() * r1.get_denumerator();
	int denumerator = r1.get_denumerator() * r2.get_denumerator();
	return Rational(numerator, denumerator);
}

//-----------------------------------------------------------------------------
//operator - (r1 - r2)
Rational operator-(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_denumerator() -
		r2.get_numerator() * r1.get_denumerator();
	int denumerator = r1.get_denumerator() * r2.get_denumerator();
	return Rational(numerator, denumerator);
}
//-----------------------------------------------------------------------------
//operator * (r1 * r2)
Rational operator*(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_numerator();
	int denumerator = r1.get_denumerator() * r2.get_denumerator();
	return Rational(numerator, denumerator);
}

//-----------------------------------------------------------------------------
//operator / (r1 / r2)
Rational operator/(const Rational& r1, const Rational& r2)
{
	int numerator = r1.get_numerator() * r2.get_denumerator();
	int denumerator = r1.get_denumerator() * r2.get_numerator();
	return Rational(numerator, denumerator);
}

//-----------------------------------------------------------------------------
//operator << (output)
ostream& operator<<(ostream& os, const Rational& r)
{
	os << r.get_numerator() << "/" << r.get_denumerator();
	return os;
}

//-----------------------------------------------------------------------------
//operator >> (input)
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
//operator += (r1 += r2)
Rational& operator+=(Rational &r1, const Rational& r2)
{
	return r1 = r1 + r2;
}

//-----------------------------------------------------------------------------
//operator -= (r1 -= r2)
Rational& operator-=(Rational& r1, const Rational& r2)
{
	return r1 = r1 - r2;
}

//-----------------------------------------------------------------------------
//operator /= (r1 /= r2)
Rational& operator/=(Rational& r1, const Rational& r2)
{
	return r1 = r1 / r2;
}

//-----------------------------------------------------------------------------
//operator *= (r1 *= r2)
Rational& operator*=(Rational& r1, const Rational& r2)
{
	return r1 = r1 * r2;
}

//-----------------------------------------------------------------------------
//operator - (r1-> -r1)
Rational operator-(const Rational& r)
{
	return Rational(-r.get_numerator(), r.get_denumerator());
}

//-----------------------------------------------------------------------------
//operator + (r1-> abs r2)
Rational operator+(const Rational& r)
{
	return Rational(abs(r.get_numerator()), r.get_denumerator());
}

//-----------------------------------------------------------------------------
//operator ++ (r1-> r1 + 1)
Rational operator++(Rational& r, int)
{
	Rational r1(1, 1);
	return r += r1;
}

//-----------------------------------------------------------------------------
//operator -- (r1-> r1 - 1)
Rational operator--(Rational& r, int)
{
	Rational r1(1, 1);
	return r -= r1;
}

//-----------------------------------------------------------------------------
//operator == (boolean check if r1 = r2)
bool operator==(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() ==
		   r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------
//operator != (boolean check if r1 != r2)
bool operator!=(const Rational& r1, const Rational& r2)
{
	return(!(r1 == r2));
}

//-----------------------------------------------------------------------------
//operator <= (boolean check if r1 <= r2)
bool operator<=(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() <=
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------
//operator >= (boolean check if r1 >= r2)
bool operator>=(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() >=
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------
//operator > (boolean check if r1 > r2)
bool operator>(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() >
		r2.get_numerator() / r2.get_denumerator());
}

//-----------------------------------------------------------------------------
//operator < (boolean check if r1 < r2)
bool operator < (const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() / r1.get_denumerator() <
		r2.get_numerator() / r2.get_denumerator());
}

