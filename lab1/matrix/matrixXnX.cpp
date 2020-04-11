#include <cstdint>
#include <xutility>
#include <iostream>

class MatrixXnX {
	int** array;
	int size = 0;
	public:
	MatrixXnX(const int iDim) {
		array = new int* [iDim];
		for (int i = 0; i < iDim; i++)
		{
			array[i] = new int[iDim];
		}
		for (int count_row = 0; count_row < iDim; count_row++) {
			for (int count_column = 0; count_column < iDim; count_column++) {
				array[count_row][count_column] = 0;
			}
		}
		size = iDim;
	}

	int element(const int i, const int j) const {
		return array[i][j];
	}

	void setElement(const int i, const int j, const int value) {
		array[i][j] = value;
	}

	void fillRandomElements(const int minVal, const int maxVal) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
			{
				array[i][j] = rand() % (maxVal - minVal + 1) + minVal;
			}
		}
	}

	int sumPrincipalDiag() const {
		int count = 0;
		for (int i = 0; i < size; i++) {
			count += array[i][i];
		}
		return count;
	}

	int sumSecondaryDiag() {
		int count = 0;
		for (int i = 0; i < size; i++) {
			count += array[i][size - 1 - i];
		}
		return count;
	}

	int productPrincipalDiag() {
		int count = 1;
		for (int i = 0; i < size; i++) {
			count *= array[i][i];
		}
		return count;
	}

	int productSecondaryDiag() {
		int count = 1;
		for (int i = 0; i < size; i++) {
			count *= array[i][size - 1 - i];
		}
		return count;
	}

	int sumRow(const int iRow) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			count += array[iRow][i];
		}
		return count;
	}

	int minColumn(const int iCol) {
		int min = INT32_MAX;
		for (int i = 0; i < size; i++) {
			min = array[i][i] < min ? array[iCol][i] : min;
			min = array[i][iCol] < min ? array[i][iCol] : min;
		}
		return min;
	}

	int maxColumn(const int iCol) {
		int max = INT32_MIN;
		for (int i = 0; i < size; i++) {
			max = array[i][iCol] > max ? array[i][iCol] : max;
		}
		return max;
	}

	void deleteArray() {
		delete[] array;
		array = nullptr;
	}
};
