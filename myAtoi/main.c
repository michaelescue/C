#include "myAtoi/myAtoi.c"
#include <stdio.h>

int main(){

	printf("Return: %d\n", myAtoi(" -105xxy"));
	printf("Return: %d\n", myAtoi(" 105xxy"));
	printf("Return: %d\n", myAtoi("1"));

	
}

