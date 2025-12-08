#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) { return (a > b) ? a : b; }

int maxDepth(struct TreeNode* root) {
   if (root == NULL) return 0;
   return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

#include <assert.h>
int main() {
  struct TreeNode tree = {
    .val = 3,
    .left = &(struct TreeNode){ .val = 9 },
    .right = &(struct TreeNode) {
      .val = 20,
      .left = &(struct TreeNode){ .val = 15 },
      .right = &(struct TreeNode){ .val = 7 }
    }
  };
  assert(maxDepth(&tree)==3);
}
