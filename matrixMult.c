// matrixMult.cpp : Defines the entry point for the console application.
//
#include "multiplier.h"
#include <stdlib.h>


int main()
{
	int row;
	int col;
	/*
	int array0[2][4] = {
					{1, 3, 5, 7},
					{2, 4, 6, 8}
					};
					*/
	int array0[8][3] = { {0, 0, 1},
	{0, 1, 3},
	{0, 2, 5},
	{0, 3, 7},
	{1, 0, 2},
	{1, 1, 4},
	{1, 2, 6},
	{1, 3, 8} };
	int** matrix0;
	matrix0 = (int**)malloc(8 * sizeof(int*));
	for (row = 0; row < 8; row++)
	{
		matrix0[row] = (int*)malloc(3 * sizeof(int));
		for (col = 0; col < 3; col++)
		{
			matrix0[row][col] = array0[row][col];
		}
	}

	/*
	int array1[4][3] = {
					{1, 8, 9},
					{2, 7, 10},
					{3, 6, 11},
					{4, 5, 12}
					};*/
	int array1[12][3] = { {0, 0, 1},
	{0, 1, 8},
	{0, 2, 9},
	{1, 0, 2},
	{1, 1, 7},
	{1, 2, 10},
	{2, 0, 3},
	{2, 1, 6},
	{2, 2, 11},
	{3, 0, 4},
	{3, 1, 5},
	{3, 2, 12} };
	int** matrix1;
	matrix1 = (int**)malloc(12 * sizeof(int*));
	for (row = 0; row < 12; row++)
	{
		matrix1[row] = (int*)malloc(3 * sizeof(int));
		for (col = 0; col < 3; col++)
		{
			matrix1[row][col] = array1[row][col];
		}
	}
	int array2[2][3] = {
					{50, 94, 178},
					{60, 120, 220}
					};
	int** matrix2;
	matrix2 = (int**)malloc(2 * sizeof(int*));
	for (row = 0; row < 2; row++)
	{
		matrix2[row] = (int*)malloc(3 * sizeof(int));
		for (col = 0; col < 3; col++)
		{
			matrix2[row][col] = array2[row][col];
		}
	}
	int** answer = sparse_matrix_multiply(matrix0, matrix1, 2, 4, 8, 4, 3, 12);

	// check the answer
	for (row = 0; row < 2; row++)
	{
		for (col = 0; col < 3; col++)
		{
			int expexted = matrix2[row][col];
			int instead = answer[row][col];
			if (expexted != instead)
			{
				return 1;
			}
		}
	}

    return 0;
}

