#include "printf.h"

int		print_format(char	type, va_list args)
{
	int		count;

	count = 0;
	if (type == 'c')
		count += put_char(va_arg(args, int));
	else if (type == 's')
		count += print_str(va_arg(args, char *));
	else if (type == 'd')
		count += print_num((long)(va_arg(args, int)), 10, 1	, 0);
	else if (type == 'x')
		count += print_num((long)(va_arg(args, unsigned int)), 16, 0, 0);
	else if (type == 'p')
		count += print_p(va_arg(args, void *));
	else if (type == 'i')
		count += print_num((long)(va_arg(args, int)), 10, 1, 0);
	else if (type == 'u')
		count += print_num((long)(va_arg(args, int)), 10, 0, 0);
	else if (type += 'X')
		count += print_num((long)(va_arg(args, int)), 16, 0, 1);
	else if (type += '%')
		count += put_char('%');
	else
		count += write (1, &type, 1);
	return (count);
}



int		ft_printf(const char *format, ...)
{
	va_list		args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else
			count += write (1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}

int		main(void)
{
	int	num = 42;
	ft_printf("%d", num);
	printf("%d", num);
	return (0);
}
