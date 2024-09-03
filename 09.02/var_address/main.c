#include <stdio.h>

void myFun1(void);

int count = 0;

int main()
{
    myFun1();

    myFun1();

    myFun1();

    myFun1();

    return 0;
}

void myFun1(void){
    count = count + 1;

    printf("This Function Executed %d time(s)\n", count);
}
