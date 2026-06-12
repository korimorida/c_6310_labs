#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    if (s)
        ft_memset(s, 0, n);
}
