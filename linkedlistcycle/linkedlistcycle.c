
// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

bool hasCycle(struct ListNode *head) {
    
	// Temp pointer for list
    int temp = &head;
    
	// Processing loop.
    while(1){
		
		printf("temp: %d\n\
				head: %d\n\
				next: %d\n",\
				temp,
				head,
				head->next);
	
		if(head->next == temp) return 1;
		else if(head == NULL) return 0;
		else head = head-> next;;
	
    }
	
}