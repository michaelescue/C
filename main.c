#include "myAtoi/myAtoi.c"
#include <stdio.h>

int main(){

	printf("Return: %d\n", myAtoi(" -105xxy"));
	printf("Return: %d\n", myAtoi(" 105xxy"));
	printf("Return: %d\n", myAtoi("1"));
	printf("Return: %d\n", myAtoi("1 with words"));
	printf("Return: %d\n", myAtoi("42"));
	printf("Return: %d\n", myAtoi("-91283472332"));
	printf("Return: %d\n", myAtoi("91283472332"));
	printf("Return: %d\n", myAtoi("-2147483648"));
	printf("Return: %d\n", myAtoi("2147483648"));

	
}

