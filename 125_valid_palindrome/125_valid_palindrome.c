#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
bool isPalindrome(char* s) {
  char c;
  if (strlen(s) < 2) return true;
  char *str = (char*)malloc(strlen(s) + 1);
  char *str_start = str;
  int i, j;

  while ((c = *s++)) {
    if (c >= 'A' && c <= 'Z') {
      c += 32; // change to lowercase
    }
    if (! ( (c >= 'a' && c < 'z') || (c >= '0' && c <= '9') ) ) {
      continue;
    }
    *(str++) = c;
  }
  *str = '\0';

  for (i = 0, j = strlen(str_start) - 1; i < j; ++i, --j) {
    if (str_start[i] != str_start[j])
      return false;
  }

  free(str_start);
  return true;
}

int main() {
  assert(isPalindrome("A man, a plan, a canal: Panama"));
  assert(!isPalindrome("race a car"));
  assert(isPalindrome(""));
  assert(isPalindrome("a"));
  assert(!isPalindrome("0P"));
}
