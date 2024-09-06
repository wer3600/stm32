#include <stdio.h>

int main(void)
{

	char msg1[] = "Hello how are you?";
	char *pmsg2 = "fastbitlab.com";

	msg1[0] = 'b';
	pmsg2[0] = 'b';

	printf("Message is : %s\n", msg1);
	printf("Message is : %s\n", pmsg2);
	printf("Address of 'pmsg2' variable = %p\n", &pmsg2);
	printf("value of 'pmsg2' variable = %p\n", pmsg2);

	for(;;);
}
