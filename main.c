#include <stdio.h>
#include <stdbool.h>
#include "linkedlist/removeNthFromEnd.c"


struct ListNode* get(struct ListNode* head){
	
	head = malloc(sizeof(struct ListNode));
	if(head == NULL) return -1;
	else return head;
	
}


int main(){

	struct ListNode* head;
	struct ListNode* temp;
	
	get(head);

	head->val = 1;
	
	temp = head->next;
	
	get(temp);
	
	temp->val = 2;
	
	temp = temp->next;
	
	get(temp);
	
	temp->val = 3;
	
	temp = temp->next;
	
	get(temp);
	
	temp->val = 4;

	temp = temp->next;
	
	get(temp);
	
	temp->val = 5;

	removeNthFromEnd(head, 2);
	
	return 0;
	
}

