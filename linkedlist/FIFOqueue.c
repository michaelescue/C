#define debug_ptr(x) printf("%s = 0x%x\n", #x, x)
#define debug_int(x) printf("%s = (int) %d\n", #x, x)
#define debug_bool(x) printf("%s = %x\n", #x, x ? "True" : "False")
#define debug_struct(x) debug_int(x->val), debug_ptr(x->next), debug_ptr(x->prev)
#define sprint(x) printf("%s\n", #x)

typedef struct MyQueue {
    int val;
    struct MyQueue *next, *prev;
    
    /* Remember that C structs cannot include functions,
        but function pointers are allowed */
    

}MyQueue;

void myQueueFree(MyQueue* obj);
bool myQueueEmpty(MyQueue* obj);
int myQueuePeek(MyQueue* obj);
int myQueuePop(MyQueue* obj);
void myQueuePush(MyQueue* obj, int x);
MyQueue* myQueueCreate();

MyQueue* myQueueCreate() {
    sprint(Create);
    
    MyQueue *tmp = malloc(sizeof(MyQueue));
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->val = 0;
    return tmp;
}

void myQueuePush(MyQueue* obj, int x) { 
    sprint(Push);
    
    debug_int(x);
    
    MyQueue *p = myQueueCreate();
    MyQueue *tmp = obj;
    
    while(tmp->prev != NULL)
        tmp = tmp->prev;
    
    tmp->prev = tmp;
    tmp->prev = NULL;
    tmp->val = x;
    
}

int myQueuePop(MyQueue* obj) {
    sprint(Pop);
    
    int tmp_val;
    MyQueue *tmp = obj;
    tmp = tmp->prev;
    tmp_val = tmp->val;
    obj->prev = tmp->prev;
    debug_ptr(tmp);
    free(tmp);
    debug_int(tmp_val);
    return tmp_val;
  
}

int myQueuePeek(MyQueue* obj) {
    sprint(Peek);
    
    return obj->prev->val;
}

bool myQueueEmpty(MyQueue* obj) {
    sprint(Empty);
    
    if( (obj->prev == NULL) )
        return 1;
    else
        return 0;
}

void myQueueFree(MyQueue* obj) {
    sprint(Free);
    
    while(!myQueueEmpty(obj)){
        sprint(Not Empty);
        myQueuePop(obj);
    }
    
    free(obj);
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/