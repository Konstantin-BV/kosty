
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
	int s;
	List* LA = NULL,
		* current = NULL,
		* p,
		* c,
		* last = NULL;
	int i = 0, w, k, t;
public:
		MyList()
		{
			
		}
	void push_back(int s) // add to the end of the list
	{
		if (LA == NULL) {
			LA = new List(s, NULL);
			current = LA;
		}
		else {
			current = LA;
			while (current->next)
				current = current->next;
			last = current;
			current = new List(s, NULL);
			if (LA->next == NULL)
				LA->next = current;
			last->next = current;
		}
	}
	void push_front(int s) // add to the top of the list
	{
		LA = new List(s, LA);
	}
	void pop_back() {  // deleting the last element
		for (p = LA; p->next != last; p = p->next)
		{
		}
		current = last;
		last = p;
		current->next = NULL;
	}
	void pop_front() // deleting the first element
	{
		LA = LA->next;
	}
	void insert(int k, int s) { // adding an item by index
		
		p = LA;
		t = 1;
		if(k<=1)
			LA = new List(s, LA);
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
		p = LA;
		t = 1;
		while (t < k)
		{
			t++;
			p = p->next;
		}
		return (p->symb);
		
	} 
	void remove(int k) {  // deleting an item by index
		p = LA;
		for (t = 1 ; t >= k; t++)
		{
			p = p->next;
		}
		p->next = p->next->next;
	} 
	size_t get_size() { // getting the list size
		c = LA;
		s = 0;
		while (c)
		{
			c = c->next;
			s++;
		}
		return(s);
		
	}
	void print_to_console() { // output list items to the console using a separator, do not use at
		p = LA;
		while (p)
		{
			std::cout << p->symb << ' ';
			p = p->next;
		}


	} 
	void clear()
	{
		LA = NULL;
		current = LA;
		last = current;
	} // delete all list items
	void set(int k, int s) { // replacing an element by index with the passed element
		p = LA;
		t = 1;
		while (t < k)
		{
			t++;
			p = p->next;
		}
		p->symb = s;
	} 
	bool isEmpty() { // checking if the list is empty
		if (LA)
			return(true);
		else
		{
			return(false);
		}

	} 
	void reverse() // changes the order of items in the list
	{
		p = LA;
		while (p)
		{
			i = rand() % (get_size()+1);
			c = LA;
			for (k = 1; k < i; k++)
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
