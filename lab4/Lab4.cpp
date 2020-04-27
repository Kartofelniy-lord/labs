// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

int BSearch1(int value, int* startArray, int left, int right) {
	bool flag = false;
	int mid;

	while ((left <= right) && (flag != true)) {
		mid = (left + right) / 2; 

		if (startArray[mid] == value) {
			flag = true;
		} 
		if (startArray[mid] > value) {
			right = mid - 1;
		} 
		else {
			left = mid + 1;
		}
	}

	if (flag) {
		cout << "Число найдено" << endl;
		return mid;
	}
	else {
		cout << "Извините, но такого элемента в массиве нет";
		return -1;
	}
}

int BSearch2(int arr[], int value, int left, int right) { 
	int m = (left + right) / 2;
	if (arr[m] == value) {
		cout << "Число найдено" << endl;
		return m;
	}
	if (m == left || m == right) { 
		cout << "Извините, но такого элемента в массиве нет";
		return -1;
	}
	if (arr[m] < value) BSearch2(arr, value, m, right - 1); 
	else BSearch2(arr, value, left, m - 1);
}

void QuickSort1(int* startArray, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = startArray[(f + l) / 2];
	do
	{
		while (startArray[f] < mid) f++;
		while (startArray[l] > mid) l--;
		if (f <= l)
		{
			count = startArray[f];
			startArray[f] = startArray[l];
			startArray[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) QuickSort1(startArray, first, l);
	if (f < last) QuickSort1(startArray, f, last);
}

int Search(int *startArray, int searchingNumber) {
	for (int i = 0; i < 10000; i++)
	{
		if (startArray[i] == searchingNumber) {
			cout << "Число нашлось" << endl;
			return i;
		}
	}
	cout << "Такого числа нет" << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	const int size = 100000;
    int array[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = -1000 + rand() % ((1000 + 1) + 1000);
	}
	clock_t start, end;
	start = clock();
	Search(array, 255);
	end = clock();
	cout << "Время поиска неотсортированного массива линейным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;

    QuickSort1(array, 0, size - 1);

	BSearch2(array, 255, 0, size - 1);
	BSearch2(255, array, 0, size - 1);

	start = clock();
	Search(array, 255);
	end = clock();
	cout << "Время поиска неотсортированного массива линейным поиском: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;
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
