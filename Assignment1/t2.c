#include <stdio.h>

int main()
{
	float moneyEuro;
	int option;
	printf("Please imput amount in Euro: ");
	scanf("%f", &moneyEuro);
   
	printf("Please choose the currency converting to (1: HK dollar, 2: RMB): ");
	scanf("%d", &option);
	
	if(option==1)
		printf("%.2f euro = %.2f HK dollar\n", moneyEuro, 8.1*moneyEuro);
	else if(option==2)
		printf("%.2f euro = %.2f RMB\n", moneyEuro, 7.2*moneyEuro);
   	return 0;
}
