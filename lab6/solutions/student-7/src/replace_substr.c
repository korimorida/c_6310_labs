#include "txtfile.h"

static char	*replace_in_line(const char *line, const char *old, const char *new_str)
{
	int		i, j, k;
	int		len_old, len_new;
	int		count;
	char	*res;

	if (!line || !old || !new_str)
		return (ft_strdup(line));

	len_old = ft_strlen(old);
	len_new = ft_strlen(new_str);
	count = 0;

	// считаем сколько замен
	i = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], old, len_old) == 0)
		{
			count++;
			i += len_old;
		}
		else
			i++;
	}

	res = ft_calloc(ft_strlen(line) + count * (len_new - len_old) + 1, 1);
	if (!res)
		return (NULL);

	i = 0;
	k = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], old, len_old) == 0)
		{
			j = 0;
			while (j < len_new)
				res[k++] = new_str[j++];
			i += len_old;
		}
		else
			res[k++] = line[i++];
	}
	return (res);
}

char	**replace_substr(char **lines, const char *old, const char *new_str)
{
	int		i;
	char	**new_lines;

	if (!lines || !old || !new_str)
		return (NULL);

	i = 0;
	while (lines[i])
		i++;

	new_lines = ft_calloc(i + 1, sizeof(char *));
	if (!new_lines)
		return (NULL);

	i = 0;
	while (lines[i])
	{
		new_lines[i] = replace_in_line(lines[i], old, new_str);
		if (!new_lines[i])
		{
			free_lines(new_lines);
			return (NULL);
		}
		i++;
	}
	return (new_lines);
}