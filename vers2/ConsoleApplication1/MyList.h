
#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include "MyList.h"
using namespace std;
struct List {
	int symb;
	List* next;
	List(int s, List* p) : symb(s), next(p) {}
};
class MyList
{

private:
	List* first = NULL,
		* current = NULL,
		* last = NULL;
public:
		MyList()
		{
			
		}
	void push_back(int s) // add to the end of the list
	{
		if (first == NULL) {
			first = new List(s, NULL);
			current = first;
		}
		else {
			current = first;
			while (current->next)
				current = current->next;
			last = current;
			current = new List(s, NULL);
			if (first->next == NULL)
				first->next = current;
			last->next = current;
		}
	}
	void push_front(int s) // add to the top of the list
	{
		first = new List(s, first);
	}
	void pop_back() {  // deleting the last element
		List* p;
		for (p = first; p->next != last; p = p->next)
		{
		}
		current = last;
		last = p;
		current->next = NULL;
	}
	void pop_front() // deleting the first element
	{
		first = first->next;
	}
	void insert(int k, int s) { // adding an item by index
		List* p;
		p = first;
		int t = 1;
		if(k<=1)
			first = new List(s, first);
		else
		{
			while (t < k - 1)
			{
				t++;
				p = p->next;
			}
			p->next = new List(s, p->next);
		}
	} 
	int at(int k) { // getting an item by index
		List* p;
		p = first;
		int t = 1;
		while (t < k)
		{
			t++;
			p = p->next;
		}
		return (p->symb);
		
	} 
	void remove(int k) {  // deleting an item by index
		List* p;
		p = first;
		for (int t = 1 ; t >= k; t++)
		{
			p = p->next;
		}
		p->next = p->next->next;
	} 
	size_t get_size() { // getting the list size
		List* c;
		c = first;
		int s = 0;
		while (c)
		{
			c = c->next;
			s++;
		}
		return(s);
		
	}
	void print_to_console() { // output list items to the console using a separator
		List* p;
		p = first;
		while (p)
		{
			std::cout << p->symb << ' ';
			p = p->next;
		}


	} 
	void clear()
	{
		first = NULL;
		current = first;
		last = current;
	} // delete all list items
	void set(int k, int s) { // replacing an element by index with the passed element
		List* p;
		p = first;
		int t = 1;
		while (t < k)
		{
			t++;
			p = p->next;
		}
		p->symb = s;
	} 
	bool isEmpty() { // checking if the list is empty
		if (first)
			return(true);
		else
		{
			return(false);
		}

	} 
	void reverse() // changes the order of items in the list
	{
		List* p;
		List* c;
		p = first;
		while (p)
		{
			int i = rand() % (get_size()+1);
			c = first;
			for (int k = 1; k < i; k++)
				c = c->next;
			i = c->symb;
			c->symb = p->symb;
			p->symb = i;
			p = p->next;
		}
	}

	~MyList()
	{
		clear();
	}
};



#endif
