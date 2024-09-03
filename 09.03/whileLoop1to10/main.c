#include <stdint.h>
#include <stdio.h>

void wait_for_user_input(void){
	printf("Press Enter to exit this application\n");
	while(getchar() != '\n'){

	}
	getchar();
}

int main(void){
	uint8_t num = 1;

	while(num <= 10){
		printf("%d\n", num);
		num++;
	}

	wait_for_user_input();
}
