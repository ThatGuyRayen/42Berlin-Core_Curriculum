#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	print_num(long n, int base)
{
	int	count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write (1, "-", 1);
		return print_num(-n, base) + 1;
	}
	else if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_num(n / base, base);
		return (count + print_num(n % base, base));
	}
}

int	print_format(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(args, int));
	else if (type == 's')
		count += print_str(va_arg(args, char *));
	else if (type == 'd')
		count += print_num((long)(va_arg(args, int)), 10);
	else if (type == 'x')
		count += print_num((long)(va_arg(args, unsigned int)), 16);
	else
		count += write(1, &type, 1);
	return (count);
}
int	my_printf(const char *str, ...)
{
	va_list	args; //args = ap (argument pointer)
	int	count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += print_format(*(++str), args);
		else
			count += write (1, str, 1);
		++str;
	}
	va_end(args);
	return count;
}



int	main ()
{
	int	count;
	count = my_printf("HEllo %s\n", "John");
	my_printf("The chars written are %d\n", count);
	return (0);
}
