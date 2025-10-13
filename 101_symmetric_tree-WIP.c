/**
 * definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <math.h>
#include <stdlib.h>
int *tree = NULL;
int count = 0;

void process(int val) {
  tree[count++] = val;
}

void traverse(struct TreeNode *node) {
  if (node != NULL) {
    process(node->val);
    traverse(node->left);
    traverse(node->right);
  }
}

bool isPalindrome(int *first, int *opl) {
  while (first < opl)
    if (*first++ != *--opl)
      return false;
  return true;
}

bool isSymmetric(struct TreeNode* root) {
  tree = (int*)malloc(1000*sizeof(int));

  traverse(root);

  int depth = ceil(log2(count));
  int j = 0;

  while (depth-- > 0) {

    int* first_idx = tree;
    int* opl_idx = tree + (int)pow(2, j);

    if (!isPalindrome(first_idx, opl_idx))
      return false;

    tree = opl_idx;
    ++j;
  }

  free(tree);
  return true; 
}

struct TreeNode *talloc(void) {
  return (struct TreeNode*) malloc(sizeof(struct TreeNode));
}



#include <assert.h>
#include <limits.h>
#include <stdio.h>

struct TreeNode *addtree(struct TreeNode *p, int **val, const int* const opl);
struct TreeNode* buildTree(int * nodes, int n);
void printTree(struct TreeNode * root);

#define NIL INT_MIN
int main() {
  int nodes[] = {1,2,2,3,4,4,3};
  /* int nodes[] = {1,2,2,NIL,3,NIL,3}; */
  struct TreeNode * root = buildTree(nodes, 7);
  /* assert(isSymmetric(root)); */
  printTree(root);

  return 0;
}

// addtree: add a node with val at or below tree
struct TreeNode *addtree(struct TreeNode *p, int **val, const int* const opl)
{ if (*val >= opl)
    return p;

  if (p == nullptr) {
    p = talloc();
    p->val = **val;
    (*val)++;
    p->left = p->right = nullptr;
  } else if (val) {
    p->left = addtree(p->left, val, opl);
    p->right = addtree(p->right, val, opl);
  }
  return p;
};

struct TreeNode* buildTree(int * nodes, int n) {
  int * val = nodes;
  int * opl = nodes + n; // opl: one past last
  int depth = ceil(log2(n));
  struct TreeNode *root = nullptr;

  while(depth-- > 0) {
    root = addtree(root, &val, opl);
  }

  return root;
}

void printTree(struct TreeNode * root) {
  if (root == nullptr) {
    return;
  }
  printf("%d ", root->val);
  printTree(root->left);
  printTree(root->right);
}
