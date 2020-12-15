#include "Tree.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

element* List::get_first()
{
	return(root);
}
void List::push_front(node* current)
{
		List::root = new element(current, List::root);
}
void List::push_back(node* current)
{
	element* eliment;
	if (List::root == NULL)
		List::root = new element(current, NULL);
	else
	{
		eliment = List::root;
		while (eliment->next)
		{
			eliment = eliment->next;
		}
		eliment->next = new element(current, NULL);
	}
}

void List::del_first()
{
	List::root = List::root->next;
}

bool Tree::contains(int x)
{
	node* Current = first;
	if(first == NULL)
		return(false);
	while (Current->value != x)
	{
		if (x < Current->value)
		{
			if (Current->left == NULL)
			{
				return(false);
				break;
			}
			Current = Current->left;

		}
		else   
		{
			if (Current->right == NULL)
			{
				return(false);
				break;
			}
			Current = Current->right;
		}
	}
	if (Current->value == x)
		return(true);
	else
		return(false);
}
void Tree::insert(int x)
{
	node* Current = first;
	if (first == NULL)
		first = new node(x, NULL, NULL);
	else
		while (1 != 0) { // Åñëè äåğåâà íåò, òî ôîğìèğóåì êîğåíü

			if (x < Current->value) {
				if (Current->left == NULL)
				{
					Current->left = new node(x, NULL, NULL);
					break;
				}
				else
					Current = Current->left;
			}
			else    // óñëîâèå äîáàâëåíèå ïğàâîãî ïîòîìêà
				if (Current->right == NULL)
				{
					Current->right = new node(x, NULL, NULL);
					break;
				}
				else
					Current = Current->right;
		}
}

void Tree::remove(int digit)
{
	if (first == NULL) return;
	node* current = first,
		* parent = NULL;
	while (1)
	{
		
		if (current->value == digit)
		{

			if (current->left == NULL && current->right == NULL)
			{
				if (parent != NULL)
				{
					if (parent->left == current)
						parent->left = NULL;
					else
						parent->right = NULL;
				}
				else
				{
					first = NULL;
				}
				delete current;
				return;
			}
			else if (current->left == NULL || current->right == NULL)
			{
				if (current->left != NULL)
				{
					swap(current->value, current->left->value);
					delete current->left;
					current->left = NULL;
				}
				else
				{
					swap(current->value, current->right->value);
					delete current->right;
					current->right = NULL;
				}
				return;
			}
			else
			{
				node* currentForSwap = current->left;
				while (currentForSwap->right != NULL)
					currentForSwap = currentForSwap->right;
				swap(current->value, currentForSwap->value);
				if (parent->right == currentForSwap)
				parent->right = NULL;
				else
					parent->left = NULL;
				delete currentForSwap;
			}
		}
		parent = current;
		if (digit > current->value)
		{
			if (current->right != NULL)
				current = current->right;
			else return;
		}
		else
		{
			if (current->left != NULL)
				current = current->left;
			else return;
		}


	}
}

Iterator* Tree::create_bft_iterator() 
{
	 if(first  == nullptr) throw std::logic_error("How can you make an iterator for an empty tree?");
	 return new Tree::bft_Iterator(first);
	
};
Iterator* Tree::create_dft_iterator() {
	 if(first == nullptr) throw std::logic_error("How can you make an iterator for an empty tree?");
	 return new dft_Iterator(first);
	
}
bool Tree::bft_Iterator::has_next()
{
	element* current = list_nodes.get_first();
	if (current) return(true);
	else
	return(false);

}
bool Tree::dft_Iterator::has_next()
{
	element* current = list_nodes.get_first();
	if (current) return(true);
	else
		return(false);
}
int Tree::bft_Iterator::next()
{
	element* current = list_nodes.get_first();
	list_nodes.del_first();
	if (current->inf->left != nullptr)
		list_nodes.push_back(current->inf->left);
	if (current->inf->right != nullptr)
		list_nodes.push_back(current->inf->right);
	return current->inf->value;
}
int Tree::dft_Iterator::next()
{
	element* current = list_nodes.get_first();
	list_nodes.del_first();
	if (current->inf->right != nullptr)
	list_nodes.push_front(current->inf->right);
	if (current->inf->left != nullptr)
	list_nodes.push_front(current->inf->left);
	 return current->inf->value;
}
void Tree::deep()
{
	dft_Iterator current(first);
	while (current.has_next())
	{
		cout << current.next() << ' ';
	}
}
void Tree::wide()
{
	bft_Iterator current(first);
	while (current.has_next())
	{
		cout << current.next() << ' ';
	}
}
