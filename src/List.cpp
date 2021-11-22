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
void List::insertFirst(const Rational r, const int power)
{
	m_head = new Node(r, power, m_head);
	m_size++;
}
//-----------------------------------------------------------------------------
List::List(const List& other)
{
	/*
	Node* tmp_head = other.m_head;
	bool first_time = true;
	Node* runner;
	while (tmp_head != nullptr)
	{
		Node* new_node = new Node(tmp_head->m_rational, tmp_head->m_power, nullptr);
		if (first_time)
		{
			runner = m_head;
		}
		runner = new_node;
		runner = runner->m_next;
		tmp_head = tmp_head->m_next;
	}
	m_size = other.m_size;
	*/
	
	Node* tmp = other.m_head;
	for (int i = 0; i < other.m_size; i++)
	{
		insertFirst(tmp->m_rational, tmp->m_power);
		tmp = tmp->m_next;
	}
	
	//flips the list
	Node *current = m_head, *next = nullptr, *prev = nullptr;
	while (current != nullptr)
	{
		next = current->m_next;
		current->m_next = prev;
		prev = current;
		current = next;
	}
	m_head = prev;
	
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

