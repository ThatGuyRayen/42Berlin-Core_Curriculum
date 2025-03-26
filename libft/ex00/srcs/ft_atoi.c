#include "libft.h"

long long	parser(const char *s, int sign)
{
	long long	result;

	result = 0;
	while (*s && ft_isdigit(*s))
	{
		if (result > (LLONG_MAX - (*s - '0')) / 10)
		{
			if (sign > 0)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result);
}

int	ft_atoi(const char *s)
{
	int				sign;

	if (!s)
		return (0);
	sign = 1;
	while (*s && ft_iswhitespace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	return ((int)(parser(s, sign) * sign));
}
/*
#include <stdio.h>
int	main (void)
{
	printf("%d\n", ft_atoi("--213"));
	return (0);
}
*/
