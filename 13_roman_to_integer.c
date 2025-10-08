#include <assert.h>

int romanToInt(char* s) {
  int acc = 0;
  char c;
  while ((c = *s++)) {
    switch (c) {
      case 'I':
        if (*s == 'V') {
          acc += 4;
          ++s;
        } else if (*s == 'X') {
          acc += 9;
          ++s;
        }
        else {
          acc += 1;
        }
      break;

      case 'V':
        acc += 5;
      break;

      case 'X':
      if (*s == 'L') {
        acc += 40;
        ++s;
      }
      else if (*s == 'C') {
        acc += 90;
        ++s;
      }
      else {
        acc += 10;
      }
      break;

      case 'L':
        acc += 50;
      break;

      case 'C':
        if (*s == 'D') {
          acc += 400;
          ++s;
        }
        else if (*s == 'M') {
          acc += 900;
          ++s;
        }
        else {
          acc += 100;
        }
      break;

      case 'D':
        acc += 500;
      break;

      case 'M':
        acc += 1000;
      break;

      default:
        return -1;
      break;
    }
  }

  return acc;
}

int main() {
  /* assert(romanToInt("III") == 3); */
  /* assert(romanToInt("LVIII") == 58); */
  assert(romanToInt("MCMXCIV") == 1994);
}
