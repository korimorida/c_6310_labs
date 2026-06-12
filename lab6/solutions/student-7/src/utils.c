#include "txtfile.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	i;

	res = malloc(n + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	size_t	len1, len2;
	size_t	i, j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	**ft_realloc_matrix(char **matrix, int new_size)
{
	char	**new_matrix;
	int		i;

	new_matrix = ft_calloc(new_size, sizeof(char *));
	if (!new_matrix)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = matrix[i];
		i++;
	}
	free(matrix);
	return (new_matrix);
}