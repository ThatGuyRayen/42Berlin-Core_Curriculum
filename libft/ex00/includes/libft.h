#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# define LLONG_MAX 9223372036854775807
# define INT_MIN -2147483647

typedef struct	s_list
{
	void	*whatever_stuff;
	size_t	stuff_size;
	struct s_list	*next;
}			t_list;
