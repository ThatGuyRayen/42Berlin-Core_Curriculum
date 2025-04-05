#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

//function to find newline
int		ft_str_index(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

//Function to join two strings while allocating memory for it (return new allocated string)
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i] = s2[j++];
	res[i] = '\0';
	free(s1);
	//we always free s1 after joining 	1.	remainder is the old leftover string (from last call).
	// 2.	buffer is the new string we just read from read().
	// 3.	We join them into a new string, and:
	// •	That new string now replaces remainder.
	// •	The old remainder (s1) is no longer needed.
	// 4.	So if we don’t free it, it stays in memory and becomes a memory leak 
	return (res);
}

// Function to extract lin and update str

char	*extract_line(char **buffer)
{
	char	*line;
	char	*newstr;
	char	nl_index;

	nl_index = ft_str_index(*buffer, '\n');
	if (nl_index == -1)
		nl_index = strlen (*buffer);
	line = strndup (*buffer, nl_index + ((*buffer)[nl_index] == '\n')); //copy till \n
	newstr = strdup (*buffer + nl_index + ((*buffer)[nl_index] == '\n'));
	free(buffer);
	if (line[0] == '\0') //nothing to return
	{
		free(line);
		return (NULL);
	}
	return (line);
}

//Main function
char	*get_next_line(int fd)
{
	int		byte;
	int		i;
	int		size;
	char	c;
	char	*str_buffer;
	char	*new_buf;

	size = BUFFER_SIZE;
	i = 0;
	if (fd < 0)
		return (NULL);
	str_buffer = (char *) malloc(size + 1);
	if (!str_buffer)
		return (NULL);
	while ((byte = read(fd, &c, 1)) > 0)
	{
		str_buffer[i++] = c;
		if (c == '\n')
			break ;
		if (i >= size)
		{
			size *= 2;
			new_buf = realloc(str_buffer, size + 1);
			if (!new_buf)
				{
					free(str_buffer);
					return (NULL);
				}
			str_buffer = new_buf;
	
		}
	}

	if (i == 0 && byte <= 0)
	{
		free(str_buffer);
		return (NULL);
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}


int		main(void)
{
	int		fd;
	char	*line;
	int		i = 0;

	fd = open ("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror ("error opeining file");
		return (1);
	}

	while ((line = get_next_line(fd)) && i < 100)
	{
		printf("Line %d: %s", i + 1, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}











