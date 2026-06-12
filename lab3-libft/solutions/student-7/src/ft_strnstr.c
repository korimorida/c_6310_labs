#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    if (!big || !little)
        return (NULL);
    if (!little[0])
        return ((char *)big);
    i = 0;
    while (big[i] && i < len)
    {
        if (big[i] == little[0])
        {
            j = 0;
            while (little[j] && big[i + j] && i + j < len && big[i + j] == little[j])
                j++;
            if (!little[j])
                return ((char *)&big[i]);
        }
        i++;
    }
    return (NULL);
}
