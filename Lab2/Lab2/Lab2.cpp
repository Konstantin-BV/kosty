// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Tree.h"
#include "List.h"
using namespace std;
int main()
{
    List C;
    Tree T;
    string s; 
    int Memory = 0;
    getline(std::cin, s);
    C.root = NULL;
    for (int i = 0; s[i] != '\0'; i++)
    {
        C.push_back(s[i]);
        Memory = Memory + 8;
    }
    T.create_list(C);
    while (T.nodes.root->Next)
    {
        T.push_node();
    }
    T.node_path(T.nodes.root->Right,"\0", "1");
    T.node_path(T.nodes.root->left, "\0", "0");
    for (int i = 0; s[i] != '\0'; i++)
    {
        T.print_s(T.nodes.root,s[i]);
    }
    cout << endl;
    for (int i = 0; s[i] != '\0'; i++)
    {
        T.print_weight(T.nodes.root, s[i]);
    }
    cout << endl << "Memore was " << Memory << endl;
    cout << "Memore became " << T.Memory << endl;
    cout << "compression ratio " << (double)Memory/T.Memory;
    while (s != "12")
    {
        cout << endl;
        cin >> s;
        T.print_ch(T.nodes.root, s, 0);
    }
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
