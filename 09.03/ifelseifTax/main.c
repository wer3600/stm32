#include <stdio.h>
#include <stdint.h>

void wait_for_user_input(void);

int main(){
	uint64_t income;
	uint64_t tax;

	double temp_income;


	printf("Enter your total income: ");
	scanf("%lf", &temp_income);

	income = (uint64_t)temp_income;

	if(income <= 9525){
		tax = 0;
	}
	else if((income >= 9526) && (income <= 38700)){
		tax = income * 0.12;
	}
	else if((income >= 38701) && (income <= 82500)){
		tax = income * 0.22;
	}
	else if(income > 82500){
		tax = income * 0.32;
		tax = tax + 1000;
	}
	printf("Tax payable: %I64u\n", tax);


	printf("Press Enter key to exit this application.\n");
	while(getchar() != '\n'){

	}
	getchar();
}
