
#include <stdint.h>
#include<stdio.h>

void delay(void)
{
	for(uint32_t i=0 ; i<300000 ; i++);
}

int main(void)
{

	uint32_t volatile *const pGPIODModeReg 	= (uint32_t*)(0x40020800);
	uint32_t volatile *const pInputDataReg 	= (uint32_t*)(0x40020800 + 0x10);
	uint32_t volatile *const pOutputDataReg = (uint32_t*)(0x40020800 + 0x14);
	uint32_t volatile *const pClockctrlReg 	= (uint32_t*)(0x40023800 + 0x30);
	uint32_t volatile *const pPullupDownReg = (uint32_t*)(0x40020800 + 0x0C);

	*pClockctrlReg |= (1 >> 3);

	*pGPIODModeReg &= ~(0xFF);
	*pGPIODModeReg |= 0x55;

	*pGPIODModeReg &= ~(0xFF << 16);

	*pPullupDownReg &= ~(0xFF << 16);
	*pPullupDownReg |= ~(0x55 << 16);


while(1){
	*pOutputDataReg |= 0x0f;

	*pOutputDataReg &= ~( 1 << 0 );

	if(!(*pInputDataReg & (1 << 8)))
	{
		delay();
		printf("1\n");
	}

	if(!(*pInputDataReg & (1 << 9)))
	{
		delay();
		printf("2\n");
	}

	if(!(*pInputDataReg & (1 << 10)))
	{
		delay();
		printf("3\n");
	}

	if(!(*pInputDataReg & (1 << 11)))
	{
		delay();
		printf("A\n");
	}

	*pOutputDataReg |= 0x0f;

	*pOutputDataReg &= ~( 1 << 1 );

	if(!(*pInputDataReg & (1 << 8)))
		{
			delay();
			printf("4\n");
		}

		if(!(*pInputDataReg & (1 << 9)))
		{
			delay();
			printf("5\n");
		}

		if(!(*pInputDataReg & (1 << 10)))
		{
			delay();
			printf("6\n");
		}

		if(!(*pInputDataReg & (1 << 11)))
		{
			delay();
			printf("B\n");
		}

		*pOutputDataReg |= 0x0f;

		*pOutputDataReg &= ~( 1 << 2 );

		if(!(*pInputDataReg & (1 << 8)))
		{
			delay();
			printf("7\n");
		}

		if(!(*pInputDataReg & (1 << 9)))
		{
			delay();
			printf("8\n");
		}

		if(!(*pInputDataReg & (1 << 10)))
		{
			delay();
			printf("9\n");
		}

		if(!(*pInputDataReg & (1 << 11)))
		{
			delay();
			printf("C\n");
		}


		*pOutputDataReg |= 0x0f;

		*pOutputDataReg &= ~( 1 << 3 );

		if(!(*pInputDataReg & (1 << 8)))
		{
			delay();
			printf("*\n");
		}

		if(!(*pInputDataReg & (1 << 9)))
		{
			delay();
			printf("0\n");
		}

		if(!(*pInputDataReg & (1 << 10)))
		{
			delay();
			printf("#\n");
		}

		if(!(*pInputDataReg & (1 << 11)))
		{
			delay();
			printf("D\n");
		}
}
	for(;;);
}
