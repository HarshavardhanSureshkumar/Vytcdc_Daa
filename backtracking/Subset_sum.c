//CH.SC.U4CSE24037
//S HARSHAVARDHAN
//Q)Subset Sum Problem using Backtracking

#include<stdio.h>

int set[20], subset[20];
int n, target;

// Function to find subsets
void subsetSum(int i, int sum, int k)
{
    if(sum == target)
    {
        printf("{ ");
        for(int j = 0; j < k; j++)
        {
            printf("%d ", subset[j]);
        }
        printf("}\n");
        return;
    }

    if(i >= n || sum > target)
        return;

    // Include element
    subset[k] = set[i];
    subsetSum(i + 1, sum + set[i], k + 1);

    // Exclude element
    subsetSum(i + 1, sum, k);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&set[i]);

    printf("Enter target sum: ");
    scanf("%d",&target);

    printf("Subsets with sum %d are:\n",target);

    subsetSum(0,0,0);

    return 0;
}