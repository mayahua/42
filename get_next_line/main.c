#include <fcntl.h>      // open()
#include <stdio.h>      // printf()
#include <stdlib.h>     // free()
#include "get_next_line.h"
// #include "get_next_line_bonus.h"

int main()
{
    int     fd = open("sample1.txt", O_RDONLY);
    char    *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	printf("\n");
    close(fd);
    return (0);
}

/*
// BONUS
int main()
{
    int     fd1, fd2;
    char    *line1, *line2;
    int     i;

    fd1 = open("sample1.txt", O_RDONLY);
    fd2 = open("sample2.txt", O_RDONLY);
    i = 0;
    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        if (!line1 && !line2)
            break ;
        if (line1)
        {
            printf("File 1, line %d: %s", i + 1, line1);
            free(line1);
        }
        if (line2)
        {
            printf("File 2, line %d: %s", i + 1, line2);
            free(line2);
        }
        i++;
    }
    close(fd1);
    close(fd2);
    return (0);
}
//*/