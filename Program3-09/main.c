#include <stdio.h>
#include <stdlib.h>

// borrowed from https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main()
{
    // get freedom fighter power
    int ffPower = 0;
    scanf("%d", &ffPower);

    // get number of enemires
    int numEnemies = 0;
    scanf("%d", &numEnemies);
    int enemies[numEnemies];

    // get power of enemies
    for (int i = 0; i < numEnemies; i++)
        scanf("%d", &enemies[i]);

    // sort the enemies by power
    qsort(enemies, numEnemies, sizeof(int), cmpfunc);
    // calculate the number of enemies defeated
    int numEnemiesDefeated = 0;
    for (int i = 0; i < numEnemies; i++)
    {
        if (ffPower >= enemies[i])
        {
            ffPower -= enemies[i];
            numEnemiesDefeated++;
        }
        else
            break;
    }
    printf("%d\n", numEnemiesDefeated);
}