#pragma once
#include <string>
#include <iostream>
#include "List.h"
using namespace std;
struct Node
{
	Node* parent;
	Node* left;
	Node* Right;
	Node* Next;
	char ch;
	int weight;
	string way;
	Node(char c, Node* Righ) : ch(c), Next(Righ) {weight = 1; left = NULL; Right= NULL;}
};

class List
{
private:

public:
	Node* root = NULL;
	void push_back_node(Node* new_node) //push node on list
	{
		Node* Curent = root;
		if (Curent)
		{
			while (Curent->Next)
			{
				Curent = Curent->Next;
			}
			Curent->Next = new_node;
		}
		else
		{
			root = new_node;
		}
	}
	void push_back(char ch) //push new node on list
	{
		Node* Curent = root;
		if (root == NULL)
			root = new Node(ch, NULL);
		else
		{
			while ((Curent->ch != '\0') && (Curent->Next))
			{
				if (Curent->ch == ch)
				{
					Curent->weight++;
					break;
				}
				Curent = Curent->Next;
			}
			if (Curent->ch != ch)
				Curent->Next = new Node(ch, NULL);
		}
	};
	void DELETE(Node* Current)
	{
		Node* Curent = root;
		if (Curent == Current)
			root = root->Next;
		else
		{
			while (Curent->Next != Current)
			{
				Curent = Curent->Next;
				if (Curent->Next == NULL)
					break;
			}
			if (Curent->Next != NULL)
				Curent->Next = Curent->Next->Next;
		}
	}
};

class Tree
{
	private:

	public:

	Node* root = NULL;
	List nodes;
	List arr;
	int Memory = 0;
	void node_path(Node* ROOT, string bol, string road)
	{
		road = road + bol;
		if (ROOT == NULL)
		{
			return;
		}
		else
		{

			node_path(ROOT->left, "0", road);

			ROOT->way = road;

			node_path(ROOT->Right, "1", road);
			return;
		}
	}
	void print_weight(Node* ROOT, char f)
	{

		if (ROOT == NULL)
		{
			return;
		}
		else
		{

			print_weight(ROOT->left, f);

			if (ROOT->ch == f)
			{
				cout << ROOT->weight << ' ';
			}

			print_weight(ROOT->Right, f);
			return;
		}
	}
	void print_s(Node* ROOT,char f)
	{
		
		if (ROOT == NULL)
		{
			return;
		}
		else
		{

			print_s(ROOT->left,f);

			if (ROOT->ch == f)
			{
				for (int j = 1; ROOT->way[j] != '\0'; j++)
				{
					Memory++;
				}
				cout << ROOT->way << ' ';
			}

			print_s(ROOT->Right,f);
			return;
		}
	}
	void print_ch(Node* ROOT, string f,int i)
	{
		if (ROOT->ch != '\0')
		{
			cout << ROOT->ch;
		}
		else
		{
			if (f[i] == '0')
				print_ch(ROOT->left, f, i + 1);
			if (f[i] == '1')
				print_ch(ROOT->Right, f, i + 1);
		}
	}
	void create_list(List new_list)
	{
		nodes = new_list;
	}
	void push_node()
	{
		Node* Curent = nodes.root;
		Node* Le=root,* Re=root;
		int w = INT_MAX;
		int l, r;
		l = w;
		r = l;
		while (Curent)
		{
			if (Curent->weight < r)
			{
				r = Curent->weight < r;
				Re = Curent;
			}
			Curent = Curent->Next;
		}
		Curent = nodes.root;
		while (Curent)
		{
			if ((Curent->weight < l)&&(Curent != Re))
			{
				l = Curent->weight < l;
				Le = Curent;
			}
			Curent = Curent->Next;
		}
		nodes.DELETE(Le);
		nodes.DELETE(Re);
		Re->parent = new Node(NULL, NULL);
		Re->parent->Right = Re;
		if (!Le)
		{
			Le->parent = Re->parent;
			Le->parent->left = Le;
			Re->parent->weight = Le->weight + Re->weight;
		}
		else
		{
			Re->parent->weight = Le->weight + Re->weight;
			Re->parent->left = Le;
		}
		
		nodes.push_back_node(Re->parent);
	}
};