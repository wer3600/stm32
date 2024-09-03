#include<stdio.h>

int main(){
	int number1, number2;

	printf("Enter first number(integer): ");
	fflush(stdout);
	scanf("%d", &number1);
	printf("Enter second number(integer): ");
	fflush(stdout);
	scanf("%d", &number2);

	if(number1 > number2){
		printf("%d is bigger.\n", number1);
	}
	else if(number1 < number2){
		printf("%d is bigger.\n", number2);
	}
	else{
		printf("numbers are equal.\n");
	}

	printf("Press Enter key to exit this application.\n");
	while(getchar() != '\n'){

	}
	getchar();
}
