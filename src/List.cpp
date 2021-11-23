#include <iostream>
#include "List.h"

using std::cout;


//-----------------------------------------------------------------------------
//List constructor
Node::Node(const Rational& r, const int power, Node* next)
	:m_rational(r), m_power(power), m_next(next)
{}
//-----------------------------------------------------------------------------
//List constructor
List::List()
	:m_head(nullptr), m_size(0)
{}
//-----------------------------------------------------------------------------
//insert Nodes to the list
void List::insert(const Rational& r, const int power)
{
	if (m_head == nullptr) //if its the first Node
	{
		m_head = new Node(r, power, nullptr);
		m_size++;
	}
	else if(m_head->m_power == -1) //head was 0 and we add a new monom
	{
		Node* tmp = m_head;
		delete tmp;
		m_head = new Node(r, power, nullptr);
	}
	else if (isPowerInList(power)) //if the power is in list already
	{
		Node* tmp = m_head;
		while (tmp->m_power != power)
		{
			tmp = tmp->m_next;
		}
		tmp->m_rational += r;
	}
	else // if its a new power
	{
		Node* tmp = m_head, *prev = m_head;
		bool first_time = true;
		while (tmp->m_next != nullptr && tmp->m_power > power)
		{
			tmp = tmp->m_next;
			if (first_time)
				first_time = false;
			else
				prev = prev->m_next;
		}
		if(tmp->m_next == nullptr)
			tmp->m_next = new Node(r, power, nullptr);
		else
			prev->m_next = new Node(r, power, tmp->m_next);
		m_size++;
	}
	
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
//return the degree of the Poly
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

