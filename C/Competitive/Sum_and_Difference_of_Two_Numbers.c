#include <stdio.h>
int main()
{
    int int1, int2, s1, d1;
    float float1, float2, s2, d2;
    scanf("%d%d", &int1, &int2);
    scanf("\n");
    scanf("%f%f", &float1, &float2);
    s1 = int1 + int2;
    d1 = int1 - int2;
    s2 = float1 + float2;
    d2 = float1 - float2;
    printf("%d %d\n", s1, d1);
    printf("%.1f %.1f", s2, d2);
}