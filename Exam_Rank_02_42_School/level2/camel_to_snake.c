#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int leng(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

int add_leng(char *s)
{
    int i = 0;
    int j = 0;
    while (s[j])
    {
        if (s[j] >= 'A' && s[j] <= 'Z')
        {
            i++;
        }
        j++;
    }
    return i;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {

        int len = leng(argv[1]);
        int add_len = add_leng(argv[1]);
        printf("%d\n", len);
        printf("%d\n", add_len);

        char * ss = malloc(len + add_len + 1);
        int i = 0;
        int j = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                if (i)
                    ss[j++] = '_';
                ss[j] = argv[1][i] + 32;
            }
            else
                ss[j] = argv[1][i];

            i++;
            j++;

        }
        ss[j] = '\0';
        printf("%s\n", ss);
        
    }
    
}

// hereIsACamelCaseWord
// here_is_a_camel_case_word