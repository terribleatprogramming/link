#pragma once
//James Curley CSCI 301 section 01

//File location /export/home/cs301/cs301193/project5
#pragma once
#ifndef  linklist_H
#define  linklist_H
#include <cstdlib>                        
#include <iostream> 
/*
linklist() { first = NULL; }
Post condition: default constructor of the ordered list

void insert(Item& entry);
Pre: takes in an item as the parameter
Post: inserts a new item into a linked list at the end

friend std::ostream& operator << (std::ostream& out_s, const  orderlist& l);
Post: Overloads the << operator, so that the linked list can be displayed

Node* get_node(Item& entry, Node* forward, Node* backward);
Post: get_node creates a new node

void removeDup(struct Node *start)
Post: removes the nodes where values are duplicates

size_t linklist::length() const
Post: Takes in a list and returns the length of it

bool linklist::present(const Item& target) const
Post takes in an item and returns true or false depending if target is in list

void linklist::display()
Post: Takes list and displays it

bool linkist::isempty()
Post: Takes a list and returns a boolean if empty or items exist

void linklist::make_empty()
Post: Takes a list and makes it empty

*/


class linklist
{
public:

	typedef char Item;
	linklist() { first = NULL; }
	
	size_t length() const;
	~linklist();
	void  insert(Item& entry);
	bool present(const Item& target) const;
	
	bool isempty();
	void make_empty();
	Item kth(size_t k) const ;
		
	friend std::ostream& operator << (std::ostream& out_s, const  linklist& l);

		struct Node		//create node
	{
		Item data;
		Node *next;
		Node *back;
	};
	Node *first;
	Node *last;

	Node* get_node(Item& entry, Node* forward, Node* backward);
};

#endif