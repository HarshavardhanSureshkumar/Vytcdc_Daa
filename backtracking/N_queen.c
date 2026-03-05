//CH.SC.U4CSE24037
//S HARSHAVARDHAN
//Q)N Queens Problem using Backtracking

#include<stdio.h>
#include<stdlib.h>

int board[20], count = 0;

// Function to check if queen placement is safe
int place(int row, int column)
{
    int i;
    for(i = 1; i < row; i++)
    {
        // Same column OR same diagonal
        if(board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

// Backtracking function
void nqueen(int row, int n)
{
    int column, i, j;

    for(column = 1; column <= n; column++)
    {
        if(place(row, column))
        {
            board[row] = column;

            if(row == n)
            {
                count++;
                printf("\nSolution %d:\n\n", count);

                for(i = 1; i <= n; i++)
                {
                    for(j = 1; j <= n; j++)
                    {
                        if(board[i] == j)
                            printf(" Q ");
                        else
                            printf(" . ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nqueen(row + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    nqueen(1, n);

    printf("\nTotal solutions = %d\n", count);

    return 0;
}