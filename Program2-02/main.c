#include <stdio.h>

int f1(int n);
int f2(int n);
int f3(int n);

int main() {
    int n = 0;
    printf("enter number: ");
    scanf("%d", &n);

    int result = f1(n);
    printf("result: %d\n", result);
}

int f1(int n)
{
    int ans = f2(n) + 7;
    return ans;
}

int f2(int n)
{
    int ans = f3(n) * 2;
    return ans;
}

int f3(int n)
{
    int ans = n * n;
    return ans;
}