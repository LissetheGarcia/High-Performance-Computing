// This programs print the maximum line lenght from user input

#include <stdio.h>

#define MAXLINE 1000

int line_count(char lines[], int lim);
void copy(char to[], char from[]);
void reverseds(char to[], char from[], int max);

int main()
{
    int len, max = 0;
    char line[MAXLINE];
    char copied[MAXLINE];
    char reversed[MAXLINE];

    while((len = line_count(line, MAXLINE)) > 0)
    {
        printf("The lenght is: %d\n", len);

        if(len > max)
        {
            max = len;
            copy(copied, line);
            reverseds(reversed, copied, max);
        }
    }
    if(max > 0)
    {
        printf("\nThe longest line has lenght: %d\n", max);
        printf("\nWhose content is: %s\n", copied);
        printf("\nWhose content reversed is: %s\n", reversed);
    }


    return 0;
}


int line_count(char s[], int lim)
{
    int i, c;

    for(i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        // s[i] = c;
        if(c == ' ' || c == '\b')
        {
            c = getchar();
        }
        if(c == '\n')
        {
            s[i] = c;
            ++i;
        }
        s[i] = c;
    }
    s[i] = '\0';

    return i;
}


void copy(char copied[], char line[])
{
    int i = 0;

    while((copied[i] = line[i]) != '\0')
    {
        ++i;
    }
}

void reverseds(char reversed[], char copied[], int max)
{
    int i = 0, lim  = max;

    // for(i = 0; i < max && lim >= 0; ++i, --lim)

    while(i < max && lim >= 0)
    // ((reversed[i] = line[lim]) != '\0')
    {
        if(copied[lim - 1] != '\n' || copied[lim - 1] != '\0')
        {
            reversed[i] = copied[lim - 1];
        }
        ++i;
        --lim;
    }
}
