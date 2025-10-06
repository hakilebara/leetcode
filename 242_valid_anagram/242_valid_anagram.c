#include <stdio.h> 

bool isAnagram(char* s, char* t) {
  int s_len, t_len;
  int s_letters[26] = {0};
  int t_letters[26] = {0};
  for (s_len = 0; s[s_len] != '\0'; ++s_len) s_letters[s[s_len] - 97]+= 1;
  for (t_len = 0; t[t_len] != '\0'; ++t_len) t_letters[t[t_len] - 97]+= 1;
  if (s_len != t_len) return false;

  for (int i = 0; i < 26; ++i)
    if (s_letters[i] != t_letters[i])
      return false;

  return true; 
}

int main() {
  printf("%d\n", isAnagram("anagram", "nagaram"));
  printf("%d\n", isAnagram("aa", "bb"));
}
