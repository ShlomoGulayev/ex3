#pragma once

using std::ostream;
using std::istream; 

class Rational
{
public:
	Rational(const int numerator = 0, const int denumenator = 1) ;
	Rational(const Rational& r);
	Rational& operator=(const Rational& r2);
	int get_numerator() const;
	int get_denumerator() const;
	void setRational(const int numerator, const int denumerator);

private:
	int m_numerator;
	int m_denumerator;
	void minimize();
};


Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
ostream& operator<<(ostream& os, const Rational& r);
istream& operator>>(istream& is, Rational& r);
Rational& operator+=(Rational& r1, const Rational& r2);
Rational& operator-=(Rational& r1, const Rational& r2);
Rational& operator/=(Rational& r1, const Rational& r2);
Rational& operator*=(Rational& r1, const Rational& r2);
Rational operator-(const Rational& r);
Rational operator+(const Rational& r);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator<(const Rational& r1, const Rational& r2);
Rational operator++(Rational& r, int);
Rational operator--(Rational& r, int);
