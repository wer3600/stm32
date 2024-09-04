#include<stdio.h>
#include<stdint.h>

struct carModel{
	unsigned carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float carWeight;
};

int main(){
	struct carModel carBMW = {2021, 15000, 220, 1330};
	struct carModel carFord = {4031, 35000, 160, 1900.96};
	struct carModel carHonda = {.carWeight = 90.90,.carPrice = 15000};

	printf("Details of car BMW is as follows\n");
	printf("carNumer	 = %u\n", carBMW.carNumber);
	printf("carPrice	 = %u\n", carBMW.carPrice);
	printf("carMaxSpeed	 = %u\n", carBMW.carMaxSpeed);
	printf("carWeight	 = %f\n", carBMW.carWeight);


	carFord.carNumber = 1000;
	printf("Details of car Ford is as follows\n");
	printf("carNumer	 = %u\n", carFord.carNumber);
	printf("carPrice	 = %u\n", carFord.carPrice);
	printf("carMaxSpeed	 = %u\n", carFord.carMaxSpeed);
	printf("carWeight	 = %f\n", carFord.carWeight);
	return 0;
}
