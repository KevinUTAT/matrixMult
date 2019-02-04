#ifndef MULTIPLIER
#define MULTIPLIER

// this function perform a matrix multiplication. return a empty array if 
// multiplication is not possible
int** matrix_multiply
	(int** X, int** Y, int x_rows, int x_cols, int y_rows, int y_cols);


// X and Y are arrays of 3-elements arrays
// each element represents a non-zero term in the matrix
// in the form of {row, col, value}
// x_size and y_size represents the number of non-zero elements in the matrix
// the format of return value is unchanged for ease of testing
int** sparse_matrix_multiply
	(int** X, int** Y, int x_rows, int x_cols, int x_size, int y_rows, int y_cols, int y_size);

#endif