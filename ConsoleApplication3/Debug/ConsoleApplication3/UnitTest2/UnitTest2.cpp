#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Костя\source\repos\ConsoleApplication3\ConsoleApplication3\ConsoleApplication3.cpp"
#include "C:\Users\Костя\source\repos\ConsoleApplication3\ConsoleApplication3\Tree.h"
#include "C:\Users\Костя\source\repos\ConsoleApplication3\ConsoleApplication3\iterator.h"
#include "C:\Users\Костя\source\repos\ConsoleApplication3\ConsoleApplication3\Tree.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		Tree tester;
		
		TEST_METHOD(insert)
		{
			tester.insert(6);
			Assert::AreEqual(tester.contains(6), true);
		}
		TEST_METHOD(null_contains)
		{
			Assert::AreEqual(tester.contains(6), false);
		}
		TEST_METHOD(Delete)
		{
			tester.insert(6);
			tester.insert(3);
			tester.insert(5);
			tester.insert(1);
			tester.insert(20);
			tester.insert(9);
			Assert::AreEqual(tester.contains(3), true);
			tester.remove(3);
			Assert::AreEqual(tester.contains(3), false);
		}
		TEST_METHOD(delete_parent)
		{
			tester.insert(6);
			tester.insert(3);
			tester.insert(5);
			tester.insert(1);
			tester.insert(20);
			tester.insert(21);
			tester.insert(9);
			Assert::AreEqual(tester.contains(20), true);
			tester.remove(20);
			Assert::AreEqual(tester.contains(20), false);
			Assert::AreEqual(tester.contains(9), true);
			Assert::AreEqual(tester.contains(21), true);
		}
		TEST_METHOD(null_remove)
		{
			tester.remove(20);
			Assert::AreEqual(tester.contains(20), false);
		}
		TEST_METHOD(TestMethod6)
		{
			tester.remove(20);
			Assert::AreEqual(tester.contains(20), false);
		}
	};
}
