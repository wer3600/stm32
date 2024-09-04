

#include<stdio.h>
#include<stdint.h>

union address
{
	uint16_t shortAddr;
	uint32_t longAddr;
};

int main(void)
{
	union address addr;

	addr.shortAddr = 0xABCD;
	addr.longAddr = 0xEEEECCCC;

	printf("short addr = %#X\n", addr.shortAddr);
	printf("long addr = %#X\n", addr.longAddr);

	getchar();

	return 0;
}
