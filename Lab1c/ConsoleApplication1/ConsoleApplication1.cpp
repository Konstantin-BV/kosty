// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <map>
#include "C:\Users\kosty\source\repos\Lab1c\ConsoleApplication1\RBtree.h"
using namespace std;

int main()
{
    RBtree Tree;
    string k,t;
    int i;
    int* r;
    cin >> k;
    t = k;
    while (k != "0")
    {
        cin >> i;
        Tree.InsertMap(k,i);
        Tree.Insert(NULL, Tree.root, k);
        cin >> k;
    }
    Tree.print(Tree.root);
    cout << "root" << Tree.associa.VALUE(Tree.root->key) << " " << endl;
    while (i != 0)
    {
        cin >> i;
        switch (i)
        {
        case 1:
            cout << "delet ";
            cin >> k;
            Tree.remove(Tree.find(k));
            break;
        case 2:
            cout << "find ";
            cin >> k;
            cout << Tree.associa.VALUE(Tree.find(k)->key) << " ";
            break;
        case 3:
            Tree.clear();
            break;
        case 4:
            Tree.get_keys(Tree.root);
            break;
        case 5:
            Tree.get_values(Tree.root);
            break;
        case 6:
            Tree.print(Tree.root);
            break;
        }
    }

    
    Tree.print(Tree.root);

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
