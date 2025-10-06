#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *indices = (int*)malloc(2*sizeof(int));
    int i,j;
    *returnSize = 2;
    for (i = 0; i < numsSize; ++i) {
      for (j = numsSize - 1; i != j && j > 0; --j) {
        if (nums[i] + nums[j] == target) {
          indices[0] = i;
          indices[1] = j;
          return indices;
        }
      }
    }
    *returnSize = 0;
    return nullptr;
}

int main() {
  int nums[] = {2, 7, 11, 15};
  int ret = 0;
  twoSum(nums, 4, 9, &ret);
}
