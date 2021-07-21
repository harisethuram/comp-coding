#include <stdio.h>
#include <stdbool.h>

bool lSearch (int x, int nums[], int n);

int main() {
    // get length of array
    int n;
    printf("Enter num elements: ");
    scanf("%d", &n);

    // get elements in array
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &nums[n]);
    }

    int x;
    printf("Enter element you are looking for: ");
    scanf("%d", &x);

    lSearch(x, nums, n);
    return 0;
}

bool lSearch (int x, int nums[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (nums[i] == x)
        {
		    printf("true\n");
			return true;
        }
	}
	printf("false\n");
	return false;
}
