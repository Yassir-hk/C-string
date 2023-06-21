#include <stdio.h>
#include "cstring.h"

int main()
{
  // Test strlen2
  const char *str = "Hello, world!";
  size_t length = strlen2(str);
  printf("Length of '%s' is %zu\n", str, length);

  // Test strcpy2
  char dest[20];
  strcpy2(str, dest);
  printf("Copied string: %s\n", dest);

  // Test strncpy2
  char dest2[10];
  strncpy2(str, dest2, 5);
  printf("Copied string with limit: %s\n", dest2);

  // Test strcat2
  const char *src = ", Welcome!";
  strcat2(src, dest);
  printf("Concatenated string: %s\n", dest);

  // Test strcmp2
  const char *str1 = "abc";
  const char *str2 = "def";
  int result = strcmp2(str1, str2);
  printf("Comparison result: %d\n", result);

  // Test strchr2
  const char *str3 = "Hello, world!";
  char c = 'o';
  char *foundChar = strchr2(str3, c);
  if (foundChar != NULL)
  {
    printf("Character '%c' found at position %ld\n", c, foundChar - str3);
  }
  else
  {
    printf("Character '%c' not found\n", c);
  }

  // Test strstr2
  const char *str4 = "Hello, world!";
  const char *subStr = "world";
  char *foundStr = strstr2(str4, subStr);
  if (foundStr != NULL)
    printf("Substring '%s' found at position %ld\n", subStr, foundStr - str4);
  else
    printf("Substring '%s' not found\n", subStr);

  // Test strcspn2
  const char *str5 = "Hello, world!";
  const char *charsToExclude = "aeiou";
  size_t longestLength = strcspn2(str5, charsToExclude);
  printf("Length of longest substring without vowels: %zu\n", longestLength);

  // Test strrev2
  char city[] = "Newyork";
  strrev2(city);
  printf("City after reverse: %s\n", city);

  // Test strlwr2 and strupr2
  char text[] = "Hello, World!";
  strlwr2(text);
  printf("Lowercase text: %s\n", text);
  strupr2(text);
  printf("Uppercase text: %s\n", text);

  return 0;
}
