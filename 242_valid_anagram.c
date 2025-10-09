#include <string.h>
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

#include <stdio.h>
int main() {
  printf("%d\n", isAnagram("anagram", "nagaram"));
  printf("%d\n", isAnagram("aa", "bb"));
}
