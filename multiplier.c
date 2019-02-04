#include "multiplier.h"
#include <stdlib.h>
#include <malloc.h>

int** matrix_multiply
	(int** X, int** Y, int x_rows, int x_cols, int y_rows, int y_cols)
{
	// Check for legality, two matrix can only multiply 
	// when x_cols = y_rows
	if (x_cols != y_rows)
	{
		int** empty_array = NULL;
		return empty_array;
	}

	// size of the product should be x_rows by y_cols
	int** product;
	int row;
	int col;
	product = (int**)malloc(x_rows * sizeof(int*));
	for (row = 0; row < x_rows; row ++)
	{
		product[row] = (int*)malloc(y_cols * sizeof(int));
	}

	// now we compute
	for (row = 0; row < x_rows; row++)
	{
		for (col = 0; col < y_cols; col++)
		{
			int sum = 0;
			int i;
			for (i = 0; i < x_cols; i++)
			{
				sum += X[row][i] * Y[i][col];
			}
			product[row][col] = sum;
		}
	}


	return product;
}


int** sparse_matrix_multiply
	(int** X, int** Y, int x_rows, int x_cols, int x_size, int y_rows, int y_cols, int y_size)
{
	// the preparation of answer do not change in sparse case
	if (x_cols != y_rows)
	{
		int** empty_array = NULL;
		return empty_array;
	}

	int** product;
	int row;
	int col;
	product = (int**)malloc(x_rows * sizeof(int*));
	for (row = 0; row < x_rows; row++)
	{
		product[row] = (int*)malloc(y_cols * sizeof(int));
	}

	// initialize answer to all zero
	for (row = 0; row < x_rows; row++)
	{
		for (col = 0; col < y_cols; col++)
		{
			product[row][col] = 0;
		}
	}

	int x;
	int y;
	for (x = 0; x < x_size; x++)
	{
		for (y = 0; y < y_size; y++)
		{
			if (X[x][1] == Y[y][0])
			{
				product[X[x][0]][Y[y][1]] += X[x][2] * Y[y][2];
			}
		}
	}

	return product;
}