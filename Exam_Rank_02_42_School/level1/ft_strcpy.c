#include <unistd.h>
#include <string.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (*s2)
    {
        s1[i] = s2[i];
        i++;
    }
}