#include <stdint.h>


int main(void)
{
	uint32_t *pClkctrlreg = (uint32_t*)0x40023830;
	uint32_t *pPortDModereg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutreg = (uint32_t*)0x40020C14;

	uint32_t *pPortAModereg = (uint32_t*)0x40020000;
	uint32_t *pPortAInReg = (uint32_t*)0x40020010;

	*pClkctrlreg |= (1 << 3);
	*pClkctrlreg |= (1 << 0);

	*pPortDModereg &= ~(3 << 24);

	*pPortDModereg |= (1 << 24);

	*pPortAModereg &= ~(3 << 0);



	while(1){

		uint8_t pinStatus = (uint8_t)(*pPortAInReg & 0x1);

		if(pinStatus){
			*pPortDOutreg |= (1 << 12);
		}
		else{
			*pPortDOutreg &= ~(1 << 12);
		}
	}

}
