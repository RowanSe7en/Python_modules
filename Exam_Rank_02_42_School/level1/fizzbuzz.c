#include <unistd.h>

void numb(int x)
{
    char dec[] = "0123456789";

    if (x > 9)
        numb(x / 10);
    write(1, &dec[x % 10], 1);
}

int main()
{
    int i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);

        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
        {
            numb(i);
        }
        write(1, "\n", 1);
        i++;
    }
    
}