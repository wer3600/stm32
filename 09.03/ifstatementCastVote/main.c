#include<stdio.h>

int main(){
	int age;

	printf("enter your age: ");
	fflush(stdout);
	scanf("%d", &age);

	if(age > 18){
		printf("You are eligible to vote");
	}
	else{
		printf("You are not eligible to vote");
	}

	printf("\nPress Enter key to exit this application.\n");
	while(getchar() != '\n'){

	}
	getchar();
}
