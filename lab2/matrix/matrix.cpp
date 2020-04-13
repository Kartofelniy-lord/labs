// matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Matrix3x3.cpp"
#include "MatrixXnX.cpp"
#include "LinkedList.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Задача 1.1
    cout << "Задача 1.1" << endl;;
    
    Matrix3x3 matrix;
    matrix.fillRandomElements(-10, 10);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << matrix.element(i, j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Сумма элементов строки " << i << " " << matrix.sumRow(i) << endl;
        cout << "Максимальный элемент столбца " << i << " " << matrix.maxColumn(i) << endl;
        cout << "Минимальный элемент столбца " << i << " " << matrix.minColumn(i) << endl;
    }

    cout << matrix.sumPrincipalDiag() << endl;
    cout << matrix.sumSecondaryDiag() << endl;
    cout << matrix.productPrincipalDiag() << endl;
    cout << matrix.productSecondaryDiag() << endl;

    cout << "_______________________________________________" << endl;
    // Задача 1.2
    cout << "Задача 1.2" << endl;;

    int size = 4;

    MatrixXnX matrix1(size);
    matrix1.fillRandomElements(-10, 10);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            cout << setw(3) << matrix1.element(i, j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Сумма элементов строки " << i << " " << matrix1.sumRow(i) << endl;
        cout << "Максимальный элемент столбца " << i << " " << matrix1.maxColumn(i) << endl;
        cout << "Минимальный элемент столбца " << i << " " << matrix1.minColumn(i) << endl;
    }

    cout << matrix1.sumPrincipalDiag() << endl;
    cout << matrix1.sumSecondaryDiag() << endl;
    cout << matrix1.productPrincipalDiag() << endl;
    cout << matrix1.productSecondaryDiag() << endl;

    matrix1.deleteArray();

    // Задача 2
    cout << "Задача 2" << endl;;
    List list;
    list.add('1');
    list.add('2');
    list.add('3');
    list.add('4');
    list.add('4');
    list.add('1');
    list.deleteDublicate();
    list.show();
}

