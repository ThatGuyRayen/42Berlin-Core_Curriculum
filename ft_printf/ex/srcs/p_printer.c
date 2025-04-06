#include "printf.h"

int		print_hex(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_hex(n / 16);
	count += put_char(hex[n % 16]);
	return (count);
}

int		print_p(void *ptr)
{
	unsigned long	add;
	int		count;

	add = (unsigned long)ptr;
	count = 0;
	count += print_str("0x");
	count += print_hex(add);
	return (count);
}
