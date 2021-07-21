#include <stdio.h>

int main()
{
    int a = 0;
    scanf("%d", &a);

    int b = 0;
    scanf("%d", &b);

    int c = 0;
    scanf("%d", &c);


    int numStonesCollected = 0;

    while (b >= 1 && c >= 2)
    {
        b -= 1;
        c -= 2;
        numStonesCollected += 3;
    }
    while (a >= 1 && b >= 2)
    {
        a -= 1;
        b -= 2;
        numStonesCollected += 3;
    }

    printf("%d\n", numStonesCollected);
}