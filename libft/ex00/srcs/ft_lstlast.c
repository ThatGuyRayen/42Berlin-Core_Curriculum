#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next) //to stop at last node
	{
		lst = lst->next;
	}
	return (lst);
}
