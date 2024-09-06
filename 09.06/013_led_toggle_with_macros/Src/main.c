#include "main.h"

//	uint32_t *pClkctrlreg = (uint32_t*)0x40023830;
//	uint32_t *pPortDModereg = (uint32_t*)0x40020C00;
//	uint32_t *pPortDOutreg = (uint32_t*)0x40020C14;



int main(void)
{

	RCC_AHB1ENR_t 	volatile *const pClkctrlreg 	= ADDR_REG_AHB1ENR;
	GPIOx_ODR_t 	volatile *const pPortDOutreg 	= ADDR_REG_GPIOD_OD;
	GPIOx_MODE_t 	volatile *const pPortDModereg 	= ADDR_REG_GPIOD_MODE;


	pClkctrlreg->gpiod_en = CLOCK_ENABLE;

	pPortDModereg->pin_12 = MODE_CONF_OUTPUT;

	while(1)
	{
		pPortDOutreg->pin_12 = PIN_STATE_HIGH;

		for(uint32_t i = 0 ; i < DELAY_COUNT ; i++);

		pPortDOutreg->pin_12 = PIN_STATE_LOW;

		for(uint32_t i = 0 ; i < DELAY_COUNT ; i++);
	}

	for(;;);
}
