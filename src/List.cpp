#include <iostream>
#include "List.h"

using std::cout;


//-----------------------------------------------------------------------------
Node::Node(const Rational r, const int power, Node* next)
	:m_rational(r), m_power(power), m_next(next)
{}
//-----------------------------------------------------------------------------
List::List()
	:m_head(nullptr), m_size(0)
{}
//-----------------------------------------------------------------------------
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
unsigned int List::getSize() const
{
	return m_size;
}
//-----------------------------------------------------------------------------
bool List::isPowerInList(const int power) const
{
	Node* tmp = m_head;
	while (tmp != NULL && tmp->m_power >= power)
	{
		if (tmp->m_power == power)
			return true;
		tmp = tmp->m_next;
	}
	return false;
}
//-----------------------------------------------------------------------------
Rational List::getRational(int power) const
{
	Node* tmp = m_head;
	while (tmp != NULL)
	{
		if (power == tmp->m_power)
			return tmp->m_rational;
		tmp = tmp->m_next;
	}
}
//-----------------------------------------------------------------------------
int List::getPowerHead() const
{
	return m_head->m_power;
}
//-----------------------------------------------------------------------------
List::~List()
{
	while (m_head != NULL)
	{
		Node* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
}
//-----------------------------------------------------------------------------
bool List::isLastNode(const int power) const
{
	Node* tmp = m_head;
	while (tmp!= NULL && tmp->m_power >= power)
	{
		if (tmp->m_power == power && tmp->m_next == NULL)
			return true;
		tmp = tmp->m_next;
	}
	return false;
}

