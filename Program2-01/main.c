#include <stdio.h>

int main()
{
    printf("Enter num. elements: ");
    int length = 0;
    scanf("%d", &length);
    int nums[length];

    for (int i = 0; i < length; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &nums[i]);
    }

    int biggest = nums[0];

    for (int j = 0; j < length; j++)
    {
        if (nums[j] > biggest)
            biggest = nums[j];
    }
    printf("largest num: %d\n", biggest);
}