#include "matrix.h"

matrix_t *mult_matrix(matrix_t *A, matrix_t *B)
{
  matrix_t *C;
  int i, j, k;

  if (!A || !B || A->cols != B->rows)
	  return (NULL);

  C = create_matrix(A->rows, B->cols);
  if (!C)
    return (NULL);

  i = 0;
  while (i < A->rows)
  {
    j = 0;
    while (j < B->cols)
    {
      C->matrix[i][j] = 0;
      k = 0;
      while (k < A->cols)
      {
        C->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        k++;
      }
      j++;
    }
    i++;
  }
  return (C);
}