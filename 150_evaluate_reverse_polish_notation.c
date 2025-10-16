/* https://leetcode.com/problems/evaluate-reverse-polish-notation/ */
#include <ctype.h>
#include <stdlib.h>
#define NUMBER 0
#define MAXSIZE 10000

int stack[MAXSIZE];
int sp = 0; // stack position

bool _isnumber(char * s) {
  int c;
  while((c = *s++)) {
    if(c == '-' || c == '+') {
      if (isdigit(*s))
        continue;
      else
        return false;
    }
    else if (!isdigit(c))
      return false;
  }
  return true;
}

void push(int x) {
  if (sp < MAXSIZE)
    stack[sp++] = x;
}

int pop(void) {
  return (sp > 0) ? stack[--sp] : 0;
}

int evalRPN(char** tokens, int tokensSize) {
  int i;
  char c;
  char *token;
  for (i = 0; i < tokensSize; ++i) {
    token = tokens[i];
    c = *token;
    if (_isnumber(tokens[i])) {
      c = NUMBER;
    }
    switch (c) {
      case NUMBER:
        push(atoi(token));
        break;
      case '+':
        push(pop()+pop());
        break;
      case '-':
        int right = pop();
        int left = pop();
        push(left - right);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        int denominator = pop();
        int numerator = pop();
        push(numerator/denominator);
        break;
    }
  }
  return pop();
}

#include <assert.h>
int main() {
  char *tokens01[] = {"2", "1", "+"};
  assert(evalRPN(tokens01, 3) == 3);
  char *tokens02[] = {"4","13","5","/","+"};
  assert(evalRPN(tokens02, 5) == 6);
  char *tokens03[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  assert(evalRPN(tokens03, 13) == 22);
  char *tokens04[] = {"4","3","-"};
  assert(evalRPN(tokens04, 3) == 1);
  char *tokens05[] = {"3","-4","+"};
  assert(evalRPN(tokens05, 3) == -1);
}
