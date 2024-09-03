#include <stdint.h>


int main(void)
{
	uint32_t *pClkctrlreg = (uint32_t*)0x40023830;
	uint32_t *pPortDModereg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutreg = (uint32_t*)0x40020C14;

	*pClkctrlreg |= (1 << 3);

	*pPortDModereg &= ~(3 << 24);

	*pPortDModereg |= (1 << 24);

	*pPortDOutreg |= (1 << 12);

	while(1){
		*pPortDOutreg |= (1 << 12);

		for(uint32_t i=0 ; i < 10000 ; i++ );

		*pPortDOutreg |= ~(1 << 12);

		for(uint32_t i=0 ; i < 10000 ; i++ );
	}

}
