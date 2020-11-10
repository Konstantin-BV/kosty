#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Костя\source\repos\ConsoleApplication1\ConsoleApplication1\MyList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		MyList* test;
		

		TEST_METHOD_INITIALIZE(LISTnew)
		{
			test = new MyList();
		}
		TEST_METHOD(push_back)
		{

			test->push_front(2);
			test->push_back(44);
			test->push_front(64);
			test->push_back(55);
			Assert::AreEqual(test->at(3), 44);
			Assert::AreEqual(test->at(4), 55);
		};
		TEST_METHOD(push_front)
		{
			test->push_back(10);
			test->push_back(8);
			test->push_front(3);
			test->push_front(9);
			Assert::AreEqual(test->at(2), 3);
			Assert::AreEqual(test->at(1), 9);
		};
		TEST_METHOD(pop_back)
		{
			test->push_back(1);
			test->push_back(86);
			test->push_front(30);
			Assert::AreEqual(test->at(3), 86);
			test->pop_back();
			test->push_back(2);
			Assert::AreEqual(test->at(3), 2);
		};
		TEST_METHOD(pop_front)
		{
			test->push_back(1);
			test->push_back(86);
			test->push_front(30);
			Assert::AreEqual(test->at(1), 30);
			test->pop_back();
			test->push_front(2);
			Assert::AreEqual(test->at(1), 2);
		}// удаление первого элемента
		TEST_METHOD(insert)
		{
			test->push_back(1);
			test->push_back(86);
			test->push_back(99);
			test->push_back(2);
			Assert::AreEqual(test->at(3), 99);
			test->insert(3, 2);
			Assert::AreEqual(test->at(3), 2);
		};
		TEST_METHOD(at)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->push_back(4);
			Assert::AreEqual(test->at(1), 1);
			Assert::AreEqual(test->at(2), 2);
			Assert::AreEqual(test->at(3), 3);
			Assert::AreEqual(test->at(4), 4);
		}
		TEST_METHOD(remove)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->push_back(4);
			Assert::AreEqual(test->at(2), 2);
			test->remove(2);
			Assert::AreEqual(test->at(2), 3);

		}
		TEST_METHOD(get_size)
		{
			test->push_back(4);
			test->push_back(10);
			Assert::AreEqual(test->get_size(), (size_t)2);
			test->push_back(40);
			test->push_back(1);
			Assert::AreEqual(test->get_size(), (size_t)4);
		}
		TEST_METHOD(clear)
		{
			test->push_back(4);
			test->push_back(2);
			Assert::AreEqual(test->isEmpty(), true);
			test->clear();
			Assert::AreEqual(test->isEmpty(),  false);
		}
		TEST_METHOD(set)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->push_back(4);
			size_t o = test->get_size();
			Assert::AreEqual(test->at(2), 2);
			test->set(2,444);
			Assert::AreEqual(o, test->get_size());
			Assert::AreEqual(test->at(2), 444);

		}
		TEST_METHOD(isEmpty)
		{
			Assert::AreEqual(test->isEmpty(), false);
			test->push_back(4);
			Assert::AreEqual(test->isEmpty(), true);
		}
		TEST_METHOD(reverse)
		{
			int i, k, int1, int2, int3;
			bool mix = true;
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			for (i = 1; i <= 6; i++)
			{
				int1 = test->at(1);
				int2 = test->at(2);
				int3 = test->at(3);
				test->reverse();
				if ((int1 == test->at(1)) && (int2 == test->at(2)) && (int3 == test->at(3)) && mix)
					mix = false;

			}
			Assert::AreEqual(mix, false);
		}
	};
}
