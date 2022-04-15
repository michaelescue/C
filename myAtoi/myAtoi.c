// 0 <= s.length <= 200
#define SIZE 200
#define MAX (int) 0x7FFFFFFF
#define MIN (int) 0x80000000
#define OVERFLOW MIN

#include <stdio.h>

int myAtoi(char * s){

    // Initials
    int num = 0;
    int negative = 0;
    int trailing = 0;
    int count = 0;
    int array[SIZE];
    for(int i = 0; i < SIZE; i++) array[i] = -1;

    #ifdef DEBUG
        printf("Input: \"%s\"\n", s);
    #endif

    // String traversal
    while(*s != '\0'){
        switch(*s){
            case ' ':
                if( (count >0) && (array[count-1] != -1) ) trailing = 1;
                break;
            case '-':
                negative = 1;
                break;
            case '+':
                negative = 0;
                break;
            case '0':
                array[count]=0;
                count++;
                break;
            case '1':
                array[count]=1;
                count++;
                break;
            case '2':
                array[count]=2;
                count++;
                break;
            case '3':
                array[count]=3;
                count++;
                break;
            case '4':
                array[count]=4;
                count++;
                break;
            case '5':
                array[count]=5;
                count++;
                break;
            case '6':
                array[count]=6;
                count++;
                break;
            case '7':
                array[count]=7;
                count++;
                break;
            case '8':
                array[count]=8;
                count++;
                break;
            case '9':
                array[count]=9;
                count++;
                break;
            default:
                trailing = 1;
                break;
        }
        
        #ifdef DEBUG
            printf("*s: %c, negative: %d, array[%d]=%d, trailing: %d\n", *s, negative, count, array[count], trailing);
        #endif
        
        if(trailing != 0) break;
        s++;
    }

    // Num calculation using array
    for(int i = 0; i < count; i++){
        
        for(int j = count-i-1; j>0; j--){
            
            // Check overflow
            if((array[i] *10) & OVERFLOW){
                if(negative) return MIN;
                else return MAX;
            }
            else
                array[i] = (array[i] * 10);
        }
        
        // Check overflow
        if((num + array[i]) & OVERFLOW){
            if(negative) return MIN;
            else return MAX;
        }

        num += array[i];

        #ifdef DEBUG
            printf("array[%d]: %d, count: %d, i: %d, num: %d\n", i, array[i], count, i, num);
        #endif
    }

    // Set Polarity
    if(negative) num = -num;

    // Return final
    return (signed int) num;

}