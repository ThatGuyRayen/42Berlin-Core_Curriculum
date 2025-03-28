#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	t_list	*current;

	newlist = NULL;
	if (!lst || !f)
		return ;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if(!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		if (!newlist)
			newlist = newnode;
		else
			current->next = newnode;
		current = newnode;
		lst = lst->next;
	}
	return (newlist)
}
