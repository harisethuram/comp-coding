#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Borrowed from https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main()
{
    // length of array
    int n = 0;
    scanf("%d", &n);

    // get elements for array
    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    // sort array
    qsort(nums, n, sizeof(int), cmpfunc);

    // print elements in reverse
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", nums[i]);
    printf("\n");
}