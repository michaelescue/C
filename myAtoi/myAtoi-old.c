#include <stdio.h>

// pos/Base definition
#define BASE 10
#define SET_SIZE 256
//#define DEBUG

static signed int num;
static unsigned int pos;
static unsigned int step;
static unsigned int val;
static unsigned int len;
static char valid_set[256];

// Helping inline function to map char to int.
static inline void insert(char x, int y){
    valid_set[x] = y;

    #ifdef DEBUG
        printf("Inserted: char: %c int: %d\n", (char) x, valid_set[x]);
    #endif
}

int myAtoi(char * s){

    #ifdef DEBUG
        printf("Input Argument: \"%s\"\n", s);
    #endif

    // Reset/initialize values.
    num = 0;
    val = 0;
    pos = 0;
    len = 0;
    step = sizeof(*s);
    for(int i = 0; i < SET_SIZE; i++) valid_set[i] = -1;

    // Free moving temp pointer
    char* tmp = s;

    // Build valid map space.
    for(char x = '0'; x <= '9'; x++){
        insert(x, x & 0xF);
    }
    insert('-', 0);
    insert('+', 0);
    insert(' ', 0);

    // Walk to end through valid string chars.
    while(valid_set[*tmp] != -1){
        
        #ifdef DEBUG
            printf("Walk to end: *tmp: %c *valid_set: %d\n", *tmp, valid_set[*tmp]);
        #endif
        
        tmp += step;
    }

    // Backup position to first number.
    while(valid_set[*tmp] <= 0)
        tmp -= step;

    // Walk to front of valid string
    do{

        #ifdef DEBUG
            printf("*tmp: %c pos: %d\n", *tmp, pos);
        #endif

        // Simple exponential without math.h
        val = valid_set[*tmp];
        if(pos > 0)
            for(int i = 0; i < pos; i++)
                val = val * 10;

        
        // Update num
        num = num + val;

        #ifdef DEBUG
            printf("*val: %d num: %d\n", val, num);
        #endif
        
        // Backup position by 1.
        tmp -= step;

        // Control statement
        switch(*tmp){
            case ' ':
                break;
            case '-':
                num = -num;
                break;
            case '+':
                break;
            default:
                pos++;
                break;
        }

    }while(tmp >= s);

    return num;
}