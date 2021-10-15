#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Input: ");
    scanf("%d", &num);
    if((num - 5)%7==0)
        num = (num - 5)/7;
    else
    {
        printf("Warning\n");
        return 1;
    }

    if(num<='z' && num>='a' || num<='Z' && num>='A')
        printf("Output: %c\n", num);
    else
        printf("Warning\n");

    return 0;
}
