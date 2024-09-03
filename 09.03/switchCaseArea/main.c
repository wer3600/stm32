#include<stdio.h>
#include<stdint.h>

void wait_for_user_input(void);

int main(){
	int8_t code;
	float a, b, c;
	float area;

	printf("Area calculation program\n");
	printf("Circle		--> c\n");
	printf("Triangle	--> t\n");
	printf("Rectangle	--> r\n");
	printf("Square		--> s\n");
	printf("Trapezoid	--> z\n");

	printf("Enter the code here.: ");
	scanf("%c", &code);

	switch(code){
	case 'c':
		printf("Circle Area Calculation.\n");
		printf("Enter radius(r) value.: ");
		scanf("%f", &a);

		if(a < 0){
			printf("radius cannot be -ve\n");
			area = -1;
		}else{
			area = 3.14 * a * a;
		}
		break;

	case 't':
		printf("Triangle Area Calculation.\n");
		printf("Enter base(b) value.: ");
		scanf("%f", &a);
		printf("Enter height(h) value.: ");
		scanf("%f", &b);

		if((b<0) || (a<0)){
			printf("base or height cannot be -ve.\n");
			area = -1;
		}else{
			area = a * b / 2;
		}
		break;

	case 'r':
		printf("Rectangle Area Calculation.\n");
		printf("Enter width(w) value.: ");
		scanf("%f", &a);
		printf("Enter length(l) value.: ");
		scanf("%f", &b);

		if((a<0) || (b<0)){
			printf("width or length cannot be -ve.\n");
			area = -1;
		}else{
			area = a * b;
		}

		break;

	case 's':
			printf("Square Area Calculation.\n");
			printf("Enter side(a) value.: ");
			scanf("%f", &a);

			if(a < 0){
				printf("side cannot be -ve.\n");
				area = -1;
			}else{
				area = a * a;
			}
			break;

	case 'z':
			printf("Trapezoid Area Calculation.\n");
			printf("Enter base1(a) value.: ");
			scanf("%f", &a);
			printf("Enter base2(b) value.: ");
			scanf("%f", &b);
			printf("Enter height(h) value.: ");
			scanf("%f", &c);

			if((a < 0) || (b < 0) || (c < 0)){
				printf("base or height cannot be -ve.\n");
				area = -1;
			}else{
				area = ((a + b)/2) * c;
			}
			break;

	default:
			printf("Invalid input\n");
			area = -1;

	}

	if(!(area < 0)){
		printf("Area = %f\n", area);
	}

	wait_for_user_input();

}

void wait_for_user_input(void){
	printf("Press Enter key to exit this application.\n");

	while(getchar() != '\n'){

	}
	getchar();
}
