#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void	*whatever_stuff;
	size_t	stuff_size;
	struct s_list	*next;
}			t_list;
