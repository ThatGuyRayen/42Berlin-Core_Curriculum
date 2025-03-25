    int ft_atoi(char *s) {
        int	i;
        int	result;
        int	sign;
        int	counter;

	i = 0;
	result = 0;
	sign = 1;
	counter = 0;
        while (s[i] == ' ')
            i++;
        while (s[i] == '+' || s[i] =='-')
        {
            if (s[i] == '-')
            {
                sign = -1;
            }
            counter++;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
            i++;
        }
        if (counter >=2)
            return (0);
        return(int)(result * sign);
    }

#include <stdio.h>
int	main (void)
{
	char *s = "-+6363";
	printf("%d\n", ft_atoi(s));
	return (0);
}
