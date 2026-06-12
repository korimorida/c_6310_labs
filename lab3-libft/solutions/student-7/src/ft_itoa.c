#include "libft.h"

static int count_digits(long n)
{
    int digits;

    if (n == 0)
        return (1);
    digits = 0;
    if (n < 0)
        n = -n;
    while (n > 0)
    {
        n /= 10;
        digits++;
    }
    return (digits);
}

char *ft_itoa(int n)
{
    long value;
    int digits;
    int negative;
    char *str;

    value = n;
    negative = 0;
    if (value < 0)
    {
        negative = 1;
        value = -value;
    }
    digits = count_digits(value) + negative;
    str = malloc(digits + 1);
    if (!str)
        return (NULL);
    str[digits] = '\0';
    if (value == 0)
        str[0] = '0';
    while (value > 0)
    {
        str[--digits] = (char)('0' + (value % 10));
        value /= 10;
    }
    if (negative)
        str[0] = '-';
    return (str);
}
