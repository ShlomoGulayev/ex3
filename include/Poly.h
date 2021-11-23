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
	Poly(const Rational scalar);
	Poly(const Rational scalar, int power);
	Poly(const Poly& polynom);
	Poly& operator=(const Poly& polinom);
	int getPowerHead() const;
	Rational getRational(const int power) const;
	bool isPowerInList(const int index) const;
	bool isLastNode(const int power) const;
	unsigned int getSize() const;

private:
	List m_list;
	unsigned int m_size;
};

ostream& operator<<(ostream& os, const Poly& poly);
bool operator==(const Poly& p1, const Poly& p2);
bool operator!=(const Poly& p1, const Poly& p2);

