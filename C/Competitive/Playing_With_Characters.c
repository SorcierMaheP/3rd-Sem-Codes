#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char ch;
    char s[100];
    char sen[100];
    // printf("Enter the character, string and sentence.\n");
    scanf("%c", &ch);
    scanf("%s", s);
    scanf("\n");
    scanf("%[^\n]%*c", sen);
    printf("%c", ch);
    printf("\n");
    printf("%s", s);
    printf("\n");
    puts(sen);
    return 0;
}