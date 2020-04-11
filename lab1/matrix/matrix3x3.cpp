#pragma once
//#include "matrix3x3.h"
#include <cstdint>
#include <xutility>
#include <iostream>
using namespace std;
class Matrix3x3
{
	int array[3][3] = { 0 };
    public :
	Matrix3x3() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				array[i][j] = 0;
			}
		}
	}

	int element(const int i, const int j) const {
		return array[i][j];
	}

	void setElement(const int i, const int j, const int value) {
		array[i][j] = value;
	}

	void fillRandomElements(const int minVal, const int maxVal) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				array[i][j] = rand() % (maxVal - minVal + 1) + minVal;
			}
		}
	}

	int sumPrincipalDiag() const {
		int count = 0;
		for (int i = 0; i < 3; i++) {
			count += array[i][i];
		}
		return count;
	}

	int sumSecondaryDiag() {
		int count = 0;
		for (int i = 0; i < 3; i++) {
			count += array[i][2 - i];
		}
		return count;
	}

	int productPrincipalDiag() {
		int count = 1;
		for (int i = 0; i < 3; i++) {
			count *= array[i][i];
		}
		return count;
	}

	int productSecondaryDiag() {
		int count = 1;
		for (int i = 0; i < 3; i++) {
			count *= array[i][2 - i];
		}
		return count;
	}

	int sumRow(const int iRow) {
		int count = 0;
		for (int i = 0; i < 3; i++) {
			count += array[iRow][i];
		}
		return count;
	}

	int minColumn(const int iCol) {
		int min = INT32_MAX;
		for (int i = 0; i < 3; i++) {
			min = array[i][i] < min ? array[iCol][i] : min;
			min = array[i][iCol] < min ? array[i][iCol] : min;
		}
		return min;
	}

	int maxColumn(const int iCol) {
		int max = INT32_MIN;
		for (int i = 0; i < 3; i++) {
			max = array[i][iCol] > max ? array[i][iCol] : max;
		}
		return max;
	}
};