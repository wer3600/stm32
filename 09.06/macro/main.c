

#include<stdio.h>

#define AREA_TRI



int main(void)
{

#if !defined(AREA_CIR) && !defined(AREA_TRI)
#error "No macros defined."
#endif

#ifndef AREA_TRI
	float radius = 0;
	printf("This is circle area calculation program.\n");
	fflush(stdout);
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f", &radius);
	printf("Area of circle = %f\n", (3.1415 * radius * radius));
	fflush(stdout);
#endif


#ifdef AREA_TRI
	float base, height;
	printf("This is triangle area calculation program.\n");
	fflush(stdout);
	printf("Enter base and height: ");
	fflush(stdout);
	scanf("%f%f", &base, &height);
	printf("Area of circle = %f\n", (0.5 * base * height));
	fflush(stdout);
#endif


}
