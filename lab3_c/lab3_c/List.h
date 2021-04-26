#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Node_city
{
	string city;
	int min_price;
	Node_city* next;
	Node_city(string name, int cost): city(name), min_price(cost), next(NULL){}
};
struct flight
{
	string city;
	string on_city;
	int prise;
	bool check;
	flight* next;
	flight(string name, string on_name, int cost) : city(name), on_city(on_name), prise(cost), next(NULL), check(false){}
};
class List
{
private:

public:
	flight* root=NULL;
	Node_city* root_city_cheack = NULL;
	string begin_city, end_city;
	void deleter()
	{
		root = NULL;
		root_city_cheack = NULL;
		begin_city = "";
		end_city = "";
	}
	void Insert(string city1,string city2,int prise1,int prise2)
	{
		flight* Current=root;
		if (!root)
		{
			root = new flight(city1, city2, prise1);
			Current = root;
		}
		else
		{
			while (Current->next)
			{
				Current = Current->next;
			}
			Current->next= new flight(city1, city2, prise1);
			Current = Current->next;
		}
		Current->next = new flight(city2, city1, prise2);
	}
	void the_happy_begin(string begin_city1, string end_city1)
	{
		begin_city = begin_city1;
		end_city = end_city1;
	}
	flight* find(string r)
	{
		flight* Y = root;
		flight* Q = NULL;
		int min_cost = 9999;
		while (Y)
		{
			if (Y->city == r)
				if ((Y->prise < min_cost) && !(Y->check))
				{
					min_cost = Y->prise;
					Q = Y;
				}
			Y = Y->next;
		}
		return Q;
	}
	void check(string r)
	{
		flight* Y = root;
		while (Y)
		{
			if (Y->on_city == r)
				Y->check = true;
			Y = Y->next;
		}
	}
	int checking()
	{
		int min=INFINITY;
		flight* Miin;
		flight* S;
		Node_city* current2;
		Node_city* current3;
		int min_prise;
		root_city_cheack = new Node_city(begin_city, 0);
		string s;
		S = find(begin_city);
		min_prise = S->prise;
		while (S->on_city != end_city)
		{
			current3 = root_city_cheack;
			min_prise = INT_MAX;
			while (current3)
			{
				s = current3->city;
				Miin = find(s);
				if (Miin)
					if (Miin->prise + current3->min_price < min_prise)
					{
						S = Miin;
						min_prise = Miin->prise + current3->min_price;
					}
				current3 = current3->next;
			}
			if (min_prise == INT_MAX)
			{
				min_prise = INT_MAX;
				break;
			}
			current2 = root_city_cheack;
			while (current2->city != S->city)
			{
				current2 = current2->next;
			}
			current3 = root_city_cheack;
			while (current3->next)
			{
				current3 = current3->next;
			}
			current3->next = new Node_city(S->on_city, current2->min_price + S->prise);
			check(S->on_city);
			min_prise = current2->min_price + S->prise;
		}
		return min_prise;

	}
};

