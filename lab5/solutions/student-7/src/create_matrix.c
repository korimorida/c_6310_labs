#include "matrix.h"

matrix_t *create_matrix(int rows, int cols)
{
  matrix_t *m;
  int i;

  if (rows <= 0 || cols <= 0)
    return (NULL);

  m = malloc(sizeof(matrix_t));
  if (!m)
    return (NULL);

  m->rows = rows;
  m->cols = cols;

  m->matrix = malloc(sizeof(int *) * rows);
  if (!m->matrix)
    return (free(m), NULL);

  i = 0;
  while (i < rows)
  {
    m->matrix[i] = malloc(sizeof(int) * cols);
    if (!m->matrix[i])
    {
      while (--i >= 0)
        free(m->matrix[i]);
      free(m->matrix);
      free(m);
      return (NULL);
    }
    i++;
  }
  return (m);
}