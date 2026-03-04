#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i] != 0)
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                if (argv[1][i] + 13 > 90)
                {
                    char c = argv[1][i] - 13;
                    write(1, &c, 1);
                }
                else
                {
                    char c = argv[1][i] + 13;
                    write(1, &c, 1);
                }
                
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                if (argv[1][i] + 13 > 122)
                {
                    char c = argv[1][i] - 13;
                    write(1, &c, 1);
                }
                else
                {
                    char c = argv[1][i] + 13;
                    write(1, &c, 1);
                }
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}