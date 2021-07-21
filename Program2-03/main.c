#include <stdio.h>

int sigma(int n);

int main() {
    int n = 0;
    printf("enter n: ");
    scanf("%d", &n);

    printf("sigma(n): %d\n", sigma(n));
}

int sigma(int n)
{
    if (n == 1)
        return 1;
    int sum = n + sigma(n - 1);
    return sum;
}