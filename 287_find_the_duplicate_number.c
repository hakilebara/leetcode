#define MAX_SIZE 100000 + 1
int findDuplicate(int* nums, int numsSize) {
  int freq[MAX_SIZE] = {0};
  int i;
  for (i = 0; i < numsSize; ++i) {
    if (freq[nums[i]] > 0) return nums[i];
    freq[nums[i]] += 1;
  }
  return -1;
}

#include <assert.h>
int main() {
  int nums1[] = {1,3,4,2,2};
  int nums2[] = {3,1,3,4,2};
  int nums3[] = {3,3,3,3,3};
  assert(findDuplicate(nums1, 5) == 2);
  assert(findDuplicate(nums2, 5) == 3);
  assert(findDuplicate(nums3, 5) == 3);
}
