#include <stdio.h>
#include "math.h"

int main(){

	printf("Add : %X\n", math_add(0x0FFF1111, 0x0FFF1111));
	printf("Multiply : %I64X\n", math_mul(0x0FFF1111, 0x0FFF1111));
	printf("Divide : %.2f\n", math_div(100, 8));

	return 0;
}
