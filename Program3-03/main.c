#include <stdio.h>

int isLegal (int num);


int main()
{
    int a = 0;
    scanf("%d", &a);

    int b = 0;
    scanf("%d", &b);

    int legalNumbers = 0;

    for (int i = a; i <= b; i++)
    {
        if (isLegal(i) == 1)
            legalNumbers++;
    }
    printf("%d\n", legalNumbers);
}
int isLegal (int num)
{
    if (num % 9 == 0)
        return 0;

    while (num != 0)
    {
        if (num % 10 == 9)
            return 0;
        num = num/10;
    }

    return 1;
}