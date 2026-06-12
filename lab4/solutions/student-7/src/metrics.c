#include "stats.h"

int metric_min(int count, ...)
{
	va_list args;
	int i, value, min;

	if (count <= 0)
		return (0);
	va_start(args, count);
	min = va_arg(args, int);
	for (i = 1; i < count; i++)
	{
		value = va_arg(args, int);
		if (value < min)
			min = value;
	}
	va_end(args);
	return (min);
}

int metric_max(int count, ...)
{
	va_list args;
	int i, value, max;

	if (count <= 0)
		return (0);
	va_start(args, count);
	max = va_arg(args, int);
	for (i = 1; i < count; i++)
	{
		value = va_arg(args, int);
		if (value > max)
			max = value;
	}
	va_end(args);
	return (max);
}

int metric_sum(int count, ...)
{
	va_list args;
	int i, sum;

	sum = 0;
	va_start(args, count);
	for (i = 0; i < count; i++)
		sum += va_arg(args, int);
	va_end(args);
	return (sum);
}

int metric_avg(int count, ...)
{
	va_list args;
	int i, sum;

	if (count <= 0)
		return (0);
	sum = 0;
	va_start(args, count);
	for (i = 0; i < count; i++)
		sum += va_arg(args, int);
	va_end(args);
	return (sum / count);
}

int compute(int metric, int count, ...)
{
	va_list args;
	int i, value, result;

	if (count <= 0)
		return (0);
	va_start(args, count);
	if (metric == METRIC_MIN || metric == METRIC_MAX)
		result = va_arg(args, int);
	else
		result = 0;
	i = (metric == METRIC_MIN || metric == METRIC_MAX) ? 1 : 0;
	for (; i < count; i++)
	{
		value = va_arg(args, int);
		if (metric == METRIC_MIN && value < result)
			result = value;
		else if (metric == METRIC_MAX && value > result)
			result = value;
		else if (metric == METRIC_SUM || metric == METRIC_AVG)
			result += value;
	}
	va_end(args);
	if (metric == METRIC_AVG)
		result = result / count;
	return (result);
}