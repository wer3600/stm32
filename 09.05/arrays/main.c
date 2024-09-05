

#include<stdio.h>
#include<stdint.h>

int main()
{

	uint8_t someData[10] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

//	printf("Before : 2nd data item %x\n", *(someData + 1));
//
//	*(someData + 1) = 0x9;
//
//	printf("After : 2nd data item %x\n", *(someData + 1));

	printf("contents of this array\n");

	for(uint32_t i =0 ; i < 10 ; i++)
	{
		printf("%x\t", someData[i]);
	}



	printf("\n");

	for(uint32_t i =0 ; i < 10 ; i++)
	{
		someData[i] = 0x33;
		printf("%x\t", someData[i]);
	}

	return 0;
}
