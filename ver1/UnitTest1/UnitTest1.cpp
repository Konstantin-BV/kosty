#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Костя\source\repos\ConsoleApplication26\ConsoleApplication26\ConsoleApplication26.cpp"
#include <vector>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		vector<int> array_int;
		vector<char> array_char;
		
		TEST_METHOD(sorter)
		{

			for (int i = 0; i < 50; i++)
				array_int.push_back(rand() % 50);
			Assert::AreEqual(is_sorter(array_int), false);
			for (int i = 0; i < 50; i++)
				array_int[i] = i;
			Assert::AreEqual(is_sorter(array_int), true);
		}

			TEST_METHOD(binary)
		{
			for (int i = 0; i < 50; i++)
				array_int.push_back(i);
			int Random = (rand() % 50);
			Assert::AreEqual(BinarySearch(Random,array_int), Random);
		}
		TEST_METHOD(qsort)
		{
			for (int i = 0; i < 50; i++)
				array_int.push_back(rand() % 50);
			Assert::AreEqual(is_sorter(array_int), false);
			array_int = QuickSort(array_int, 0, size(array_int) - 1);
			Assert::AreEqual(is_sorter(array_int), true);
		}
		TEST_METHOD(QSort)
		{
			for (int i = 0; i < 50; i++)
				array_int.push_back(rand() % 50);
			Assert::AreEqual(is_sorter(array_int), false);
			array_int = QuickSort(array_int, 0, size(array_int) - 1);
			Assert::AreEqual(is_sorter(array_int), true);
		}
		TEST_METHOD(BSort)
		{
			for (int i = 0; i < 4; i++)
				array_int.push_back(rand() % 50);
			Assert::AreEqual(is_sorter(array_int), false);
			array_int = Bogosort(array_int);
			Assert::AreEqual(is_sorter(array_int), true);
		}
		TEST_METHOD(ISort)
		{
			for (int i = 0; i < 50; i++)
				array_int.push_back(rand() % 50);
			Assert::AreEqual(is_sorter(array_int), false);
			array_int = InsertionSort(array_int);
			Assert::AreEqual(is_sorter(array_int), true);
		}

		TEST_METHOD(csort)
		{
			for (int i = 0; i < 50; i++)
				array_char.push_back((char)((rand()%28) + 96));
			Assert::AreEqual(is_sorter(array_char), false);
			array_char = CountingSort(array_char);
			Assert::AreEqual(is_sorter(array_char), true);
		}
	};
}
