#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
    int     byte;
    char    c;
    char    *str_buffer;
    int     i;
	int		size = 100;

    if (fd < 0)
        return (NULL);
    
    str_buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!str_buffer)
        return (NULL);

    i = 0;
    byte = read(fd, &c, 1);
    while (byte > 0)
    {
        str_buffer[i++] = c;
        if (c == '\n')
            break;
        if (i >= size - 1) // Increase buffer size dynamically
        {
            size *= 2;
            str_buffer = realloc(str_buffer, size);
            if (!str_buffer)
                return (NULL);
        }
        byte = read(fd, &c, 1);
    }
    if (i == 0 || byte < 0)
    {
        free(str_buffer);
        return (NULL);
    }
    str_buffer[i] = '\0';
    return (str_buffer);
}

int main(void)
{
    char    *str;
    int     fd;
    int     i;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }
    
    i = 0;
    while (i < 6)
    {
        str = get_next_line(fd);
        if (!str)
            break;
        printf("i: %i\n", i);
        printf("%s", str); // no need for \n as get_next_line includes it
        free(str);
        i++;
    }
    close(fd);
    return (0);
}
