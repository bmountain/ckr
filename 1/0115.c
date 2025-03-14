#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float ftc(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main()
{
    for (int i = LOWER; i <= UPPER; i = i + STEP)
    {
        float res = ftc(i);
        printf("%d %f\n", i, res);
    }
    return 0;
}
