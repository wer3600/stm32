#include<stdio.h>
#include<stdint.h>

int main(void)
{
    uint8_t volatile data1;
    uint8_t volatile data2;

    data1 = 50;

    data2 = data1;

    data2 = data1;

	for(;;);
}
