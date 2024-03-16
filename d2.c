#include <stdio.h>

int main() 
{
    char ch, s[100], sen[100];
    scanf("%c", &ch); // Read a character
    scanf(" %99s", s); // Read a string with a limit of 99 characters
    scanf(" %[^\n]", sen); // Read a line of text including spaces

    printf("%c\n%s\n%s", ch, s, sen);

    return 0;
}

