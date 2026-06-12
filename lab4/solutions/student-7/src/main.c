#include "stats.h"

int main(int argc, char **argv)
{
	int metric;
	int i, count;
	int *numbers;

	if (argc < 3)
		return print_error("Error: not enough arguments\n");

	metric = get_metric_code(argv[1]);
	if (metric == -1)
		return print_error("Error: unknown metric\n");

	count = argc - 2;
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return print_error("Error: malloc failed\n");

	for (i = 0; i < count; i++)
	{
		if (!is_valid_number(argv[i + 2]))
		{
			free(numbers);
			return print_error("Error: invalid number\n");
		}
		numbers[i] = ft_atoi(argv[i + 2]);
	}

	ft_putnbr_fd(compute(metric, count,
		numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]), 1);
	ft_putchar_fd('\n', 1);

	free(numbers);
	return 0;
}