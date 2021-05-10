#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\kosty\source\repos\Course_work\Course_work\Way.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	Way test;
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Insert)
		{
			test.Insert("spb", "msk", 13);
			test.Insert("msk", "omsk", 14);
			Assert::AreEqual(test.root->prise, 13);
			Assert::AreEqual(test.root->next->prise, 0);
			Assert::AreEqual(test.root->next->next->prise, 14);
			Assert::AreEqual(test.root->next->next->next->prise, 0);
		};
		TEST_METHOD(checking)
		{
			test.deleter();
			test.Insert("S", "P", 11);
			test.Insert("P", "T", 11);
			test.Insert("S", "C", 10);
			test.Insert("C", "T", 10);
			int i = test.checking();
			Assert::AreEqual(i, 11);
		};

		TEST_METHOD(finall)
		{
			test.deleter();
			test.Insert("S", "T", 11);
			test.Insert("S", "C", 10);
			test.Insert("C", "T", 10);
			int i = test.FINAL();
			Assert::AreEqual(i, 21);
		};
		TEST_METHOD(not_cheack)
		{
			test.deleter();
			test.Insert("S", "T", 11);
			test.Insert("S", "C", 10);
			test.Insert("C", "T", 10);
			Assert::AreEqual(test.root->check, false);
			int i = test.checking();
			Assert::AreEqual(test.root->check, true);
			test.not_check();
			Assert::AreEqual(test.root->check, false);
		};
		TEST_METHOD(find)
		{
			test.deleter();
			test.Insert("msk", "spb", 13);
			test.Insert("msk", "omsk", 10);
			string s1 = "msk", s2 = "omsk", s3 = "spb";
			flight* R = test.find("msk");
			Assert::AreEqual(R->prise, 13);
			Assert::AreEqual(R->city, s1);
			Assert::AreEqual(R->on_city, s3);
		};
		TEST_METHOD(find_revers_may)
		{
			test.deleter();
			test.Insert("msk", "spb", 13);
			test.Insert("msk", "omsk", 10);
			string s1 = "msk", s2 = "spb";
			flight* R = test.find("msk");
			Assert::AreEqual(R->prise, 13);
			Assert::AreEqual(test.find_revers_may(s1,s2)->prise, 0);
		};
		TEST_METHOD(minus)
		{
			test.deleter();
			test.Insert("S", "P", 11);
			test.Insert("P", "T", 10);
			test.Insert("S", "C", 10);
			test.Insert("C", "T", 10);
			int i = test.checking();
			Assert::AreEqual(i, 10);
			Assert::AreEqual(test.find_revers_may("P", "S")->prise, 1);
			Assert::AreEqual(test.find_revers_may("S", "P")->prise, 10);
		};
		
	};
}