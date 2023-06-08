#include <iostream>
#include <fstream>
#include <list>
#include <chrono>
#include "RBST.h"

void qsort(Client* arr, const int size)
{
    int left = 0;
    int right = size - 1;
    Client mid = arr[size / 2];

    do
    {
        while (arr[left] < mid) left++;

        while (arr[right] > mid)  right--;

        if (left <= right) std::swap(arr[left++], arr[right--]);
    } while (left <= right);

    if (right > 0) qsort(arr, right + 1);
    if (left < size) qsort(&arr[left], size - left);
}

void templ()
{
    system("cls");
    std::cout
        << "Template:\n"
        << "Name             [enter]\n"
        << "Deposit number   [enter]\n"
        << "Deposit amount   [enter]\n"
        << "Deposit duration [enter]\n\n";
}

void menu()
{
    int choice;
    const int CL_COUNT = 5;
    Client clients[CL_COUNT], to_find;
    std::ifstream fin;
    RBS_Tree* tree = new RBS_Tree(*clients);

    while (true)
    {
        do
        {
            std::cout
                << "[0] Exit\n"
                << "[1] The worst qsort case (file)\n"
                << "[2] Average qsort case   (file)\n"
                << "[3] The best qsort case  (file)\n"
                << "[4] Manual input\n"
                << "[5] Find an entry\n"
                << "[6] Delete an entry\n"
                << "[7] Sort\n"
                << "[8] Show all entries\n";

            std::cin >> choice;
        } while (choice < 0 || choice > 8);

        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            fin.open("the worst-case.txt");
            break;
        case 2:
            fin.open("average-case.txt");
            break;
        case 3:
            fin.open("the best-case.txt");
            break;
        case 4:
            templ();

            for (int i = 0; i < CL_COUNT; ++i)
            {
                std::cin >> clients[i];
                RBST::insert(tree, clients[i]);
            }
            break;
        case 5:
            templ();

            std::cin >> to_find;
            if (RBST::find(tree, to_find)) 
                std::cout << "Entry is found\n";
            else 
                std::cout << "Entry not found\n";
            break;
        case 6:
            templ();

            std::cin >> to_find;
            if (RBST::find(tree, to_find))
            {
                RBST::remove(tree, to_find);
                std::cout << "Entry is found and deleted\n";
            }
            else std::cout << "Entry not found\n";
            break;
        case 7:
            qsort(clients, CL_COUNT);
            break;
        case 8:
            for (Client cl : clients)
                std::cout << cl << '\n';
            break;
        }

        if (fin.is_open())
        {
            for (int i = 0; i < CL_COUNT; ++i) 
            {
                fin >> clients[i];
                RBST::insert(tree, clients[i]);
            }
            fin.close();
        }

        system("pause");
        system("cls");
    }
}

int main()
{
    /*
William Jones
5881 6977 3432 4277
3395733
1259
nigga
123
456
30

grgrgr
456
789
30

meow
789
123
789

vasya
159
753
89

cock
759
153
456
    const int CL_COUNT = 5;
    Client clients[CL_COUNT];
    Client find;

    std::string
        file_1 = "the worst-case.txt",
        file_2 = "average-case.txt",
        file_3 = "the best-case.txt";

    std::ifstream fin(file_2);

    for (int i = 0; i < CL_COUNT, fin >> clients[i]; ++i);

    qsort(clients, CL_COUNT);

    RBS_Tree* tree = new RBS_Tree(clients[0]);

    for (int i = 1; i < CL_COUNT; ++i)
        RBST::insert(tree, clients[i]);

    if (RBST::find(tree, find)) std::cout << "found\n";
    */

    menu();
    return 0;
}