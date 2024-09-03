#include <stdio.h>

int main(){
	char a, b, c, d, e, f;

	printf("Enter 6 characters of your choice: ");
	fflush(stdout);
	scanf("%c %c %c %c %c %c", &a, &b, &c, &d, &e, &f);

	printf("ASCII Codes : %u %u %u %u %u %u", a, b, c, d, e, f);

	printf("\nPress Enter key to exit this application.");
	while(getchar() != '\n'){

	}
	getchar();
}
