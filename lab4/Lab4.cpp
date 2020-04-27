// Lab4.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
		cout << "����� �������" << endl;
		return mid;
	}
	else {
		cout << "��������, �� ������ �������� � ������� ���";
		return -1;
	}
}

int BSearch2(int arr[], int value, int left, int right) { 
	int m = (left + right) / 2;
	if (arr[m] == value) {
		cout << "����� �������" << endl;
		return m;
	}
	if (m == left || m == right) { 
		cout << "��������, �� ������ �������� � ������� ���";
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
			cout << "����� �������" << endl;
			return i;
		}
	}
	cout << "������ ����� ���" << endl;
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
	cout << "����� ������ ������������������ ������� �������� �������: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;

    QuickSort1(array, 0, size - 1);

	BSearch2(array, 255, 0, size - 1);
	BSearch2(255, array, 0, size - 1);

	start = clock();
	Search(array, 255);
	end = clock();
	cout << "����� ������ ������������������ ������� �������� �������: " << (((double)end - start) / ((double)CLOCKS_PER_SEC)) << endl;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
