#include <stdio.h>

int coins(float change);

int main()
{
    // cost
    float c = 0;

    // amount paid
    float p = 0;

    printf("Enter cost: ");
    scanf("%f", &c);

    printf("Enter amount paid: ");
    scanf("%f", &p);

    float change = p - c;
    //printf("%f\n", change);
    int numCoins = coins(change);

    printf("Num Coins: %d\n", numCoins);
}

int coins (float change)
{
    int remainder = (int) (change * 100);
    int numCoins = 0;
    // exploit Quarters
    while (remainder >= 25)
    {
        numCoins++;
        remainder -= 25;
    }

    // exploit Dimes
    while (remainder >= 10)
    {
        numCoins++;
        remainder -= 10;
    }

    // exploit Nickels
    while (remainder >= 5)
    {
        numCoins++;
        remainder -= 5;
    }

    while (remainder >= 1)
    {
        numCoins++;
        remainder -= 1;
    }

    return numCoins;
}