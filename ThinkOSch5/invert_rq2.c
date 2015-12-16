#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 12;
	int ones = 255; //flip with ones
	
	int res = (num ^ ones) + 1;
	printf("%d\n", res);	//-12 in 2's complement = 244

    return 0;

    // int num = 12;
    // printf("%d\n", ~num+1); //can use not operator to flip, or flip with 1s
    // return 0;
}