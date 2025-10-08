#include <assert.h>

#define MAXVAL 100
char stack[MAXVAL];
int stack_pos = 0;

void push(char c) {
  if (stack_pos < MAXVAL)
    stack[stack_pos++] = c;
}

char pop() {
  return (stack_pos > 0) ? stack[--stack_pos] : 0;
}

bool isValid(char* s) {
  char c; 
  bool ret = false;
  while ((c = *s++)) {
    if (c == '(' || c == '[' || c == '{')
      push(c);
    else {
      if (c == '\0')
        return false;
      switch (c) {
        case ')':
          if (pop() != '(')
            return false;
          else ret = true;
        break;

        case '}':
          if (pop() != '{')
            return false;
          else ret = true;
        break;

        case ']':
          if (pop() != '[')
            return false;
          else ret = true;
        break;

        default:
          return false;
        break;
      }
    }
  }
  return ret;
}

int main() {
  assert(isValid("[]"));
  assert(isValid("()[]{}"));
  assert(isValid("([])"));
  assert(!isValid("(])"));
  assert(!isValid("([)]"));
  assert(!isValid(""));
  assert(!isValid("]"));
}
