//CH.SC.U4CSE24037
//S HARSHAVARDHAN
//Q) String Matching using Boyer-Moore Algorithm

#include<stdio.h>
#include<string.h>

#define MAX 256

// Function to create bad character table
void badCharHeuristic(char pattern[], int size, int badchar[])
{
    for(int i = 0; i < MAX; i++)
        badchar[i] = -1;

    for(int i = 0; i < size; i++)
        badchar[(int)pattern[i]] = i;
}

// Boyer Moore search function
void boyerMoore(char text[], char pattern[])
{
    int m = strlen(pattern);
    int n = strlen(text);

    int badchar[MAX];

    badCharHeuristic(pattern, m, badchar);

    int s = 0; // shift of pattern

    while(s <= (n - m))
    {
        int j = m - 1;

        // Compare pattern from right to left
        while(j >= 0 && pattern[j] == text[s + j])
            j--;

        if(j < 0)
        {
            printf("Pattern found at index %d\n", s);

            if(s + m < n)
                s += m - badchar[text[s + m]];
            else
                s += 1;
        }
        else
        {
            printf("Pattern %d\n", j);

            int shift = j - badchar[text[s + j]];
            if(shift < 1)
                shift = 1;

            s += shift;
        }
    }
}

int main()
{
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    boyerMoore(text, pattern);

    return 0;
}