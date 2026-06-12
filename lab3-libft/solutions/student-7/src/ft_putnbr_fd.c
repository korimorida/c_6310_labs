#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    long value;
    char c;

    if (fd < 0)
        return;
    value = n;
    if (value < 0)
    {
        write(fd, "-", 1);
        value = -value;
    }
    if (value >= 10)
        ft_putnbr_fd((int)(value / 10), fd);
    c = (char)('0' + (value % 10));
    write(fd, &c, 1);
}
