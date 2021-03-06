#pragma once
#include "Rational.h"

struct Node
{
	Node(const Rational& r, int power, Node* next);
	Rational m_rational;
	int m_power;
	Node* m_next;
};

class List {
public:
	List();
	List(const List& other);
	void insert(const Rational& r, const int power);
	
	bool isPowerInList(const int power) const;
	Rational getRational(const int power) const;
	bool isLastNode(const int power) const;
	int getPowerHead() const;
	unsigned int getSize() const;
	~List();

private:
	Node* m_head;
	unsigned int m_size;
	
};
