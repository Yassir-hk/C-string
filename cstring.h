#ifndef CSTRING_H
#define CSTRING_H

/*
 * Return the maximum value between two values
 */
long max2(const long val1, const long val2) {
  return val1 < val2 ? val2:val1;
}

/*
 * Return the length of a string
 */
size_t strlen2(const char *str) {
  size_t length = 0;
  while (str != NULL && *str++ != '\0')
    length++;
  return length;
}

/*
 * Copy source string in destination string and return the new string
 */
char *strcpy2(const char *src, char *dest) {
  if (src == NULL || dest == NULL) {
    return dest;
  }

  char *currChar = dest;
  while (*src != '\0') {
    *currChar++ = *src++;
  }

  *currChar = '\0';
  return dest;
}

/*
 * Copy n character from source string to destination string and return the new string
 */
char *strncpy2(const char *src, char *dest, size_t n) {
  if (src == NULL || dest == NULL) {
    return dest;
  }

  char *itr = dest;
  while (*src != '\0' && n--) {
    *itr++ = *src++;
  }

  *itr = '\0';
  return dest;
}

/*
 * Concatenate source string with destination string and return the new string
 */
char *strcat2(const char *src, char *dest) {
  if (src == NULL || dest == NULL) {
    return dest;
  }

  char *itr = dest + strlen2(dest);
  while (*src != '\0') {
    *itr++ = *src++;
  }
  
  *itr = '\0';
  return dest;
}

/*
 * Concatenate n character from source string with destination string and return the new string
 */
char *strncat(const char *src, char *dest, size_t n) {
  if (src == NULL || dest == NULL) {
    return dest;
  }
  
  char *itr = dest + strlen2(dest);
  while (*src != '\0' && n--) {
    *itr++ = *src++;
  }
  
  *itr = '\0';
  return dest;
}

/*
 * Compare two strings, return a negative value if str1 < str2, 0 if str1 == str2, positive value otherwise
 */
int strcmp2(const char *str1, const char *str2) {
  if (str1 == str2) {
    return 0;
  } else if (str1 == NULL) {
    return -1;
  } else if (str2 == NULL) {
    return 1;
  }

  while (*str1 != '\0' && *str2 != '\0') {
    if(*str1 != *str2) {
      return *str1 - *str2;
    }
    str1++;
    str2++;
  }

  return (int) (*str1 - *str2);
}

/*
 * Compare the first n character of the two strings
 */
int strncmp2(const char *str1, const char *str2, size_t n) {
  if (str1 == str2) {
    return 0;
  } else if (str1 == NULL) {
    return -1;
  } else if (str2 == NULL) {
    return 1;
  }

  while (*str1 != '\0' && *str2 != '\0' && n--) {
    if(*str1 != *str2) {
      return *str1 - *str2;
    }
    str1++;
    str2++;
  }

  return (int) (*str1 - *str2);
}

/*
 * Search for the first occurence of a char in a string and return a pointer to that char
 */
char *strchr2(const char *str, const char c) {
  if (str == NULL || *str == c) {
    return str;
  }

  while (*str != '\0') {
    if (*str == c) {
      return str;
    }
    str++;
  }

  return NULL;
}

/*
 * Search for the first occurence of str2 in str1 and return a pointer to that string, otherwise NULL
 */
char *strstr2(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) {
    return NULL;
  }

  const char *str1Itr = str1;
  const char *str2Itr = str2;

  while (*str1Itr != '\0' && *str2Itr != '\0') {
    if(*str1Itr++ != *str2Itr++) {
      str2Itr = str2;
    }
  }

  return *str2Itr != '\0' ? NULL:str1Itr - (int) (str2Itr - str2);
}

/*
 * Return the length of the longest sub-string of str1 which not contain any char from str2
 */
size_t strcspn2(const char *str1, const char *str2) {
  size_t maxlength = 0;
  size_t curlength = 0;

  while (str1 != NULL && *str1 != '\0') {
    curlength = (strchr2(str2, *str1++) == NULL) ? curlength + 1:0;
    maxlength = max2(maxlength, curlength);
  }

  return maxlength;
}

/*
 * Reversing a string
 */
void strrev2(char *str) {
  const size_t length = strlen2(str);
  for (size_t i = 0; 2*i < length-1; i++) {
    char temp = str[length-i-1];
    str[length-i-1] = str[i];
    str[i] = temp;
  }
}

/*
 * Convert lowercase chars of string to uppercase chars
 */
void strlwr2(char *str) {
  while (str != NULL && *str != '\0') {
    if(*str >= 'A' && *str <= 'Z') {
      *str += ('a' - 'A');
    }
    str++;
  }
}

/*
 * Convert uppercase chars of string to lowercase chars 
 */
void strupr2(char *str) {
  while (str != NULL && *str != '\0') {
    if (*str >= 'a' && *str <= 'z') {
      *str -= ('a' - 'A');
    }
    str++;
  }
}

#endif