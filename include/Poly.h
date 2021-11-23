#pragma once
#include <vector>
#include "List.h"
#include "Rational.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::nothrow;

class Poly
{
public:
	Poly();
	Poly(const std::vector<Rational>&);
	Poly(const Rational& scalar);
	Poly(const Rational& scalar, const int power);
	Poly(const Poly& polynom);
	Poly& operator=(const Poly& polinom);
	Rational operator[](const int power) const;
	Rational& operator()(const Rational& r);
	
	int getDeg() const;
	Rational getRational(const int power) const;
	bool isPowerInList(const int power) const;
	bool isLastNode(const int power) const;
	unsigned int getSize() const;
	~Poly();
private:
	List m_list;
	unsigned int m_size;
};

ostream& operator<<(ostream& os, const Poly& poly);
bool operator==(const Poly& p1, const Poly& p2);
bool operator!=(const Poly& p1, const Poly& p2);
bool operator<(const Poly& p1, const Poly& p2);
bool operator<=(const Poly& p1, const Poly& p2);
bool operator>(const Poly& p1, const Poly& p2);
bool operator>=(const Poly& p1, const Poly& p2);
Poly operator+(const Poly& poly1, const Poly& poly2);
Poly operator-(const Poly& poly1, const Poly& poly2);
Poly operator*(const Poly& poly1, const Poly& poly2);
Poly operator*(const Poly& poly1, const int& scalar);
Poly operator*(const int& scalar, const Poly& poly1);
Poly& operator+=(Poly& poly1, const Poly& poly2);
Poly& operator-=(Poly& poly1, const Poly& poly2);
Poly& operator*=(Poly& poly1, const Poly& poly2);