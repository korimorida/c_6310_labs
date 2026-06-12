#include "stats.h"

/* Вывод ошибки в stderr и возвращает 1 */
int print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

/* Проверяет, является ли строка валидным числом */
int is_valid_number(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (str[i] == '\0') // только знак, без цифр
		return (0);
	for (; str[i]; i++)
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
	return (1);
}

/* Преобразует метрику по имени в код METRIC_* */
int get_metric_code(char *name)
{
	if (!name)
		return (-1);
	if (ft_strncmp(name, "min", 4) == 0)
		return METRIC_MIN;
	if (ft_strncmp(name, "max", 4) == 0)
		return METRIC_MAX;
	if (ft_strncmp(name, "sum", 4) == 0)
		return METRIC_SUM;
	if (ft_strncmp(name, "avg", 4) == 0)
		return METRIC_AVG;
	return (-1);
}