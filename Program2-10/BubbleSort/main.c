#include <stdio.h>

void bubbleSort(int nums[], int length);
void printArray (int nums[], int length);

int main() {
    int n = 0;
    printf("Number of elements: ");
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &nums[i]);
    }
    bubbleSort(nums, n);
    printArray(nums, n);
}

// sort the elements
void bubbleSort(int nums[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        // up till length - i - 1, because after each iteration of outer loop, we assume (length - i)th element is where it's supposed to be.
        for (int j = 0; j < length - i - 1; j++)
        {
            if (nums[j+1] < nums[j])
            {
                // swap
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

void printArray (int nums[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}