#include <stdint.h>


int main(void)
{
	uint32_t *pClkctrlreg = (uint32_t*)0x40023830;
	uint32_t *pPortDModereg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutreg = (uint32_t*)0x40020C14;

	*pClkctrlreg |= 0x08;

	*pPortDModereg &= 0xFCFFFFFF;

	*pPortDModereg |= 0x01000000;

	*pPortDOutreg |= 0x1000;

	while(1);

}
