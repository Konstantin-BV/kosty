#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
struct Node_city
{
	string city;
	int min_price;
	Node_city* next;
	Node_city(string name, int cost) : city(name), min_price(cost), next(NULL) {}
};
struct flight
{
	string city;
	string on_city;
	int prise;
	flight* next;
	bool check;
	flight(string name, string on_name, int cost) : city(name), on_city(on_name), check(false), prise(cost), next(NULL) {}
};
class Way
{
private:

public:
	flight* root = NULL;
	Node_city* root_city_cheack = NULL;
	string begin_city = "S", end_city = "T";
	void deleter()
	{
		root = NULL;
		root_city_cheack = NULL;
	}
	void Insert(string city1, string city2, int prise1)
	{
		flight* Current = root;
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
			Current->next = new flight(city1, city2, prise1);
			Current = Current->next;
		}
		Current->next = new flight(city2, city1, 0);
	}
	flight* find(string r)
	{
		flight* Y = root;
		flight* Q = NULL;
		int min_cost = -1;
		while (Y)
		{
			if (Y->city == r)
				if ((Y->prise > min_cost) && !(check(Y->on_city)))
				{
					min_cost = Y->prise;
					Q = Y;
				}
			Y = Y->next;
		}
		return Q;
	}
	flight* find_revers_may(string r, string s)
	{
		flight* Y = root;
		while (Y)
		{
			if ((Y->on_city == r)&&(Y->city == s))
				break;
			Y = Y->next;
		}
		return Y;
	}
	bool city_check(string r)
	{
		flight* g = root;
		bool a = false, b = false;
		while(g)
		{
			if (g->city == r)
				a = !a;
			if (g->on_city == r)
				b = !b;
			g = g->next;
		}
		return (a && b);
	}
	int min_max()
	{
		int min = INT_MAX;
		flight* Y = root;
		while (Y)
		{
			if (Y->check)
			{
				if ((Y->prise < min) && (Y->city != end_city))
					min = Y->prise;
			}
			Y = Y->next;
		}
		return min;
	}
	void minus(int j)
	{
		flight* Y = root;
		while (Y)
		{
			if ((Y->check))
			{
				find_revers_may(Y->city, Y->on_city)->prise += j;
				Y->prise = Y->prise - j;
			}
			Y = Y->next;
		}
	}
	bool check(string r)
	{
		Node_city* Y = root_city_cheack;
		bool a = false;
		string k;
		while (Y)
		{
			k = Y->city;
			if (!( k != r ))
				a = true;
			Y = Y->next;
		}
		return a;
	}
	void not_check()
	{
		flight* Y = root;
		while (Y)
		{
			Y->check = false;
			Y = Y->next;
		}
	}
	int FINAL()
	{
		int s = 1,finall=0;
		while (s != 0)
		{
			s = checking();
			finall = finall + s;
			root_city_cheack = NULL;
			not_check();
		}
		return finall;
	}
	int checking()
	{
		flight* Miin;
		flight* S;
		begin_city = "S";
		end_city = "T";
		Node_city* current2;
		Node_city* current3;
		int min_prise;
		root_city_cheack = new Node_city(begin_city, 0);
		string s;
		S = find(begin_city);
		min_prise = S->prise;
		do
		{
			current3 = root_city_cheack;
			min_prise = 0;
			while (current3)
			{
				s = current3->city;
				Miin = find(s);
				if (Miin)
					if (Miin->prise + current3->min_price > min_prise)
					{
						S = Miin;
						min_prise = Miin->prise + current3->min_price;
					}
				current3 = current3->next;
			}
			if (min_prise == 0)
			{
				min_prise = 0;
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
			S->check = true;
			min_prise = current2->min_price + S->prise;
		} while (S->on_city != end_city);
 		if (min_prise != 0)
		{
			min_prise = min_max();
			minus(min_prise);
		}
		current3 = root_city_cheack;
		while (current3->next)
		{
			std::cout << current3->city << ' ';
			current3 = current3->next;
		}
		if (min_prise != 0)
		std::cout << min_prise;
		std::cout << endl;
		return min_prise;

	}
};

