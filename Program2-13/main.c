#include <stdio.h>
#include <stdlib.h>

int max(int n1, int n2);
int K (int k, int i, int w[], int v[]);


int main()
{
    int n = 0;
    int k = 0;
    printf("Enter Knapsack capacity: ");
    scanf("%d", &k);
    printf("Enter number of objects: ");
    scanf("%d", &n);

    int w[n];
    int v[n];

    for (int i = 0; i < n; i++)
    {
        printf(" %d, %d\n", w[i], v[i]);
    }
    int optVal = K(k, n - 1, w, v);
    printf("%d\n", optVal);
    return 0;
}

int K (int k, int i, int w[], int v[])
{
    if (i == 0)
        return 0;
    else if (w[i] <= k)
        return max(v[i]+ K(k - w[i], i - 1, w, v), K(k, i - 1, w, v));
    else
        return K(k, i - 1, w, v);
}

int max(int n1, int n2)
{
    if (n1 >= n2)
        return n1;
    else
        return n2;
}