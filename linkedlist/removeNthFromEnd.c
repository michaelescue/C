/**
 * @file removeNthFromEnd.c
 * @author Michael Escue
 * @brief Recursive remove Nth node from end of list algorithm. ! NOT the fastest method. Using loops with temporary pointers can be faster.
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ListNode.h"

#define DEBUG

unsigned long long count = 0;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
  // Switch Conditions for function re-entry.

  if(head->next == NULL){
      
      count = 0;
      
      #ifdef DEBUG
        printf("NULL. Count: %d, Val: %d, Head: %x, Next: %x\n", count, head->val, head, head->next);
      #endif
      
      count++;
  }
  else{
              
      head->next = removeNthFromEnd(head->next,n);
      
      #ifdef DEBUG
        printf("RETURN. Next: %x\n",head->next);
      #endif

      count++;
  }
  
  // Switch Conditions for return value.

  #ifdef DEBUG
    printf("Count: %d, Val: %d, Head: %x, Next: %x\n", count, head->val, head, head->next);
  #endif

  if(n == count){
      
      #ifdef DEBUG
        printf("%d == %d Head: %x, Next: %x\n", n, count, head, head->next);
      #endif

      return head->next;
  }
  else{
      return head;
  }
}

