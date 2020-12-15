#pragma once
#include "iterator.h"
using namespace std;
struct node {
	int value;
	node* left,
		* right;
	node(int symb, node* pointer, node* pointer2) : value(symb), left(pointer), right(pointer2) {}
};

struct element {
	node* inf;
	element* next;
	element(node* symb, element* pointer) : inf(symb), next(pointer) {}
};

class List
{
private:
	element* root;
public:
	void push_front(node* current);
	void push_back(node* current);
	void del_first();
	element* get_first();
};
class Tree
{

private:
	node* first;
public:
	Tree() {};
	~Tree() {};
	bool contains(int x);
	void insert(int x);
	void remove(int x);
	void deep();
	void wide();
	Iterator* create_bft_iterator();
	Iterator* create_dft_iterator();
	class dft_Iterator : public Iterator {
	List list_nodes;
	node * current;
	public:
	dft_Iterator(node * start) : current(start) {
	list_nodes.push_front(start);
		}
		bool has_next();
		int next();
	};
	class bft_Iterator : public Iterator {
		List list_nodes;
		node* current;
	public:
		bft_Iterator(node* start) : current(start) {
		list_nodes.push_front(start);
		}
		bool has_next();
		int next();
	};


};