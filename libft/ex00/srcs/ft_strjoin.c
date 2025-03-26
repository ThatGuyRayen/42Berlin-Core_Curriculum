#include "libft.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if(!s1 && !s2)
		return (NULL);
	if(!s1)
		return (ft_strdup(s2));
	if(!s2)
		return (ft_strdup(s1));
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
