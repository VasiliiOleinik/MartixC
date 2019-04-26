// HelloMatrix.cpp:
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::setw;
using std::swap;

int _tmain(int argc, _TCHAR *argv[])
{
	const int M = 3;
	const int N = 5;
	// matrix declaration
	// int x [M] [N]; // rectangular
	// int z [M] [M]; // square

	// Initialization of matrices
	int z[M][N] = {
		{2, 5, 8, 7, 9},
		{5, 9, 0, 1, 2},
		{6, 7, 1, 9, 8}};

	// int q [M] [N] = {
	// 2, 5, 6, 7, 1,
	// 5, 9, 0, 1, 2,
	// 6, 7, 1, 9, 8
	//};

	//// Matrix is stored in memory by rows
	// int w [M] [N] = {
	// 2, 5, 6, 7, 1, 5, 9, 0, 1, 2, 6, 7, 1, 9, 8
	//};

	// int e [] [N] = {
	// {2, 5, 6, 7, 1},
	// {5, 9, 0, 1, 2},
	// {6, 7}
	//};

	// Typical algorithms for working with matrices

	// Display the matrix on the screen
	// name [line index] [column index]
	cout << "\nMatrix:\n";
	for (int i = 0; i < M; i++)
	{
		// Display line items
		for (int j = 0; j < N; j++)
		{
			cout << setw(5) << z[i][j];
		} // for j
		cout << "\n";
	} // for i
	cout << "\n";

	// Sum of matrix elements
	int s = 0;
	for (int i = 0; i < M; i++)
	{
		// Summation of elements
		for (int j = 0; j < N; j++)
		{
			s += z[i][j];
		} // for j
	}	 // for i
	cout << "s = " << s << "\n";

	// number of odd elements of the matrix
	int k = 0;
	for (int i = 0; i < M; i++)
	{
		// Number of elements odd
		for (int j = 0; j < N; j++)
		{
			if (z[i][j] % 2 != 0)
				k++;
		} // for j
	}	 // for i
	cout << "k = " << k << "\n";

	// maximum and minimum matrix elements
	int min, max;
	int imin, jmin, imax, jmax;
	imin = jmin = imax = jmax = 0;
	min = max = z[0][0];

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (z[i][j] < min)
			{
				min = z[i][j];
				imin = i;
				jmin = j;
			} // if
			if (z[i][j] > max)
			{
				max = z[i][j];
				imax = i;
				jmax = j;
			} // if
		}	 // for j
	}		  // for i
	cout << "max = " << max << "[" << imax << "][" << jmax << "]\n";
	cout << "min = " << min << "[" << imin << "][" << jmin << "]\n";

	// Swap 2 columns jmin and jmax
	for (int i = 0; i < M; i++)
		swap(z[i][jmin], z[i][jmax]);

	cout << "\nMatrix 1:\n";
	for (int i = 0; i < M; i++)
	{
		// Display line items
		for (int j = 0; j < N; j++)
		{
			cout << setw(5) << z[i][j];
		} // for j
		cout << "\n";
	} // for i
	cout << "\n";

	// Swap 2 lines 0 and M-1
	int i0 = 0, i1 = M - 1;
	for (int j = 0; j < N; j++)
		swap(z[i0][j], z[i1][j]);

	cout << "\nMatrix 2:\n";
	for (int i = 0; i < M; i++)
	{
		// Display line items
		for (int j = 0; j < N; j++)
		{
			cout << setw(5) << z[i][j];
		} // for j
		cout << "\n";
	} // for i
	cout << "\n";

	// matrix sorting - 0th column elements - ascending
	for (int j = 0; j < N; j++)
	{
		for (int jj = 0; jj < N - j - 1; jj++)
		{
			if (z[0][jj] > z[0][jj + 1])
			{
				// Swap the jj and jj + 1 column
				for (int i = 0; i < M; i++)
					swap(z[i][jj], z[i][jj + 1]);
			}
		} // for jj
	}	 // for j

	cout << "\nMatrix 3:\n";
	for (int i = 0; i < M; i++)
	{
		// Display line items
		for (int j = 0; j < N; j++)
		{
			cout << setw(5) << z[i][j];
		} // for j
		cout << "\n";
	} // for i
	cout << "\n";

	return 0;
}
