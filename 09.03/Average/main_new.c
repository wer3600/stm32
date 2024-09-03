#include <stdio.h>

int main(void){
	float number1, number2, number3;
	float average;

	printf("Enter 3 numbers : ");
	fflush(stdout);
	scanf("%f %f %f", &number1, &number2, &number3);

	average = (number1 + number2 + number3) / 3;

	printf("Average is %f\n", average);

	printf("Press Enter key to exit the application \n");
	while(getchar() !=  '\n'){

	}
	getchar();
}
