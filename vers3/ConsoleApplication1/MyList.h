
#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include "MyList.h"
using namespace std;
struct List {
	int value;
	List* next;
	List(int symb, List* pointer) : value(symb), next(pointer) {}
};
class MyList
{

private:
	List* first = NULL,
		* tail = NULL,
		* last = NULL;
public:
		MyList()
		{
			
		}
	void push_back(int number) // add to the end of the list
	{
		if (first == NULL) {
			first = new List(number, NULL);
			tail = first;
		}
		else {
			tail = first;
			while (tail->next)
				tail = tail->next;
			last = tail;
			tail = new List(number, NULL);
			if (first->next == NULL)
				first->next = tail;
			last->next = tail;
		}
	}
	void push_front(int number) // add to the top of the list
	{
		first = new List(number, first);
	}
	void pop_back() {  // deleting the last element
		List* counter;
		for (counter = first; counter->next != last; counter = counter->next)
		{
		}
		tail = last;
		last = counter;
		tail->next = NULL;
	}
	void pop_front() // deleting the first element
	{
		first = first->next;
	}
	void insert(int position, int number) { // adding an item by index
		List* counter;
		counter = first;
		int step = 1;
		if(position <=1)
			first = new List(number, first);
		else
		{
			while (step < position - 1)
			{
				step++;
				counter = counter->next;
			}
			counter->next = new List(number, counter->next);
		}
	} 
	int at(int position) { // getting an item by index
		List* counter;
		counter = first;
		int step = 1;
		while (step < position)
		{
			step++;
			counter = counter->next;
		}
		return (counter->value);
		
	} 
	void remove(int position) {  // deleting an item by index
		List* counter;
		counter = first;
		for (int i = 1 ; i >= position; i++)
		{
			counter = counter->next;
		}
		counter->next = counter->next->next;
	} 
	size_t get_size() { // getting the list size
		List* counter;
		counter = first;
		int size_list = 0;
		while (counter)
		{
			counter = counter->next;
			size_list++;
		}
		return(size_list);
		
	}
	void print_to_console() { // output list items to the console using a separator
		List* counter;
		counter = first;
		while (counter)
		{
			std::cout << counter->value << ' ';
			counter = counter->next;
		}


	} 
	void clear()
	{
		first = NULL;
		tail = first;
		last = tail;
	} // delete all list items
	void set(int position, int number) { // replacing an element by index with the passed element
		List* counter;
		counter = first;
		int step = 1;
		while (step < position)
		{
			step++;
			counter = counter->next;
		}
		counter->value = number;
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
		List* counter;
		List* holder_list;
		counter = first;
		while (counter)
		{
			int Random = rand() % (get_size()+1);
			holder_list = first;
			for (int i = 1; i < Random; i++)
				holder_list = holder_list->next;
			Random = holder_list->value;
			holder_list->value = counter->value;
			counter->value = Random;
			counter = counter->next;
		}
	}

	~MyList()
	{
		clear();
	}
};



#endif
