#include <stdlib.h>
#include <stdbool.h>
#define STACK_MAX 100
typedef struct {
  int s[STACK_MAX];
  int pos;
} Stack;

void push(Stack* stack, int x) {
  if (stack->pos < STACK_MAX) {
    stack->s[stack->pos++] = x;
  }
}
int pop(Stack* stack) {
  if (stack->pos >= 0) {
    return stack->s[--stack->pos];
  }
  else {
    return -1;
  }
}

bool is_empty(Stack *stack) {
  return stack->pos == 0;
}

int peek(Stack *stack) {
  if (stack->pos >= 0) {
    return stack->s[stack->pos-1];
  }
  return -1;
}

typedef struct {
  Stack s1;
  Stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
  MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
  q->s1.pos = 0;
  q->s2.pos = 0;
  return q;
}

void myQueuePush(MyQueue* obj, int x) {
  push(&obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
  int retvalue;
  while (!is_empty(&obj->s1)) {
    push(&obj->s2, pop(&obj->s1));
  }
  retvalue = pop(&obj->s2);
  while (!is_empty(&obj->s2)) {
    push(&obj->s1, pop(&obj->s2));
  }
  return retvalue;
}

int myQueuePeek(MyQueue* obj) {
  int retvalue;
  while (!is_empty(&obj->s1)) {
    push(&obj->s2, pop(&obj->s1));
  }
  retvalue = peek(&obj->s2);
  while (!is_empty(&obj->s2)) {
    push(&obj->s1, pop(&obj->s2));
  }
  return retvalue;
}

bool myQueueEmpty(MyQueue* obj) {
  return is_empty(&obj->s1) && is_empty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
  free(obj);
}

#include <assert.h>
int main() {
  MyQueue* obj = myQueueCreate();
  myQueuePush(obj, 1);
  myQueuePush(obj, 2);

  int param_2 = myQueuePop(obj);

  int param_3 = myQueuePeek(obj);

  bool param_4 = myQueueEmpty(obj);

  myQueueFree(obj);
  assert(param_2 == 1);
  assert(param_3 == 2);
  assert(param_4 == false);
  
}
