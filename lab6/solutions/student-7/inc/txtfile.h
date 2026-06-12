#ifndef TXTFILE_H
# define TXTFILE_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);
char	**replace_substr(char **lines, const char *old, const char *new_str);

char    *ft_strndup(const char *s, size_t n);
char    *ft_strjoin_free(char *s1, char *s2);
char    **ft_realloc_matrix(char **old, int new_size);

#endif