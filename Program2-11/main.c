#include <stdio.h>

// For simplicity, Path graphs are stored as arrays
int findMaxWISBruteForce(int n, int pGraph[]);
int findMaxWISTopDown(int n, int pGraph[], int dp[]);
int findMaxWISBottomUp(int n, int pGraph[], int dp[]);
void backTrack (int n, int pGraph[], int dp[]);

int max (int n1, int n2);

int main()
{
    // get length of array
    int n;
    printf("Enter num elements: ");
    scanf("%d", &n);

    // check if n is 0; if so, exit
    if (n == 0)
        return 0;
    // get the weights of vertices
    int pGraph[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &pGraph[i]);
    }

    // initialize the dp array to all -1's
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = -1;

    // dp[0] will be 0 as the maxWIS of an empty set is always 0
    dp[0] = 0;

    // Top down approach
    int maxWIS = findMaxWISBottomUp(n, pGraph, dp);
    printf("\n");
    // print dp
    for (int i = 0; i < n + 1; i++)
        printf("%d, ", dp[i]);
    printf("\n\n");
    // Back-tracking
    backTrack(n, pGraph, dp);

    // print maxWIS
    printf("maxWIS: %d\n", maxWIS);
    return 0;
}

/* Brute force approach
Input
    - n: the findMaxWISBruteForce considers all elements in pGraph up till but not including n
    - pGraph: a list consisting of the weights of all vertices
Output
    - the sum of all weights in the Maximum WIS
*/
int findMaxWISBruteForce(int n, int pGraph[])
{
    // base case 1: if n = 1, then return the weight of first vertex only
    if (n == 1)
        return pGraph[0];
    // base case 2: if n = 2, then return the max of first two vertices
    else if (n == 2)
        return max(pGraph[0], pGraph[1]);

    // calculate Gn recursively (Case 1)
    int Gn = findMaxWISBruteForce(n - 1, pGraph);

    // calculate Gn' recursively (Case 2)
    int GnPrime = findMaxWISBruteForce(n - 2, pGraph);

    // find max of case 1 and case 2
    int maxWIS = max(Gn, GnPrime + pGraph[n - 1]);

    // return
    return maxWIS;
}

/* Top-Down Dynamic Programming approach
Input
    - n: the findMaxWISBruteForce considers all elements in pGraph up till but not including n
    - pGraph: a list consisting of the weights of all vertices
    - dp: the array used for memoization
Output
    - the sum of all weights in the Maximum WIS
    - also alters dp during memoization
*/
int findMaxWISTopDown(int n, int pGraph[], int dp[])
{
    // base case: if n = 1, then return the weight of first vertex
    if (n == 1)
    {
        // memoize
        dp[1] = pGraph[0];
        return pGraph[0];
    }

    // Case 1
    // Check if a solution for Gn already exists in dp
    int Gn = dp[n - 1];
    // If a solution doesn't exist i.e. is -1, calculate the solution
    if (Gn == -1)
        Gn = findMaxWISTopDown(n - 1, pGraph, dp);

    // Case 2
    int GnPrime = dp[n - 2];
    if (GnPrime == -1)
        GnPrime = findMaxWISTopDown(n - 2, pGraph, dp);

    // find max of case 1 and case 2
    int maxWIS = max(Gn, GnPrime + pGraph[n - 1]);

    // memoize
    dp[n] = maxWIS;
    // return
    return maxWIS;
}

/* Bottom-Up Dynamic Programming approach
Input
    - n: the findMaxWISBruteForce considers all elements in pGraph up till but not including n.
    - pGraph: a list consisting of the weights of all vertices
    - dp: the array used for memoization
Output
    - the sum of all weights in the Maximum WIS
    - also alters dp during memoization
*/
int findMaxWISBottomUp(int n, int pGraph[], int dp[])
{
    // max WIS of the first vertex is the first vertex
    dp[1] = pGraph[0];

    // bottom-up loop
    for (int i = 2; i < n + 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + pGraph[i - 1]);

    // last slot in dp is the sum of weights in the Max WIS
    return dp[n];
}

// prints out the weights and positions of the vertices that make up the Max WIS
void backTrack (int n, int pGraph[], int dp[])
{
    // start at last element in dp
    int i = n;

    while (i != 0)
    {
        // if part of case 1, then the vertex does not belong in max WIS and decrease i by 1
        if (dp[i] == dp[i-1])
            i--;
        // else, print the vertex and decrease i by 2
        else
        {
            printf("%d [Vertex No. %d]\n", pGraph[i - 1], i);
            i -= 2;
        }
    }
}
// return max of two numbers
int max (int n1, int n2)
{
    if (n1 >= n2)
        return n1;
    return n2;
}