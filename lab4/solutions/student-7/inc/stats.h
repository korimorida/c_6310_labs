#ifndef STATS_H
# define STATS_H

# include <stdarg.h>
# include "libft.h"


# define METRIC_MIN 0
# define METRIC_MAX 1
# define METRIC_SUM 2
# define METRIC_AVG 3


typedef int (*t_metric_fn)(int count, ...);


typedef struct s_metric
{
	char		*name;
	int			code;
	t_metric_fn	func;
}	t_metric;

int		print_error(char *msg);

int		is_valid_number(char *str);
int		parse_int(char *str, int *out);

int			get_metric_code(char *name);
t_metric_fn	get_metric_function(char *name);

int		compute(int metric, int count, ...);
int		metric_min(int count, ...);
int		metric_max(int count, ...);
int		metric_sum(int count, ...);
int		metric_avg(int count, ...);

#endif