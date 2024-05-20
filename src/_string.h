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
#define _NULL ((void*)0)

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

