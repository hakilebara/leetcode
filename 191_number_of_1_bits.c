int hammingWeight(int n) {
  int acc = 0;
  while (n > 0) {
    acc += n & 1;
    n >>= 1;
  }    
  return acc;
}

#include <assert.h>
int main() {
  assert(hammingWeight(11) == 3);
  assert(hammingWeight(128) == 1);
  assert(hammingWeight(128) == 1);
}
