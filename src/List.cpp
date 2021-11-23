#include <iostream>
#include "List.h"

using std::cout;


//-----------------------------------------------------------------------------
//List constructor
Node::Node(const Rational r, const int power, Node* next)
	:m_rational(r), m_power(power), m_next(next)
{}
//-----------------------------------------------------------------------------
//List constructor
List::List()
	:m_head(nullptr), m_size(0)
{}
//-----------------------------------------------------------------------------
//insert a Rational value to the list
void List::insert(const Rational r, const int power)
{
	if (m_head == nullptr)
		m_head = new Node(r, power, nullptr);
	else
	{
		Node* tmp = m_head;
		while (tmp->m_next != nullptr)
		{
			tmp = tmp->m_next;
		}
		tmp->m_next = new Node(r, power, nullptr);
	}
	m_size++;
}
//-----------------------------------------------------------------------------
//List copy constructor
List::List(const List& other)
	:m_head(nullptr), m_size(0)
{
	Node* tmp = other.m_head;
	
	while (tmp != nullptr)
	{
		insert(tmp->m_rational, tmp->m_power);
		tmp = tmp->m_next;
	}
	
	m_size = other.m_size;
	
}
//-----------------------------------------------------------------------------
//get the size of the list
unsigned int List::getSize() const
{
	return m_size;
}
//-----------------------------------------------------------------------------
//checks if a given Power is in the List
bool List::isPowerInList(const int power) const
{
	Node* tmp = m_head;
	while (tmp != nullptr && tmp->m_power >= power)
	{
		if (tmp->m_power == power)
			return true;
		tmp = tmp->m_next;
	}
	return false;
}

//-----------------------------------------------------------------------------
//checks if a given Rational is in the List
bool List::isRationalInList(const Rational r) const
{
	Node* tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->m_rational == r)
			return true;
		tmp = tmp->m_next;
	}
	return false;
}
//-----------------------------------------------------------------------------
//returns the Rational of a given Power
Rational List::getRational(int power) const
{
	if (isPowerInList(power))
	{
		Node* tmp = m_head;
		while (tmp != nullptr)
		{
			if (power == tmp->m_power)
				return tmp->m_rational;
			tmp = tmp->m_next;
		}
	}
	return Rational();
}

//-----------------------------------------------------------------------------
//returns the Power of a given Rational
int List::getPower(Rational r) const
{
	Node* tmp = m_head;
	while (tmp != nullptr)
	{
		if (r == tmp->m_rational)
			return tmp->m_power;
		tmp = tmp->m_next;
	}
	return 0;
}

//-----------------------------------------------------------------------------
//returns the degree of the Poly
int List::getPowerHead() const
{
	return m_head->m_power;
}
//-----------------------------------------------------------------------------
//List destructor
List::~List()
{
	while (m_head != nullptr)
	{
		Node* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
}
//-----------------------------------------------------------------------------
//checks if a given Node is the last one
bool List::isLastNode(const int power) const
{
	Node* tmp = m_head;
	while (tmp!= nullptr && tmp->m_power >= power)
	{
		if (tmp->m_power == power && tmp->m_next == nullptr)
			return true;
		tmp = tmp->m_next;
	}
	return false;
}

