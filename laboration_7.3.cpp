#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void Rotate_Right(int** a, const int rowCount, const int colCount, int x);
void Rotate_Down(int** a, const int rowCount, const int colCount, int x);
int Row_With_Zeroes(int** a, const int rowCount, const int colCount);
void User_Choice(int** a, const int rowCount, const int colCount, int user_choice, int x);

int main()
{
	int rowCount, colCount;
	int x;
	cout << " X = "; cin >> x;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int Row_With_Max_Count_Of_Zeros = Row_With_Zeroes(a, rowCount, colCount);
	cout << "Row_With_Count_Of_Zeros = " << Row_With_Max_Count_Of_Zeros << endl;

	int user_choice;
	cout << "Choose what method you want: ";  cin >> user_choice;

	User_Choice(a, rowCount, colCount, user_choice, x);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Rotate_Right(int** a, const int rowCount, const int colCount, int x) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < x; j++) {
			int temp = a[i][colCount - 1];
			for (int l = colCount - 1; l > 0; l--) {
				a[i][l] = a[i][l - 1];
			}
			a[i][0] = temp;
		}
	}
}

void Rotate_Down(int** a, const int rowCount, const int colCount, int x) {
	for (int j = 0; j < colCount; j++) {
		for (int i = 0; i < x; i++) {
			int temp = a[rowCount - 1][j];
			for (int l = rowCount - 1; l > 0; l--) {
				a[l][j] = a[l - 1][j];
			}
			a[0][j] = temp;
		}
	}
}

int Row_With_Zeroes(int** a, const int rowCount, const int colCount)
{
	int max_count_of_zero = 0;
	int rowIndex = -1;

	for (int i = 0; i < rowCount; i++) {
		int Count_of_Zero = 0;  //Lichilnik 0
		
		for (int j = 0; j < colCount; j++) {
			if (a[i][j] == 0) {
				Count_of_Zero++;
			}
		}

		if (Count_of_Zero > max_count_of_zero) {
			max_count_of_zero = Count_of_Zero;
			rowIndex = i;
		}
	}
	
	return rowIndex;
}

void User_Choice(int** a, const int rowCount, const int colCount, int user_choice, int x) {
	if (user_choice == 1) {
		Rotate_Down(a, rowCount, colCount, x);
	}
	else {
		Rotate_Right(a, rowCount, colCount, x);
	}

	Print(a, rowCount, colCount);
} 