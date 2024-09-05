#include<stdio.h>
#include<stdint.h>

void wait_for_user_input(void);

int main(void)
{

	uint32_t nItem1, nItem2;
	printf("Array swapping program\n");
	printf("Enter no of elements of Array-1 or Array-2: ");
	scanf("%d %d", &nItem1, &nItem2);

	if((nItem1 < 0) || (nItem2) < 0)
	{
		printf("number of elements cannot be negative.\n");
		wait_for_user_input();

		return 0;
	}

	uint32_t array1[nItem1];
	uint32_t array2[nItem2];

	for(uint32_t i = 0 ; i < nItem1 ; i++)
	{
		printf("Enter %d element of array1:", i);
		scanf("%d", &array1[i]);
	}

	for(uint32_t i = 0 ; i < nItem2 ; i++)
	{
		printf("Enter %d element of array2:", i);
		scanf("%d", &array2[i]);
	}

	printf("Contents of array before swap \n");
	for(uint32_t i = 0 ; i < nItem1 ; i ++)
	{
		printf("%d\t", array1[i]);
	}
	printf("\n");
	for(uint32_t i = 0 ; i < nItem2 ; i ++)
	{
		printf("%d\t", array2[i]);
	}

	printf("\n");

	printf("Contents of array after swap \n");
	for(uint32_t i = 0 ; i < nItem2 ; i ++)
	{
		printf("%d\t", array2[i]);
	}
	printf("\n");
	for(uint32_t i = 0 ; i < nItem1 ; i ++)
	{
		printf("%d\t", array1[i]);
	}

	wait_for_user_input();


}

void wait_for_user_input(void)
{

	printf("\nPress Enter key to exit this application.");
	while(getchar() != '\n')
	{

	}

	getchar();
}
