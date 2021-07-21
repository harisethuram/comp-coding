#include <stdio.h>

int hash (char c);


int main()
{
    int length = 0;
    scanf("%d", &length);

    char s[length];
    scanf("%s", s);

    int start = 0;
    scanf("%d", &start);

    int end = 0;
    scanf("%d", &end);

    // using ASCII
    int alphabets[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = start; i <= end; i++)
    {
        alphabets[hash(s[i])]++;
    }

    int numOdds = 0;

    for (int i = 0; i < 26; i++)
    {
        if (alphabets[i] % 2 != 0)
            numOdds++;
    }
    if (numOdds > 1)
        printf("NO!\n");
    else
        printf("YES!\n");
}
// returns an index for a character by converting it to ascii and subtracting 65
int hash (char c)
{
    int index = c - 65;
    return index;
}