// ConsoleApplication26.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

bool is_sorter(vector<char> source_data)
{
	bool sorter = true;
	for (int i = 1; i < size(source_data) - 1; i++)
		if (source_data[i] < source_data[i - 1])
			sorter = false;
	return(sorter);
}

bool is_sorter(vector<int> source_data)
{
	bool sorter = true;
	for (int i = 1; i < size(source_data) - 1; i++)
		if (source_data[i] < source_data[i - 1])
			sorter = false;
	return(sorter);
}
vector<char> CountingSort(vector<char> source_data)
{
	int index = 0;
	int i = 0;
	int key[28];
	for (index = 0; index < size(key); index++)
		key[index] = 0;
	for (index = 0; index < size(source_data); index++)
	{
		key[(int)source_data[index]-96]++;
	}
	for (index = 0; index < size(key); index++)
	{
		while (key[index] != 0)
		{
			source_data[i] = (char)(index + 96);
			i++;
			key[index]--;
		}
	}
	return(source_data);
}

vector<int> Bogosort(vector<int> source_data)
{
	int carman,random;
	while (!is_sorter(source_data))
	{
			for (int i = 0; i < size(source_data) - 1; i++)
			{
				carman = source_data[i];
				random = rand() % size(source_data);
				source_data[i] = source_data[random];
				source_data[random] = carman;
			}
	}
	return(source_data);
}
vector<int> InsertionSort(vector<int> source_data)
{
	int carman, i2;
	for (int i = 1; i < size(source_data) - 1; i++)
	{
		i2 = i;
		carman = source_data[i];
		while (source_data[i2-1] > carman)
		{
			source_data[i2] = source_data[i2 - 1];
			i2--;
			if (i2 == 0)
				break;
		}
		source_data[i2] = carman;
	}
	return(source_data);
}

vector<int> QuickSort(vector<int> &source_data, int begin, int end)
{
	int t, c, i;
	int right = end, left = begin, support = source_data[begin];
	while (left < right)
	{
		while ((source_data[right] >= support) && (left < right))
			right--;
		if (left != right)
		{
			source_data[left] = source_data[right];
			left++;
		}
		while ((source_data[left] <= support) && (left < right))
			left++;
		if (left != right)
		{
			source_data[right] = source_data[left];
			right--;
		}
	}
	source_data[left] = support;
		if (begin < left)
			source_data = QuickSort(source_data, begin, right - 1);
		if (end > left)
			source_data = QuickSort(source_data, left + 1, end);
		return(source_data);
}
int BinarySearch(int number, vector<int> a)
{
	int end,begin=0;
	end = size(a)-1;
	while ((number > a[begin]) && (number < a[end]))
	{
		if (a[begin + (end - begin) / 2] < number)
		{

			begin = begin + (end - begin) / 2;
		}
		else 
		{
			end = begin + (end - begin) / 2;;
		}
		if ((a[end] > number) && (a[end - 1] < number))
		{
			cout << "error";
			return(-1);
			break;
		}
	}
	if (a[end] == number)
	return(end);
	if (a[begin] == number)
		return(begin);
}

int main()
{
	vector<int> array_int;
	vector<char> array_char;
	char letter;
	int s, w, k;
	int Random;
	time_t start, end;
	cout << "Вводите элементы списка, когда введёте все нажмите -0\n";
	cin >> s;
	while (s != -0)
	{
		array_int.push_back(s);
		cin >> s;
	}
	cin >> s;
	while (s != 0) //menu
	{
		switch (s) {
		case 1:
			cout << "Вводите элементы списка, когда введёте все нажмите -0\n";
			cin >> w;
			while (w != -0)
			{
				array_int.push_back(w);
				cin >> w;
			}
			cin >> w;
			cout << BinarySearch(w, array_int);
			break;
		case 2:
			cout << "kkkkk";
			array_int = QuickSort(array_int,0,size(array_int)-1);
			cout << '\n';
			for(int i = 0; i < size(array_int); i++)
				cout << array_int[i] << ' ';
			break;
		case 3:
			cout << "kkkkk";
			array_int = InsertionSort(array_int);
			cout << '\n';
			for (int i = 0; i < size(array_int); i++)
				cout << array_int[i] << ' ';
			break;
		case 4:
			cout << "fff";
			array_int = Bogosort(array_int);
			cout << '\n';
			for (int i = 0; i < size(array_int); i++)
				cout << array_int[i] << ' ';
			break;
		case 5:
			cout << "Вводите элементы списка, когда введёте все нажмите /\n";
			cin >> letter;
			while (letter != '/')
			{
				array_char.push_back(letter);
				cin >> letter;
			}
			cout << "fff";
			array_char = CountingSort(array_char);
			cout << '\n';
			for (int i = 0; i < size(array_char); i++)
				cout << array_char[i] << ' ';
			break;
		case 6:
			int k = 0,step = 1,start,end,i2;
			float time[2][5];
			while (k<5)
			{
				time[1][k] = 0;
				time[2][k] = 0;
				step = step * 10;
				array_int = (vector<int>)NULL;
				for (int i = 0; i < step; i++)
					array_int.push_back(rand() % 100);
				for (i2 = 0; i2 < 10; i2++)
				{
					for (int i = 0; i < step; i++)
						array_int[i] = rand() % 100;
					start = clock();
					array_int = QuickSort(array_int, 0, size(array_int) - 1);
					end = clock();
					time[1][k] = time[1][k] + ((float)(end - start) / CLOCKS_PER_SEC);
				}
				time[1][k] = time[1][k] / 10;
				cout << time[1][k] << '\n';
				for (i2 = 0; i2 < 10; i2++)
				{
					for (int i = 0; i < step; i++)
						array_int[i] = rand() % 100;
					start = clock();
					array_int = InsertionSort(array_int);
					end = clock();
					time[2][k] = time[2][k] + ((float)(end - start) / CLOCKS_PER_SEC);
				}
				time[2][k] = time[2][k] / 10;
				cout << time[2][k] << '\n';
				k++;
				cout << step << '\n';
			}
		

			break;
	}
		cin >> s;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

