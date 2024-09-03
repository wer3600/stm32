#include<stdio.h>
#include<stdint.h>

void wait_for_user_input(void){
	printf("Press Enter key to exit this application.\n");

	while(getchar() != '\n'){

	}
	getchar();
}


int main(){
	int32_t start_num, end_num;
	uint32_t even = 0;

	printf("Enter starting and ending numbers(give space between 2 nums): ");
	scanf("%d %d", &start_num, &end_num);

	if(start_num > end_num){
		printf("ending number should bigger than starting number.\n");
		wait_for_user_input();
		return 0;
	}

	printf("Even numbers are : \n");

	while(start_num <= end_num){
		if(start_num % 2 == 0){
			printf("%4d\t", start_num);
			even += 1;
		}
		start_num++;
	}

	printf("\nTotal Even numbers : %u\n", even);

	wait_for_user_input();
}
