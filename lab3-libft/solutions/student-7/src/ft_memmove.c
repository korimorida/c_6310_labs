#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;

    if (!dest || !src)
        return (NULL);
    if (dest == src)
        return (dest);
    if (dest > src)
    {
        i = n;
        while (i > 0)
        {
            i--;
            ((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
        }
    }
    else
    {
        i = 0;
        while (i < n)
        {
            ((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
            i++;
        }
    }
    return (dest);
}
