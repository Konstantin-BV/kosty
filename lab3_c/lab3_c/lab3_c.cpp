// lab3_c.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

int main()
{
    std::string line,s,s1;
    std::string line1[4];
    List III;
    int cost1;
    int cost2;
    std::ifstream in("text.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        int l = 0;
        while (getline(in, line))
        {
            std::cout << line << std::endl;
            int i = 0,j=0;
            for (i = 0; i < line.size(); i++)
            {
                
                if (line[i] ==';')
                {
                    l++;
                    i++;
                }
                line1[l].push_back(line[i]);
            }
            l = 0;
            if (line1[2] != "N/A")
                cost1 = stoi(line1[2]);
            else
                cost1 = INT_MAX;
            if (line1[3] != "N/A")
                cost2 = stoi(line1[3]);
            else
                cost2 = INT_MAX;
            III.Insert(line1[0], line1[1], stoi(line1[2]), stoi(line1[3]));
            for (i = 0; i < 4; i++)
            {
                line1[i] = "";
            }
        }
    }
    in.close();     // закрываем файл
    std::cin >> s;
    std::cin >> s1;
    III.the_happy_begin(s,s1);
    std::cout << III.checking() << endl;
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
