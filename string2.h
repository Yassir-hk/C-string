#ifndef STRING2_H
#define STRING2_H

#include <stddef.h>
#include <stdbool.h>


const int ascii_diff = ('a' - 'A');

// Return the maximum value between two values
size_t max2(const size_t val1, const size_t val2)
{
  return val1 < val2 ? val2 : val1;
}

bool is_letter(const char c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool are_same(const char a, const char b)
{
  return a == b || (is_letter(a) && is_letter(b) && (a + ascii_diff == b || a - ascii_diff == b));
}

// Return the length of a string
size_t strlen2(const char *str)
{
  size_t length = 0;

  while (str != NULL && *str++ != '\0')
    length++;
  
  return length;
}

// Copy source string in destination string and return the new string
char *strcpy2(const char *src, char *dest)
{
  if (src == NULL || dest == NULL)
    return dest;

  char *currChar = dest;

  while (*src != '\0')
    *currChar++ = *src++;
  *currChar = '\0';

  return dest;
}

// Copy n character from source string to destination string and return the new string
char *strncpy2(const char *src, char *dest, int n)
{
  if (src == NULL || dest == NULL)
    return dest;

  char *it = dest;

  while (*src != '\0' && n--)
    *it++ = *src++;
  *it = '\0';

  return dest;
}

// Concatenate source string with destination string and return the new string
char *strcat2(const char *src, char *dest)
{
  if (src == NULL || dest == NULL)
    return dest;

  char *it = dest + strlen2(dest);

  while (*src != '\0')
    *it++ = *src++;
  *it = '\0';

  return dest;
}

// Concatenate n character from source string with destination string and return the new string
char *strncat2(const char *src, char *dest, int n)
{
  if (src == NULL || dest == NULL)
    return dest;

  char *it = dest + strlen2(dest);

  while (*src != '\0' && n--)
    *it++ = *src++;
  *it = '\0';

  return dest;
}

// Compare two strings, return a negative value if str1 < str2, 0 if str1 == str2, positive value otherwise
int strcmp2(const char *str1, const char *str2)
{
  if(str1 == NULL && str2 == NULL)
    return 0;
  if(str1 == NULL || str2 == NULL)
    return str1 == NULL ? -1 : 1;

  while (*str1 && *str2)
  {
    if (*str1 != *str2)
      return *str1 - *str2;
    str1++;
    str2++;
  }

  return *str1 - *str2;
}

// Compare the first n character of the two strings
int strncmp2(const char *str1, const char *str2, int n)
{
  if(str1 == NULL && str2 == NULL)
    return 0;
  if(str1 == NULL || str2 == NULL)
    return str1 == NULL ? -1 : 1;

  while (*str1 && *str2 && n--)
  {
    if (*str1 != *str2)
      return *str1 - *str2;
    str1++;
    str2++;
  }

  return *str1 - *str2;
}

// Work like strcmp2, this function doesn't care about upper and lower cases
int stricmp2(const char *str1, const char *str2)
{
  if(str1 == NULL && str2 == NULL)
    return 0;
  if(str1 == NULL || str2 == NULL)
    return str1 == NULL ? -1 : 1;

  while(*str1 != '\0' && *str2 != '\0')
  {
    if(!are_same(*str1, *str2))
      return *str1 - *str2;
    str1++;
    str2++;
  }

  return *str1 - *str2;
}

// Work like strncmp2, this function doesn't care about upper and lower cases
int strnicmp2(const char *str1, const char *str2, int n)
{
  if(str1 == NULL && str2 == NULL)
    return 0;
  if(str1 == NULL || str2 == NULL)
    return str1 == NULL ? -1 : 1;

  while(*str1 != '\0' && *str2 != '\0' && n--)
  {
    if(!are_same(*str1, *str2))
      return *str1 - *str2;
    str1++;
    str2++;
  }

  return *str1 - *str2;
}

// Search for the first occurence of a char in a string and return a pointer to that char
const char *strchr2(const char *str, const char c)
{
  while (str != NULL && *str != '\0')
  {
    if (*str == c)
      return str;
    str++;
  }

  return NULL;
}

// Search for the first occurence of str2 in str1 and return a pointer to that string, otherwise NULL
char *strstr2(const char *str1, const char *str2)
{
  if (str1 == NULL || str2 == NULL)
    return NULL;

  const char *it1 = str1;
  const char *it2 = str2;

  while (*it1 != '\0' && *it2 != '\0')
  {
    if (*it1++ != *it2++)
      it2 = str2;
  }

  return *it2 != '\0' ? NULL : (char *)(it1 - (it2 - str2));
}

// Return the length of the longest sub-string of str1 which not contain any char from str2
size_t strcspn2(const char *str1, const char *str2)
{
  size_t maxlength = 0;
  size_t curlength = 0;

  while (str1 != NULL && *str1 != '\0')
  {
    curlength = (strchr2(str2, *str1++) == NULL) ? curlength + 1 : 0;
    maxlength = max2(maxlength, curlength);
  }

  return maxlength;
}

// Reversing a string
void strrev2(char *str)
{
  const size_t length = strlen2(str);

  for (int i = 0; 2 * i < length - 1; i++)
  {
    char temp = str[length - i - 1];
    str[length - i - 1] = str[i];
    str[i] = temp;
  }
}

// Convert lowercase chars of string to uppercase chars
void strlwr2(char *str)
{
  while (str != NULL && *str != '\0')
  {
    if (*str >= 'A' && *str <= 'Z')
      *str += ascii_diff;
    str++;
  }
}

// Convert uppercase chars of string to lowercase chars
void strupr2(char *str)
{
  while (str != NULL && *str != '\0')
  {
    if (*str >= 'a' && *str <= 'z')
      *str -= ascii_diff;
    str++;
  }
}

#endif
