#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rawNumber, pNumber;
    printf("Enter a positive integer(100<=n<=999): ");
    scanf("%d", &rawNumber);

    pNumber = 0;
    pNumber += rawNumber/100;
    pNumber += rawNumber%100/10*10;
    pNumber += rawNumber%10*100;

    printf("The invert number is : %d\n", pNumber);

    return 0;
}
