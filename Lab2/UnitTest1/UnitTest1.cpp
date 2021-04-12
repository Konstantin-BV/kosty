#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\kosty\source\repos\Lab2\Lab2\Lab2.cpp"
#include <string>
#include <iostream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		
	public:
		List Co;
		Tree T;
		string s;
        
		
		TEST_METHOD(push_back)
		{
			s = "abcd";
			for (int i = 0; s[i] != '\0'; i++)
			{
				Co.push_back(s[i]);
			}
			Assert::AreEqual(Co.root->ch, 'a');
			Assert::AreEqual(Co.root->Next->ch, 'b');
			Assert::AreEqual(Co.root->Next->Next->ch, 'c');
			Assert::AreEqual(Co.root->Next->Next->Next->ch, 'd');
		}
		TEST_METHOD(create_list)
		{
			Co.root = NULL;
			s = "abcd";
			for (int i = 0; s[i] != '\0'; i++)
			{
				Co.push_back(s[i]);
			}
			T.create_list(Co);
			Assert::AreEqual(T.nodes.root->ch, 'a');
			Assert::AreEqual(T.nodes.root->Next->ch, 'b');
			Assert::AreEqual(T.nodes.root->Next->Next->ch, 'c');
			Assert::AreEqual(T.nodes.root->Next->Next->Next->ch, 'd');
		}
		TEST_METHOD(push_back_node)
		{
			Co.root = NULL;
			s = "abcd";
			for (int i = 0; s[i] != '\0'; i++)
			{
				Co.push_back(s[i]);
			}
			T.create_list(Co);
			Assert::AreEqual(T.nodes.root->ch, 'a');
			Assert::AreEqual(T.nodes.root->Next->ch, 'b');
			Assert::AreEqual(T.nodes.root->Next->Next->ch, 'c');
			Assert::AreEqual(T.nodes.root->Next->Next->Next->ch, 'd');
			Node* Q = new Node('w', NULL);
			T.nodes.push_back_node(Q);
			Assert::AreEqual(T.nodes.root->Next->Next->Next->Next->ch, 'w');
		}
		TEST_METHOD(DELETE)
		{
			s = "abcd";
			for (int i = 0; s[i] != '\0'; i++)
			{
				Co.push_back(s[i]);
			}
			Assert::AreEqual(Co.root->ch, 'a');
			Assert::AreEqual(Co.root->Next->ch, 'b');
			Assert::AreEqual(Co.root->Next->Next->ch, 'c');
			Assert::AreEqual(Co.root->Next->Next->Next->ch, 'd');
			Co.DELETE(Co.root->Next);
			Assert::AreEqual(Co.root->ch, 'a');
			Assert::AreEqual(Co.root->Next->ch, 'c');
			Assert::AreEqual(Co.root->Next->Next->ch, 'd');
		}
		TEST_METHOD(push_node)
		{
			Co.root = NULL;
			T.nodes.root = NULL;
			s = "abcd";
			for (int i = 0; s[i] != '\0'; i++)
			{
				Co.push_back(s[i]);
			}
			T.create_list(Co);
			Assert::AreEqual(T.nodes.root->ch, 'a');
			Assert::AreEqual(T.nodes.root->Next->ch, 'b');
			Assert::AreEqual(T.nodes.root->Next->Next->ch, 'c');
			Assert::AreEqual(T.nodes.root->Next->Next->Next->ch, 'd');
			while (T.nodes.root->Next)
			{
				T.push_node();
			}
			Assert::AreEqual(T.nodes.root->Right->Right->ch, 'a');
			Assert::AreEqual(T.nodes.root->Right->left->ch, 'b');
			Assert::AreEqual(T.nodes.root->left->Right->ch, 'c');
			Assert::AreEqual(T.nodes.root->left->left->ch, 'd');
		}
		TEST_METHOD(way)
		{
			Co.root = NULL;
			T.nodes.root = NULL;
			s = "abcd";
			for (int i = 0; s[i] != '\0'; i++)
			{
				Co.push_back(s[i]);
			}
			T.create_list(Co);
			Assert::AreEqual(T.nodes.root->ch, 'a');
			Assert::AreEqual(T.nodes.root->Next->ch, 'b');
			Assert::AreEqual(T.nodes.root->Next->Next->ch, 'c');
			Assert::AreEqual(T.nodes.root->Next->Next->Next->ch, 'd');
			while (T.nodes.root->Next)
			{
				T.push_node();
			}
			Assert::AreEqual(T.nodes.root->Right->Right->ch, 'a');
			Assert::AreEqual(T.nodes.root->Right->left->ch, 'b');
			Assert::AreEqual(T.nodes.root->left->Right->ch, 'c');
			Assert::AreEqual(T.nodes.root->left->left->ch, 'd');
			T.node_path(T.nodes.root->Right, "\0", "1");
			T.node_path(T.nodes.root->left, "\0", "0");
			Assert::AreEqual(T.nodes.root->Right->Right->way,(string) "11");
			Assert::AreEqual(T.nodes.root->Right->left->way, (string)"10");
			Assert::AreEqual(T.nodes.root->left->Right->way, (string)"01");
			Assert::AreEqual(T.nodes.root->left->left->way, (string)"00");
		}

	};
}
