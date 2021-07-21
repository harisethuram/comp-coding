#include <stdio.h>

int main()
{
    int x = 0;
    scanf("%d", &x);

    int y = 0;
    scanf("%d", &y);

    if (x - y == 1)
        printf("NO\n");
    else
        printf("YES\n");
}