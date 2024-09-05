#include "main.h"

//	uint32_t *pClkctrlreg = (uint32_t*)0x40023830;
//	uint32_t *pPortDModereg = (uint32_t*)0x40020C00;
//	uint32_t *pPortDOutreg = (uint32_t*)0x40020C14;



int main(void)
{

	RCC_AHB1ENR_t 	volatile *const pClkctrlreg 	= (RCC_AHB1ENR_t*)	0x40023830;
	GPIOx_ODR_t 	volatile *const pPortDOutreg 	= (GPIOx_ODR_t*)	0x40020C14;
	GPIOx_MODE_t 	volatile *const pPortDModereg 	= (GPIOx_MODE_t*)	0x40020C00;


	pClkctrlreg->gpiod_en = 1;

	pPortDModereg->pin_12 = 1;

	while(1)
	{
		pPortDOutreg->pin_12 = 1;

		for(uint32_t i = 0 ; i < 300000 ; i++);

		pPortDOutreg->pin_12 = 0;

		for(uint32_t i = 0 ; i < 300000 ; i++);
	}

	for(;;);
}
