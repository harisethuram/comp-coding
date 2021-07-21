#include <stdio.h>
#include <stdlib.h>

int sumDigits(int n);

int main()
{
    int sum = 0;
    int length = 0;
    scanf("%d", &length);

    char n[length];

    scanf("%s", n);
    if (length == 1)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < length; i++)
        sum += ((int)(n[i]))-48;
    int timesSpellUsed = 1;

    while (sum > 9)
    {
        sum = sumDigits(sum);
        timesSpellUsed++;
    }
    printf("%d\n", timesSpellUsed);
}

int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
