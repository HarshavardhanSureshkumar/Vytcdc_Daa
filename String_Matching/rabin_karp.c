//CH.SC.U4CSE24037
//S HARSHAVARDHAN
//Q) String Matching using Rabin-Karp Algorithm

#include<stdio.h>
#include<string.h>

#define d 256   // number of characters in input alphabet

void rabinKarp(char text[], char pattern[], int q)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // Calculate h = pow(d, m-1) % q
    for(i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Calculate hash value of pattern and first window of text
    for(i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for(i = 0; i <= n - m; i++)
    {
        // Check hash values
        if(p == t)
        {
            // Check characters one by one
            for(j = 0; j < m; j++)
            {
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == m)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash for next window
        if(i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if(t < 0)
                t = t + q;
        }
    }
}

int main()
{
    char text[100], pattern[100];
    int q = 101; // prime number

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    rabinKarp(text, pattern, q);

    return 0;
}