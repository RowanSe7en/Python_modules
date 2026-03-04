#include <unistd.h>

int ft_strlen(char *s)
{
    int l = 0;
    while (s[l])
        l++;
    return l;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = ft_strlen(argv[1]) - 1;
        while (i >= 0)
        {
            write(1, &argv[1][i], 1);
            i--;
        }
        
    }
    write(1, "\n", 1);
}