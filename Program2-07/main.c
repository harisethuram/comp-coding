#include <stdio.h>


int h(int k)
{
    return (5 * k) + 3;
}

int main()
{
    int numbersToBeInserted [] = {10, 20, 30, 40, 50, 60, 70, 80};
    int tableLength = 20;

    int table[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int index = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            index = (h(numbersToBeInserted[i]) + j) % tableLength;
            if (table[index] == -1)
            {
                table[index] = numbersToBeInserted[i];
                break;
            }
        }
    }
    for (int i = 0; i < tableLength; i++)
        printf("%d, ", table[i]);
}

