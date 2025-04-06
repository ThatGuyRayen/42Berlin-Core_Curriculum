#ifndef PRINTF_H
# define PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		put_char(int c);
int		print_str(char *str);
int		print_num(long num, int base, int is_signed, int is_upper);
int		print_hex(unsigned long n);
int		print_p(void *ptr);

#endif
