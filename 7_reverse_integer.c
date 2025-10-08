#include <limits.h>

int reverse(int x) {
  int acc = 0;
  int sign = 1;

  if (x < 0) {
    if (x == INT_MIN) return 0;
    sign = -1;
    x *= -1;
  }

  do {
    if (acc > INT_MAX/10) return 0;
    acc *= 10;
    acc += x % 10;
  } while ((x /= 10));

  acc *= sign;
  return  acc;
}

#include <assert.h>
int main() {
  assert(reverse(123) == 321);
  assert(reverse(-123) == -321);
  assert(reverse(120) == 21);
  assert(reverse(1534236469) == 0);
  assert(reverse(-2147483648) == 0);
  assert(reverse(-2147483412) == -2143847412);
}
