#include <stdlib.h>
#include <string.h>
bool isAnagram(char* s, char* t);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
  int ls = strlen(s); int lp = strlen(p);
  int *returnArray = (int*)malloc(ls*sizeof(int));
  int i, count;
  count = 0;
  for (i = 0; i <= ls - lp; ++i) {
    char p_copy[lp+1];
    strncpy(p_copy, s+i, lp);
    p_copy[lp] = '\0';
    if (isAnagram(p, p_copy)) {
      returnArray[count++] = i;
    }
  }

  *returnSize = count;
  return returnArray;
}

bool isAnagram(char* s, char* t) {
  if (strlen(s) != strlen(t)) 
    return false;

  int i;
  int letter_frequency[26] = {0};


  for (i = 0; i < strlen(s); ++i) {
    letter_frequency[s[i] - 'a']++;
    letter_frequency[t[i] - 'a']--;
  }

  for (i = 0; i < 26; ++i)
    if (letter_frequency[i] != 0)
      return false;

  return true; 
}

#include <assert.h>
#include <stdio.h>

int main() {

  int* test1 = nullptr;
  int size = 0;
  test1 = findAnagrams("abab", "ab", &size);
  for (int i = 0; i < size; ++i) {
    printf("%d ", test1[i]);
  }
  printf("\n");

  return 0;
}
