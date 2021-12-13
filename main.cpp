#include <iostream>
#include <Windows.h>
#include "SelfOrganizingList.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    int l=0,c=0;
    SelfOrganizingList<int>* intList = new SelfOrganizingList<int>;
    SelfOrganizingList<char>* charList = new SelfOrganizingList<char>;
    SelfOrganizingList<double>* doubleList = new SelfOrganizingList<double>;
    cout << "Вводите список типа int(Ctrl+Z для конца ввода):\n";
    cin >> *intList;
    cin.clear();
    cout << "Вводите список типа char(Ctrl+Z для конца ввода):\n";
    cin >> *charList;
    cin.clear();
    cout << "Вводите список типа double(Ctrl+Z для конца ввода):\n";
    cin >> *doubleList;
    cin.clear();
    while (l != 4) {
        cout << "Выберите, с каким списком работать:\n";
        cout << "1. int.\n";
        cout << "2. char.\n";
        cout << "3. double.\n";
        cout << "4. Завершить работу программы.\n";
        cin >> l;
        switch (l) {
        case 1: {
            while (c != 7) {
                cout << "Выберите пункт меню:\n";
                cout << "1. Вывести список.\n";
                cout << "2. Очистить список.\n";
                cout << "3. Найти индекс элемента по значению.\n";
                cout << "4. Удалить все элементы с заданным значением.\n";
                cout << "5. Удалить элемент по индексу.\n";
                cout << "6. Добавить элемент в начало списка.\n";
                cout << "7. Вернуться в предыдущее меню.\n";
                cin >> c;
                switch (c) {
                case 1: {
                    cout << "Список типа int: " << *intList << '\n';
                    break;
                }
                case 2: {
                    intList->clear();
                    cout << "Список очищен.\n";
                    break;
                }
                case 3: {
                    cout << "Введите значение:\n";
                    int tmp;
                    cin >> tmp;
                    tmp = intList->findElemByVal(tmp);
                    if (tmp == -1) {
                        cout << "Такого элемента нет.\n";
                    }
                    else {
                        cout << "Индекс элемента - " << tmp<<'\n';
                    }
                    break;
                }
                case 4: {
                    cout << "Введите значение:\n";
                    int tmp;
                    cin >> tmp;
                    intList->deleteNodesByValue(tmp);
                    break;
                }
                case 5: {
                    cout << "Введите индекс:\n";
                    int tmp;
                    cin >> tmp;
                    intList->deleteNodeAt(tmp);
                    break;
                }
                case 6: {
                    cout << "Введите значение:\n";
                    int tmp;
                    cin >> tmp;
                    intList->addToHead(tmp);
                    break;
                }
                }
            }
            c = 0;
            break;
        }
        case 2: {
            while (c != 7) {
                cout << "Выберите пункт меню:\n";
                cout << "1. Вывести список.\n";
                cout << "2. Очистить список.\n";
                cout << "3. Найти индекс элемента по значению.\n";
                cout << "4. Удалить все элементы с заданным значением.\n";
                cout << "5. Удалить элемент по индексу.\n";
                cout << "6. Добавить элемент в начало списка.\n";
                cout << "7. Вернуться в предыдущее меню.\n";
                cin >> c;
                switch (c) {
                case 1: {
                    cout << "Список типа char: " << *charList << '\n';
                    break;
                }
                case 2: {
                    charList->clear();
                    cout << "Список очищен.\n";
                    break;
                }
                case 3: {
                    cout << "Введите значение:\n";
                    char tmp;
                    cin >> tmp;
                    tmp = charList->findElemByVal(tmp);
                    if (tmp == -1) {
                        cout << "Такого элемента нет.\n";
                    }
                    else {
                        cout << "Индекс элемента - " << tmp << '\n';
                    }
                    break;
                }
                case 4: {
                    cout << "Введите значение:\n";
                    char tmp;
                    cin >> tmp;
                    charList->deleteNodesByValue(tmp);
                    break;
                }
                case 5: {
                    cout << "Введите индекс:\n";
                    int tmp;
                    cin >> tmp;
                    charList->deleteNodeAt(tmp);
                    break;
                }
                case 6: {
                    cout << "Введите значение:\n";
                    char tmp;
                    cin >> tmp;
                    charList->addToHead(tmp);
                    break;
                }
                }
            }
            c = 0;
            break;
        }
        case 3: {
            while (c != 7) {
                cout << "Выберите пункт меню:\n";
                cout << "1. Вывести список.\n";
                cout << "2. Очистить список.\n";
                cout << "3. Найти индекс элемента по значению.\n";
                cout << "4. Удалить все элементы с заданным значением.\n";
                cout << "5. Удалить элемент по индексу.\n";
                cout << "6. Добавить элемент в начало списка.\n";
                cout << "7. Вернуться в предыдущее меню.\n";
                cin >> c;
                switch (c) {
                case 1: {
                    cout << "Список типа double: " << *doubleList << '\n';
                    break;
                }
                case 2: {
                    doubleList->clear();
                    cout << "Список очищен.\n";
                    break;
                }
                case 3: {
                    cout << "Введите значение:\n";
                    double tmp;
                    cin >> tmp;
                    tmp = doubleList->findElemByVal(tmp);
                    if (tmp == -1) {
                        cout << "Такого элемента нет.\n";
                    }
                    else {
                        cout << "Индекс элемента - " << tmp << '\n';
                    }
                    break;
                }
                case 4: {
                    cout << "Введите значение:\n";
                    double tmp;
                    cin >> tmp;
                    doubleList->deleteNodesByValue(tmp);
                    break;
                }
                case 5: {
                    cout << "Введите индекс:\n";
                    int tmp;
                    cin >> tmp;
                    doubleList->deleteNodeAt(tmp);
                    break;
                }
                case 6: {
                    cout << "Введите значение:\n";
                    double tmp;
                    cin >> tmp;
                    doubleList->addToHead(tmp);
                    break;
                }
                }
            }
            c = 0;
            break;
        }
        }
    }
    delete intList;
    delete charList;
    delete doubleList;
}
