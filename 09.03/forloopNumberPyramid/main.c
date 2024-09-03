#include<stdio.h>
#include<stdint.h>

void wait_for_user_input(void){
	printf("Press Enter key to exit this application.\n");
	while(getchar() != '\n'){

	}
	getchar();
}

int main(){
	uint32_t height;

	printf("Enter height of pyramid: ");
	scanf("%d", &height);

	for(uint32_t i=0 ; i<=height ; i++){
		for(uint32_t j = i ; j>0 ;j--){
			printf(" %d   ", j);
		}
		printf("\n");
	}

	wait_for_user_input();
}
