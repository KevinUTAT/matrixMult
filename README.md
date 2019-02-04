# Matrix Multiplication
In *multiplier.c* and *multiplier.h* \
This program contains two important function: \
*matrix_multiply* and *sparse_matrix_multiply* \
They both perform the same task: Matrix Multiplication X x Y = Z \
The first one use dense algorithm, the second one use sparse algorithm

# Dense algorithm 
This algorithm start with every cell in the final answer \
answer Z[r][c] = rth Row in X inner product with cth Column in Y. \
The complexity is O(x_rows * y_cols * x_cols). \
\
In this case, X, Y, Z are represented as it is

# Sparse algorithm
This algorithm start with X and Y \
Every X[x][i] multiply Y[i][y] will be a part of summation of answer Z[x][y] \
Therefore, we start with a Z that is all zero, and add every X[x][i] multiply Y[i][y] \
to it. \
The complexity is O(x_size * y_size) \
when X and Y are sparse, this is a much lower complexity \
\
In this case X and Y are represented differently: \
they are arrays of non-zero value with its coordinate \
in the form of {row, col, value} \
and X and Y looks like {{row0, col0, value0}, {row1, col1, value1}, ... } \
This avoids storing zero value element in memory \
for ease of testing, the representation of Z is unchanged.