#pragma once
#include "Rational.h"

struct Node
{
	Node(Rational r, int power, Node* next);
	Rational m_rational;
	int m_power;
	Node* m_next;
};

class List {
public:
	List();
	List(const List& other);
	void insert(const Rational r, const int power);
	
	bool isPowerInList(const int index) const;
	bool isRationalInList(const Rational r) const;
	Rational getRational(int power) const;
	bool isLastNode(const int power) const;
	int getPowerHead() const;
	int getPower(Rational r) const;
	
	unsigned int getSize() const;
	~List();
private:
	Node* m_head;
	unsigned int m_size;
	
};
