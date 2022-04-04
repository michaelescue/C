#include <stdio.h>

typedef struct {
	short a;
	long b;
	char c;
} myStruct;


char* uname[256];

int main(){

myStruct obj;

printf("Sizeof myStruct obj: %d\n", sizeof(obj));

getchar();

return 0;	
}
