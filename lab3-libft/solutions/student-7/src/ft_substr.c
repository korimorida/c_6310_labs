#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t source_len;
    char *substr;
    size_t i;

    if (!s)
        return (NULL);
    source_len = ft_strlen(s);
    if ((size_t)start >= source_len)
        return (ft_strdup(""));
    if (len > source_len - start)
        len = source_len - start;
    substr = malloc(len + 1);
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}
