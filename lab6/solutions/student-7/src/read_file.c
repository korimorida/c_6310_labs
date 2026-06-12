#include "txtfile.h"
#include <fcntl.h>
#include <unistd.h>

static char	*read_line(int fd)
{
	char	*buf;
	char	c;
	int		ret;

	buf = ft_calloc(1, 1); // пустая строка
	if (!buf)
		return (NULL);

	while ((ret = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			break ;
		buf = ft_strjoin_free(buf, ft_strndup(&c, 1));
		if (!buf)
			return (NULL);
	}
	if (ret < 0)
	{
		free(buf);
		return (NULL);
	}
	if (ret == 0 && ft_strlen(buf) == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	**read_file(const char *filename)
{
	int		fd;
	char	*line;
	char	**lines;
	int		count;

	if (!filename)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);

	lines = ft_calloc(1, sizeof(char *)); // массив строк
	if (!lines)
		return (NULL);

	count = 0;
	while (1)
	{
		line = read_line(fd);
		if (!line)
			break ;
		lines = ft_realloc_matrix(lines, count + 2); // +1 строка +1 NULL
		if (!lines)
		{
			free(line);
			close(fd);
			return (NULL);
		}
		lines[count++] = line;
		lines[count] = NULL;
	}
	close(fd);
	return (lines);
}