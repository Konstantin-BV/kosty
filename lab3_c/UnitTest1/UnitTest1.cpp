#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\kosty\source\repos\lab3_c\lab3_c\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	List test;
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Insert)
		{
			test.Insert("spb", "msk", 13, 12);
			test.Insert("msk", "omsk", 14, 24);
			Assert::AreEqual(test.root->prise, 13);
			Assert::AreEqual(test.root->next->prise, 12);
			Assert::AreEqual(test.root->next->next->prise, 14);
			Assert::AreEqual(test.root->next->next->next->prise, 24);
		};
		TEST_METHOD(find)
		{
			test.deleter();
			test.Insert("spb", "msk", 13, 12);
			test.Insert("msk", "omsk", 10, 24);
			string s1 = "msk", s2 = "omsk";
			flight* R = test.find("msk");
			Assert::AreEqual(R->prise, 10);
			Assert::AreEqual(R->city, s1);
			Assert::AreEqual(R->on_city, s2);
		};
		TEST_METHOD(check)
		{
			test.deleter();
			test.Insert("spb", "msk", 13, 12);
			test.Insert("msk", "omsk", 10, 24);
			test.check("msk");
			Assert::AreEqual(test.root->check, true);
			Assert::AreEqual(test.root->next->check, false);
			Assert::AreEqual(test.root->next->next->check, false);
			Assert::AreEqual(test.root->next->next->next->check, true);
		};
		TEST_METHOD(checking)
		{
			test.deleter();
			test.Insert("spb", "msk", 3, 12);
			test.Insert("msk", "omsk", 3, 3);
			test.Insert("spb", "omsk", 10, 12);
			test.Insert("omsk", "bagd", 2, 5);
			test.Insert("msk", "vas", , 11);
			test.Insert("bagd", "vas", 2, 10);
			test.the_happy_begin("spb", "vas");
			Assert::AreEqual(test.checking(), 10);
		}
	};
}
