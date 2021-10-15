#include <stdio.h>

int main() {
	int r = 10; // define the radius of the sphere
	float v;
	v = 4/3. * 3.14 * r * r * r; // calculate the volume
	printf("The volume of the sphere is : %.2f\n", v);
	return 0;
}
