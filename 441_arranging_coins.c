#include <math.h>
int arrangeCoins(int n) {
  return floor(((-1+sqrt(1+8*(long)n))/2));
}
#include <assert.h>
int main() {
  assert(arrangeCoins(1804289383) == 60070);
}
