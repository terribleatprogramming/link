#include "linklist.h"

//James Curley CSCI 301 section 01 /export/home/cs301/cs301193/project5
// user id: 

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>				
#include <cstring>
#include <algorithm>   
#include <assert.h>
#include "linklist.h"



//destructor
linklist::~linklist()
{
	Node* temp;

	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}
//insert a new node at the end of the list
void linklist::insert(Item& entry)
{
	Node *prev;

	//assert(!present(entry)));

	if (first == NULL || entry < first->data)
		first = get_node(entry, first, NULL);
	else
	{
		prev = first;
		while (prev->next != NULL && prev->next->data < entry)
			prev = prev->next;
		prev->next = get_node(entry, prev->next, NULL);
	}
}
//overload << to display list
std::ostream& operator << (std::ostream& out_s, const linklist& l)
{
	linklist::Node *cursor;

	out_s << "output: " << std::endl;

	for (cursor = l.first;
		cursor != NULL && cursor->next != NULL;
		cursor = cursor->next)
	{
		out_s << cursor->data;
	}
	if (cursor != NULL)
	{
		out_s << cursor->data;
	}
	out_s << std::endl;
	out_s << std::endl;

	return out_s;
}
//length of list function
size_t linklist::length() const
{
	Node *cursor;
	size_t count;

	count = 0;
	for (cursor = first; cursor != NULL; cursor = cursor->next)
		++count;
	return count;
}
bool linklist::present(const Item& target) const
{
	Node *cursor;

	for (cursor = first;
		cursor != NULL && cursor->data != target;
		cursor = cursor->next);   
	return (cursor != NULL);
}


//Private Get Node function
linklist::Node* linklist::get_node(Item& entry, Node* forward, Node* backward)
{
	Node *temp;

	temp = new Node;
	temp->data = entry;
	temp->next = forward;
	temp->back = backward;
	return temp;
}
void linklist::make_empty()
{
	Node* temp;

	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}



//This checks to see if the list is empty or not. true if empty false if stuff inside list
bool linklist::isempty()
{
	Node *p = first;
	Node *q = last;
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

linklist::Item linklist::kth(size_t k) const
{
	Node *cursor;
	size_t count;

	assert(1 <= k && k <= length());

	cursor = first;
	for (count = 1; count<k; ++count)
		cursor = cursor->next;
	return cursor->data;
}

linklist::linklist()
{
}

