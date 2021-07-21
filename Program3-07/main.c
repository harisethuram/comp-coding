#include <stdio.h>
#include <stdlib.h>

int isEven (int numToBeChecked)
{
    while (numToBeChecked != 0)
    {
        if ((numToBeChecked % 10) % 2 == 1)
            return 0;
        numToBeChecked /= 10;

    }
    return 1;
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int nCopy = n;
    int differenceBelow = 0;
    int differenceAbove = 0;
    // forever loop to be broken out of
    while (1)
    {
        if (isEven(nCopy) == 1)
        {
            differenceBelow = abs(n - nCopy);
            break;
        }

        nCopy--;
    }
    while (1)
    {
        if (isEven(nCopy) == 1)
        {
            differenceAbove = abs(n - nCopy);
            break;
        }

        nCopy ++;
    }

    if (differenceAbove <= differenceBelow)
    {
        printf("%d\n", differenceAbove);
    }
    else
        printf("%d\n", differenceBelow);
}