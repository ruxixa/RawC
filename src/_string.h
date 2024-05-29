/**
 * _string.h - Standard string operations library.
 * 
 * Author: ruxixa
 * 
 * Date: 20.05.2024
*/

/**
 * _size_t - type representing the size of
 *           the memory block or the length of string.
*/
typedef unsigned long long int _size_t;

/* NULL - a macro representing a null pointer. */
#define _NULL ((void *)0)

/**
 * Get the length of given string.
 * 
 * @param str - the string to be measured.
 * @return the length of the string.
*/
_size_t _strlen(const char* str) {
    _size_t len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/**
 * Copy the string from source to destination.
 * 
 * @param dest - the destination string.
 * @param src - the source string.
 * @return the destination string.
*/
char* _strcpy(char* dest, const char* src) {
    _size_t i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/**
 * Concatenate the source string to the destination string.
 * 
 * @param dest - the destination string.
 * @param src - the source string.
 * @return the destination string.
*/
char* _strcat(char* dest, const char* src) {
    _size_t i = 0;
    _size_t j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return dest;
}

/**
 * Compare two strings.
 * 
 * @param str1 - the first string.
 * @param str2 - the second string.
 * @return 0 if the strings are equal, 
 *         a negative value if str1 is less than str2,
 *         a positive value if str1 is greater than str2.
*/
int _strcmp(const char* str1, const char* str2) {
    _size_t i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

/**
 * Find the first occurrence of a character in the string.
 * 
 * @param str - the string to be searched.
 * @param ch - the character to be found.
 * @return a pointer to the first occurrence of the 
 *         character in the string.
 *         NULL if the character is not found.
*/
char* _strchr(const char* str, int ch) {
    size_t i = 0; // Use size_t for indexing

    while (str[i] != '\0') {
        if (str[i] == (char)ch) {
            return (char*)&str[i];
        }
        i++;
    }

    return (char*)_NULL; // Cast _NULL to char* to match return type
}

/**
 * Find the last occurrence of a character in the string.
 * 
 * @param str - the string to be searched.
 * @param ch - the character to be found.
 * @return a pointer to the last occurrence of the 
 *         character in the string.
 *         NULL if the character is not found.
*/
char * _strrchr(const char* str, int ch) {
    size_t i = 0;
    size_t last = -1; // Initialize last to -1

    while (str[i] != '\0') {
        if (str[i] == (char)ch) {
            last = i;
        }
        i++;
    }

    // if the character is not found
    if (last == -1) {
        return (char*)_NULL;
    }

    return (char*)&str[last];
}

/**
 * Find the first occurrence of a substring in the string.
 * 
 * @param str - the string to be searched.
 * @param substr - the substring to be found.
 * @return a pointer to the first occurrence of the 
 *         substring in the string.
 *         NULL if the substring is not found.
*/
char* _strstr(const char* str, const char* substr) {
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (str[i]
 != '\0') {
        if (str[i] == substr[j]) {
            k = i;
            while (str[k] == substr[j] && substr[j] != '\0') {
                k++;
                j++;
            }
            if (substr[j] == '\0') {
                return (char*)&str[i];
            }
            j = 0;
        }
        i++;
    }

    return (char*)_NULL;
}

/**
 * Find the index of the first occurrence of a character in the string.
 * 
 * @param str - the string to be searched.
 * @param ch - the character to be found.
 * @return the index of the first occurrence of the 
 *         character in the string.
 *         -1 if the character is not found.
*/
int _strindex(const char* str, int ch) {
    _size_t i = 0;

    while (str[i] != '\0') {
        if (str[i] == (char)ch) {
            return i;
        }
        i++;
    }

    return -1;
}

/**
 * Find the index of the last occurrence of a character in the string.
 * 
 * @param str - the string to be searched.
 * @param ch - the character to be found.
 * @return the index of the last occurrence of the 
 *         character in the string.
 *         -1 if the character is not found.
*/
int _strrindex(const char* str, int ch) {
    _size_t i = 0;
    _size_t last = -1; // Initialize last to -1

    while (str[i] != '\0') {
        if (str[i] == (char)ch) {
            last = i;
        }
        i++;
    }

    return last;
}

void* _memcpy(void* dest, const void* src, _size_t n) {
    _size_t i = 0;
    char* d = (char*)dest;
    const char* s = (const char*)src;

    while (i < n) {
        d[i] = s[i];
        i++;
    }

    return dest;
}

void* _memmove(void* dest, const void* src, _size_t n) {
    _size_t i = 0;
    char* d = (char*)dest;
    const char* s = (const char*)src;

    if (d < s) {
        while (i < n) {
            d[i] = s[i];
            i++;
        }
    } else {
        i = n;
        while (i > 0) {
            d[i - 1] = s[i - 1];
            i--;
        }
    }

    return dest;
}

void* _memset(void* dest, int ch, _size_t n) {
    _size_t i = 0;
    char* d = (char*)dest;

    while (i < n) {
        d[i] = (char)ch;
        i++;
    }

    return dest;
}

int _memcmp(const void* ptr1, const void* ptr2, _size_t n) {
    _size_t i = 0;
    const char* p1 = (const char*)ptr1;
    const char* p2 = (const char*)ptr2;

    while (i < n) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
        i++;
    }

    return 0;
}

/**
 * Convert a string to an integer.
 * 
 * @param str - the string to be converted.
 * @return the integer value of the string.
*/
char* _strncpy(char* dest, const char* src, _size_t n) {
    _size_t i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

/**
 * Concatenate the source string to the destination string.
 * 
 * @param dest - the destination string.
 * @param src - the source string.
 * @param n - the number of characters to concatenate.
 * @return the destination string.
*/
char* _strncat(char* dest, const char* src, _size_t n) {
    _size_t i = 0;
    _size_t j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (src[j] != '\0' && j < n) {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return dest;
}

/**
 * Compare two strings.
 * 
 * @param str1 - the first string.
 * @param str2 - the second string.
 * @param n - the number of characters to compare.
 * @return 0 if the strings are equal, 
 *         a negative value if str1 is less than str2,
 *         a positive value if str1 is greater than str2.
*/
int _strncmp(const char* str1, const char* str2, _size_t n) {
    _size_t i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && i < n) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return 0;
}

/**
 * Find the first occurrence of a character in the string.
 * 
 * @param str - the string to be searched.
 * @param ch - the character to be found.
 * @param n - the number of characters to search.
 * @return a pointer to the first occurrence of the 
 *         character in the string.
 *         NULL if the character is not found.
*/
_size_t _strcspn(const char* str, const char* reject) {
    _size_t i = 0;
    _size_t j = 0;

    while (str[i] != '\0') {
        j = 0;
        while (reject[j] != '\0') {
            if (str[i] == reject[j]) {
                return i;
            }
            j++;
        }
        i++;
    }

    return i;
}

/**
 * Find the index of the first occurrence of a character in the string.
 * 
 * @param str - the string to be searched.
 * @param ch - the character to be found.
 * @return the index of the first occurrence of the 
 *         character in the string.
 *         -1 if the character is not found.
*/
_size_t _strspn(const char* str, const char* accept) {
    _size_t i = 0;
    _size_t j = 0;

    while (str[i] != '\0') {
        j = 0;
        while (accept[j] != '\0') {
            if (str[i] == accept[j]) {
                break;
            }
            j++;
        }
        if (accept[j] == '\0') {
            return i;
        }
        i++;
    }

    return i;
}

/**
 * Find the first occurrence of a substring in the string.
 * 
 * @param haystack - the string to be searched.
 * @param needle - the substring to be found.
 * @return a pointer to the first occurrence of the 
 *         substring in the string.
 *         NULL if the substring is not found.
*/
char* _strstr(const char* haystack, const char* needle) {
    _size_t i = 0;
    _size_t j = 0;
    _size_t k = 0;

    while (haystack[i] != '\0') {
        if (haystack[i] == needle[j]) {
            k = i;
            while (haystack[k] == needle[j] && needle[j] != '\0') {
                k++;
                j++;
            }
            if (needle[j] == '\0') {
                return (char*)&haystack[i];
            }
            j = 0;
        }
        i++;
    }

    return (char*)_NULL;
}

/**
 * Tokenize a string.
 * 
 * @param str - the string to be tokenized.
 * @param delim - the delimiter string.
 * @return a pointer to the next token.
 *         NULL if no more tokens are available.
*/
char* _strtok(char* str, const char* delim) {
    static char* token = '\0';
    static char* next = '\0';
    _size_t i = 0;
    _size_t j = 0;

    if (str != '\0') {
        token = str;
    }

    if (token == '\0') {
        return '\0';
    }

    i = _strspn(token, delim);
    if (token[i] == '\0') {
        token = '\0';
        return '\0';
    }

    next = &token[i];
    j = _strcspn(next, delim);
    if (next[j] == '\0') {
        token = '\0';
    } else {
        next[j] = '\0';
        token = &next[j + 1];
    }

    return next;
}