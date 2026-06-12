#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char ch;
    char *last;
    size_t i;

    if (!s)
        return (NULL);
    ch = (char)c;
    last = NULL;
    i = 0;
    while (s[i])
    {
        if (s[i] == ch)
            last = (char *)&s[i];
        i++;
    }
    if (ch == '\0')
        return ((char *)&s[i]);
    return (last);
}
