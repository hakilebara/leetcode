#include <stdlib.h>
#define STACK_MAX 100

typedef struct {
  int stack[STACK_MAX];
  int pos;
} Stack;

typedef struct {
  Stack a;
  Stack b;
} MyQueue;

void push(Stack *stack, int x) {
  if (stack->pos < STACK_MAX)
    stack->stack[stack->pos++] = x;
}

int pop(Stack *stack) {
  return stack->stack[--stack->pos];
}

int peek(Stack *stack) {
  return stack->stack[stack->pos - 1];
}


MyQueue* myQueueCreate() {
  MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
  queue->a.pos = 0;
  queue->b.pos = 0;
  return queue;
}

void myQueuePush(MyQueue* obj, int x) {
  push(&(obj->a), x);
}

int myQueuePop(MyQueue* obj) {
  while(obj->a.pos > 0)  {
    push(&obj->b, pop(&obj->a));
  }
  int x = pop(&obj->a);
  while(obj->b.pos >= 0) {
    push(&obj->a, pop(&obj->b));
  }
  return x;
}


int myQueuePeek(MyQueue* obj) {
  while(obj->a.pos > 0)  {
    push(&obj->b, pop(&obj->a));
  }
  int x = peek(&obj->a);
  while(obj->b.pos >= 0) {
    push(&obj->a, pop(&obj->b));
  }
  return x;
}

bool myQueueEmpty(MyQueue* obj) {
  return obj->a.pos <= 0; 
}

void myQueueFree(MyQueue* obj) {
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
