#include <stdbool.h>
#include <stdlib.h>
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void traverse(struct TreeNode* root, int count, int targetSum, bool* flag)
{
  if (root == NULL) return;

  count += root->val;

  if (root->left == NULL && root->right == NULL) {
    if (count == targetSum) {
      *flag = true;
    }
  }

  traverse(root->left, count, targetSum, flag) ;
  traverse(root->right, count, targetSum, flag);
}

bool hasPathSum(struct TreeNode* root, int targetSum) 
{
  if (root == NULL) return false;
  targetSum -= root->val;
  if (root->left == NULL && root->right == NULL) { // at leaf node
    return (targetSum == 0);
  }
  return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

#include <assert.h>
int main()
{
  struct TreeNode tree =
  {
    .val = 5,
    .left =
    &(struct TreeNode){
      .val = 4,
      .left =
      &(struct TreeNode){
        .val = 11,
        .left = &(struct TreeNode){ .val = 7 },
        .right = &(struct TreeNode){ .val = 2 },
      }
    },
    .right =
    &(struct TreeNode){
      .val = 8,
      .left = &(struct TreeNode){ .val = 13 },
      .right = &(struct TreeNode){
        .val = 4,
        .right = &(struct TreeNode){
          .val = 1,
        }
      }
    }
  };
  assert(hasPathSum(&tree, 22));
}
