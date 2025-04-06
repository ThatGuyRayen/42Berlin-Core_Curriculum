#include "printf.h"

int		put_char(int c)
{
	return write(1, &c, 1);
}

int		print_str(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		put_char ((int)*str);
		++count;
		++str;
	}
	return (count);
}

int print_num(long num, int base, int is_signed, int is_upper)
{
	char	*lower = "0123456789abcdef";
	char	*upper = "0123456789ABCDEF";
	char	buffer[32];
	int		i;
	int		count;
	unsigned long n;
	char	*digits;

	i = 0;
	count = 0;

	if (is_upper == 1)
		digits = upper;
	else
		digits = lower;

	if (is_signed == 1 && num < 0)
	{
		count += write(1, "-", 1);
		n = (unsigned long)(-num);
	}
	else
		n = (unsigned long)num;

	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}

	while (n > 0)
	{
		buffer[i] = digits[n % base];
		n = n / base;
		i++;
	}

	while (i > 0)
	{
		i--;
		count += write(1, &buffer[i], 1);
	}
	return (count);
}


