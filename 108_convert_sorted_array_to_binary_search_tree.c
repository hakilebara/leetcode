#include <stdlib.h>
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
#include <stdio.h>

struct TreeNode* process(int low, int high, int *nums)
{
  if (low > high) {
    return NULL;
  }  
  int mid;
  mid = (low + high) / 2;
  struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  node->val = nums[mid];

  node->left  = process(low, mid-1, nums);
  node->right = process(mid + 1, high, nums);
  return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  struct TreeNode *tree = process(0, numsSize - 1, nums);
  return tree;
}

int main() {
  int x[] = {-10, -3, 0, 5, 9};
  int *n = x;
  sortedArrayToBST(n, 5);
}
