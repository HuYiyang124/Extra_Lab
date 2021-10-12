#include <stdio.h>

int main() {
	float amount, afterAmount;
	printf("Enter an amount : ");
	scanf("%f", &amount);
	afterAmount = (1 + 0.05)*amount; //calculate after the 5% tax
	printf("With tax added : $%.2f\n", afterAmount);
	return 0;
}
