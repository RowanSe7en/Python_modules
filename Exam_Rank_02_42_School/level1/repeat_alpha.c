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
                int in = argv[1][i] - 64;
                while (in > 0)
                {
                    write(1, &argv[1][i], 1);
                    in--;
                }
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                int in = argv[1][i] - 96;
                while (in > 0)
                {
                    write(1, &argv[1][i], 1);
                    in--;
                }
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}