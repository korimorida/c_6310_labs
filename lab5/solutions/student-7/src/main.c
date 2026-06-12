#include "matrix.h"

int main(void)
{
  matrix_t *A;
  matrix_t *B;
  matrix_t *C;

  A = create_matrix(2, 3);
  B = create_matrix(3, 2);

  if (!A || !B)
    return (1);

  A->matrix[0][0] = 1;
  A->matrix[0][1] = 2;
  A->matrix[0][2] = 3;
  A->matrix[1][0] = 4;
  A->matrix[1][1] = 5;
  A->matrix[1][2] = 6;

  B->matrix[0][0] = 7;
  B->matrix[0][1] = 8;
  B->matrix[1][0] = 9;
  B->matrix[1][1] = 10;
  B->matrix[2][0] = 11;
  B->matrix[2][1] = 12;

  C = mult_matrix(A, B);

  print_matrix(C);

  remove_matrix(A);
  remove_matrix(B);
  remove_matrix(C);

  return (0);
}