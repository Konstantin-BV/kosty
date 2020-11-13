
#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include "MyList.h"
using namespace std;
struct item {
	int value;
	item* next;
	item(int symb, item* pointer) : value(symb), next(pointer) {}
};
class MyList
{

private:
	item* first = NULL,
		* last = NULL;
public:
		MyList()
		{
			
		}
	void push_back(int number) // add to the end of the list
	{

		item* tail = NULL;
		if (first == NULL) {
			first = new item(number, NULL);
			last = first;
		}
		else {
			tail = new item(number, NULL);
			if (first->next == NULL)
				first->next = tail;
			last->next = tail;
			last = tail;
		}
	}
	void push_front(int number) // add to the top of the list
	{
		first = new item(number, first);
		if (first->next == NULL)
		last = first;
	}
	void pop_back() {  // deleting the last element
		item* counter;
		if (first == NULL)
			throw out_of_range("В писке нет элементов");
		for (counter = first; counter->next != last; counter = counter->next)
		{
			if (counter == last)
				break;
		}
		last = counter;
		last->next = NULL;
	}
	void pop_front() // deleting the first element
	{
		if (first == NULL)
			throw out_of_range("В писке нет элементов");
		if (first->next == NULL)
			first = NULL;
		else
		first = first->next;
	}
	void insert(int position, int number) { // adding an item by index
		if ((position > get_size()) || (position < 0))
			throw out_of_range("В писке нет такого элемента");
		item* counter;
		counter = first;
		int step = 1;
		if(position <=1)
			first = new item(number, first);
		else
		{
			while (step < position - 1)
			{
				step++;
				counter = counter->next;
			}
			counter->next = new item(number, counter->next);
		}
	} 
	int at(int position) { // getting an item by index
		if ((position > get_size()) || (position < 0))
			throw out_of_range("В писке нет такого элемента");
		item* counter;
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
		if ((position > get_size()) || (position < 0))
			throw out_of_range("В писке нет такого элемента");
		item* counter;
		counter = first;
		for (int i = 1 ; i >= position; i++)
		{
			counter = counter->next;
		}
		counter->next = counter->next->next;
	} 
	size_t get_size() { // getting the list size
		item* counter;
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
		item* counter;
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
		last = first;
	} // delete all list items
	void set(int position, int number) { // replacing an element by index with the passed element
		if ((position > get_size()) || (position < 0))
			throw out_of_range("В писке нет такого элемента");
		item* counter;
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
		int step = 0,size=get_size();
		item* counter;
		item* holder_list;
		counter = first;
		while (step < size - step)
		{
			
			int current = size - step;
			holder_list = first;
			for (int i = 1; i < current; i++)
				holder_list = holder_list->next;
			current = holder_list->value;
			holder_list->value = counter->value;
			counter->value = current;
			counter = counter->next;
			step++;
		}
	}

	~MyList()
	{
		clear();
	}
};



#endif
