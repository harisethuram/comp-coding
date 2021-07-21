#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int stringLength = 0;
    scanf("%d", &stringLength);

    char s[stringLength];
    scanf("%s", s);

    char distinctPlaces[stringLength];
    int isIn = 0;
    for (int i = 0; i < stringLength; i++)
    {
        isIn = 0;
        for (int j = 0; j < stringLength; j++)
        {
            if (s[i] == distinctPlaces[j])
                isIn = 1;
        }
        if (isIn == 0)
            distinctPlaces[i] = s[i];
    }
    for (int i = 0; i < stringLength; i++)
    {
        if (isalpha(distinctPlaces[i]))
            printf("%c", distinctPlaces[i]);
    }
}