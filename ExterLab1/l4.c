#include <stdio.h>

int main()
{
    int x,tmp;
    printf("Enter a dollar amount:");
    scanf("%d",&x);
    tmp=x;
    printf("\n$20 bills: %d\n",tmp/20);
    tmp=tmp%20;
    printf("$10 bills: %d\n",tmp/10);
    tmp=tmp%10;
    printf("$5 bills: %d\n",tmp/5);
    tmp=tmp%5;
    printf("$1 bills: %d\n",tmp);
    return 0;
}
