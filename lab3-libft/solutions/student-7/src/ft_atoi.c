#include "libft.h"

int ft_atoi(const char *nptr)
{
    long result;
    int sign;

    if (!nptr)
        return (0);
    result = 0;
    sign = 1;
    while (ft_isspace((unsigned char)*nptr))
        nptr++;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9')
    {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }
    return ((int)(result * sign));
}
