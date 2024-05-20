/**
 * _stdio.h - Standard input/output library remake.
 * 
 * Author: ruxixa
 * 
 * Date: 17.05.2024
*/

// include guard 
#ifndef __STDIO_H__
#define __STDIO_H__

// unfortunately, I had no clue how to implement
// the stdarg.h library, so I had to use the orginal one
#include <stdarg.h>

/**
 * Determine the architecture and include the
 * proper syscalls header file.
 *
 * Available architectures:
 * - x86_64
 * - i386
 * ! more architectures will be added in the future
 * 
 * If the architecture is not supported, the error
 * "Architecture not supported" will be thrown.
*/
#ifdef __x86_64__
    #include <x86_64/syscalls.h>
#elif defined(__i386__) || defined(__i686__)
    #include <x86/syscalls.h>
#elif defined(__arm__)
    #include <arm/syscalls.h>
#else
    #error "Architecture not supported"
#endif

/**
 * _mode_t - type representing the file mode.
*/
typedef int umode_t;

/**
 * _size_t - type representing the size of
 *           the memory block or the length of string.
*/
typedef unsigned long long int _size_t;

/**
 * _FILE - structure representing the file.
 * 
 * This structure is used to store the information
 * about the file, such as file descriptor, buffer,
 * buffer size, buffer position, error indicator and
 * end-of-file indicator. These informations can
 * be used to perform file in/out operations.
 * 
 * 
 * @param fd file descriptor
 * @param buffer buffer for the file I/O
 * @param buffer_size size of the buffer
 * @param buffer_pos current position in the buffer
 * @param error error indicator
 * @param eof end-of-file indicator
*/
typedef struct {
    int fd;               
    char *buffer;         
    _size_t buffer_size;  
    _size_t buffer_pos;  
    int error;            
    int eof;              
} _FILE;

/**
 * MAX_DIGITS - Maximum number of digits in an integer.
 *              Setting this value to 12 will allow to store an integer
 *              with 12 digits. The value is used to allocate a memory
 *              for a string representation of an integer.
*/
#define MAX_DIGITS 12

/**
 * MAX_BUFFER - Maximum size of a buffer.
 *              Setting this value to 255 will allow to store 255 characters
 *              in a buffer. The value is used to allocate a memory for a
 *              text input.
*/
#define MAX_BUFFER 255

/**
 * NULL - Null pointer. The value is used to check if
 *        a pointer value is empty. 
*/
#define NULL ((void *)0)

/**
 * Library functions:
 *  > in/out operations:
 *   @fn _printf Print a given string to the standard output.
 *   @fn _scanf Scan a text from the standard input using the given format.
 *   @fn _putchar  Put a character to the standard output.
 *   @fn _putc Put a character to the given output.
 *   @fn _puts Print a string to the standard output.
 * 
 *  > file operations:
 *   @fn _rename Rename the given file.
 *   @fn _fopen Open the file.
 *   @fn _fclose Close the file.
 *   @fn _fwrite Write to the stream.
 * 
 *  > other operations:
 *   @fn _exit Exit the program with a given exit code.
 * 
 * Helper functions:
 *  > string operations:
 *  @fn _strlen Get a lenght of an given string.
 *  @fn _atoi Convert a string to an integer.
 *  @fn _int_to_str Convert an integer to a string.
 *  @fn copy_string Copy a string from the source to the destination.
 *  @fn _free Free a memory block.
 *  @fn _int_len Get a lenght of an given inteeger.
*/  

/*
 * Helper functions (not part of the standard library
*/

/**
 * Get a lenght of an given inteeger. If the inteeger is empty, 
 * the function will return 0.
 * 
 * This function is not a part of the standard library,
 * but I had to implement it as a helper function for
 * the _int_to_str function. 
 * 
 * @param text string to get length
 * @return length of the string
*/
_size_t _int_len(int num) {
    _size_t len = 0;

    while (num) {
        num /= 10;
        len++;
    }

    return len;
}

/**
 * Memory block structure
 * 
 * The structure is used to store the memory blocks
 * that are freed by the user. The structure is a singly
 * linked list, where each block contains the size of the
 * memory block and a pointer to the next memory block.
 * 
 * The structure is used to free the memory that is allocated
 * by the _int_to_str function.
 * 
 * @param size size of the memory block
 * @param next pointer to the next memory block
*/
typedef struct memory_block {
    _size_t size;
    struct memory_block *next;
} memory_block;

memory_block *memory_list = NULL;

/**
 * Free a memory block.
 * 
 * The function is used to free the memory block
 * that is allocated by the _int_to_str function.
 * 
 * This function is not a part of the standard library,
 * but I had to implement it as a helper function for
 * in/out operations which require a dynamic memory
 * allocation.
 * 
 * @param ptr pointer to the memory block
*/
void _free(void *ptr) {
    if (ptr == NULL) return; 

    memory_block *block = (memory_block *)((char *)ptr - sizeof(_size_t));

    block->next = memory_list;
    memory_list = block;
}

/**
 * Convert an integer to a string.
 * 
 * The function is used to convert an integer to a string.
 * 
 * This function is not a part of the standard library,
 * but I had to implement it as a helper function for
 * string operations.
 * 
 * @param num integer to convert
 * @return string representation of 
 *         given integer
*/
const char* _int_to_str(int num) {
    static char str[MAX_DIGITS]; 
    _size_t length = _int_len(num);

    for (int i = length - 1; i >= 0; i--) {
        str[i] = num % 10 + '0'; 
        num /= 10; 
    }

    str[length] = '\0';
    return str;
}

/**
 * Get a lenght of an given string. 
 * If the string is empty, 
 * the function will return 0.
 * 
 * @param text string to get length
 * @return length of the string
*/
_size_t _strlen(const char* string) {
    _size_t len = 0;
    while (*string++) len++;
    return len;
}

/**
 * Convert a string to an integer.
 * 
 * Returns the integer representation of the string.
 * 
 * @param str string to convert
 * @return integer representation of the string
*/
int _atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    
    // check if there is an - or + sign
    // to determine the sign of the number
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // convert the string to an integer
    while (str[i] >= '0' && str[i] <= '9') {
        // multiply the result by 10 and add the current digit
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

/**
 * Copy a string from the source to the destination.
 * 
 * The function is used to copy a string from the source
 * to the destination.
 * 
 * @param dest destination string 
 * @param src source string
*/
void copy_string(char *dest, const char *src) {
    // copy the string from the source to the destination
    // in a loop until the null terminator is reached
    while ((*dest++ = *src++) != '\0');
}

/**
 * Exit the program with a given exit code.
 * The function will call the sys_exit
 * syscall to exit the program.
 *
 * @param exit_code exit code of the program
*/
void _exit(int exit_code) { 
    // call the sys_exit syscall
    sys_exit(exit_code);
};

/**
 * Scan a text from the standard input
 * using the given format.
 * 
 * Unfortunately, I couldn't implement the scanf
 * the same way as it is implemented in the standard
 * C library, so insteand of passing regular arguments
 * to the function, You have to pass the references to
 * the variables.
 * 
 * Example usage:
 *  int a;
 *  _scanf("%d", &a);
 * 
 * This will generate an segfault:
 *  int a;
 *  _scanf("%d", a);
 * 
 * @param format format of the input
 * @param ... arguments to modify
*/
void _scanf(const char *format, ...) {
    // initialize the va_list
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            // skip the '%' character
            format++; 
            /**
             * Check the format specifier.
             * 
             * The format specifier can be one of the following:
             * - %d - integer
             * - %s - string
             * 
             * TODO: Add more format specifiers.
             *  
             * If the format specifier is not recognized,
             * the function will print the character without
             * any changes.
            */
            switch (*format) {
                case 'd': {
                    int *arg = va_arg(args, int *);

                    char buffer[MAX_DIGITS];
                    sys_read(1, buffer, MAX_DIGITS);

                    // make the last character a null terminator
                    buffer[_strlen(buffer) - 1] = '\0';

                    int num = _atoi(buffer);

                    *arg = num; 
                    break;
                }
                case 's': {
                    char *arg = va_arg(args, char *);

                    char buffer[MAX_BUFFER];
                    sys_read(1, buffer, MAX_BUFFER); 

                    // make the last character a null terminator
                    buffer[_strlen(buffer) - 1] = '\0';

                    copy_string(arg, buffer);
                    break;
                }
                case '\0': 
                    return;
            }
        // if the character is not a format specifier ('%')
        // just print the character without any changes
        } 
        else _putchar(*format);
        format++;
    }

    // free the va_list
    va_end(args);
}

/**
 * Print a string to the standard output.
 * 
 * The function is using the _printf function
 * to print the string to the standard output.
 * 
 * Example usage:
 * _puts("Hello, World!");
 * 
 * @param str string to print
*/
void _puts(const char *str) {
    _size_t len = _strlen(str);
    
    sys_write(1, str, len);
}

/**
 * Put a character to the standard output.
 * The function will call the sys_write syscall
 * to print the character.
 * 
 * @param character character to print
*/
void _putchar(char character) {
    sys_write(1, &character, 1);
}

/**
 * Put a character to the given output.
 * The function will call the sys_write syscall
 * to print the character.
 * 
 * @param character character to print
 * @param fd file descriptor
*/
void _putc(char character, long fd) {
    sys_write(fd, &character, 1);
}

/**
 * Print a given string to the standard output.
 * 
 * The function is using the _putchar function
 * to print the characters of the string.
 * 
 * Example usage:
 * _printf("Hello, World!\n");
 * 
 * This will print the "Hello, World!" string
 * to the standard output.
 * 
 * @param string string to print
 * @param ... 
*/
void _printf(const char* format, ...) {
    // initialize the va_list
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            // skip the '%' character
            format++; 
            /**
             * Check the format specifier.
             * 
             * The format specifier can be one of the following:
             * - %d - integer
             * - %s - string
             * - %c - character
             * - %x - hexadecimal
             * - %p - pointer
             * 
             * If the format specifier is not recognized,
             * the function will print the character without
             * any changes.
            */
            switch (*format) {
                case 'd': {
                    int num = va_arg(args, int);

                    char* num_str = _int_to_str(num);

                    for (int i = 0; num_str[i] != '\0'; i++) {
                        _putchar(num_str[i]);
                    }

                    _free(num_str); 
                    break;
                }
                case 's': {
                    const char* text = va_arg(args, const char*);

                    while (*text != '\0') {
                        _putchar(*text);
                        text++;
                    }

                    break;
                }
                case 'c': {
                    char c = va_arg(args, int);

                    _putchar(c);
                    break;
                }
                case 'x': {
                    int num = va_arg(args, int);

                    char* num_str = _int_to_str(num);

                    for (int i = 0; num_str[i] != '\0'; i++) {
                        _putchar(num_str[i]);
                    }

                    _free(num_str); 

                    break;
                }
                case 'p': {
                    void* ptr = va_arg(args, void*);

                    // convert the pointer to a string
                    char* ptr_str = _int_to_str((int)ptr);

                    for (int i = 0; ptr_str[i] != '\0'; i++) {
                        _putchar(ptr_str[i]);
                    }

                    _free(ptr_str); 
                    break;
                }
                // check if the format specifier is a null terminator
                case '\0': 
                    return;
            }
        // if the character is not a format specifier ('%')
        // just print the character without any changes
        } 
        else _putchar(*format);
        format++;  
    }

    va_end(args);
}

/**
 * Rename the given file.
 * 
 * syscall to rename the file.
 * 
 * @param old_name old name of the file
 * @param new_name new name of the file
*/
void _rename(const char *old_name, const char *new_name) {
    // call the sys_rename syscall
    sys_rename(old_name, new_name);
}

/**
 * Open the file.
 * 
 * The function is used to open the file
 * with the given name and mode.
 * 
 * @param filename name of the file
 * @param mode mode of the file
 * @return file descriptor
*/
_FILE* _fopen(const char* filename, const char* mode) {
    long flags;

    // create a new file
    _FILE file;
    _FILE *file_ptr = &file;

    /**
     * Check the file mode.
     * 
     * The mode of the file is determined by the
     * first character of the mode string. The mode
     * can be one of the following:
     * 
     * - "r"  - read-only
     * - "w"  - write-only, create, truncate
     * - "a"  - write-only, create, append
     * - "r+" - read-write
     * - "w+" - read-write, create, truncate
     * - "a+" - read-write, create, append
     *  
     * If the mode is not recognized, the default
     * mode is read-only ("r") 
    */
    switch (mode[0])
    {
    case 'r' : flags = _O_RDONLY; break;                            // read-only
    case 'w' : flags = _O_WRONLY | _O_CREAT | _O_TRUNC; break;      // write-only, create, truncate
    case 'a' : flags = _O_WRONLY | _O_CREAT | _O_APPEND; break;     // write-only, create, append
    case 'r+': flags = _O_RDWR; break;                              // read-write
    case 'w+': flags = _O_RDWR | _O_CREAT | _O_TRUNC; break;        // read-write, create, truncate
    case 'a+': flags = _O_RDWR | _O_CREAT | _O_APPEND; break;       // read-write, create, append
    default  : flags = _O_RDONLY; break;                            // DEFAULT: read-only
    }

    file_ptr->fd = sys_open(filename, flags, 0666); 
    file_ptr->buffer = NULL;        
    file_ptr->buffer_size = 0;      
    file_ptr->buffer_pos = 0;       
    file_ptr->error = 0;            
    file_ptr->eof = 0;              

    return file_ptr;
}

/**
 * Close the file.
 * 
 * The function is used to close the file
 * with the given file descriptor.
 * 
 * @param file file to close
*/
void _fclose(_FILE *file) {
    sys_close(file->fd);
}

/**
 * Write to the stream.
 * 
 * The function is used to write the data
 * to the stream.
 * 
 * @param ptr pointer to the data
 * @param size size of the data
 * @param nmemb number of members
 * @param stream stream to write
 * 
 * @return number of bytes written
*/
void _fwrite(char *str, _size_t size, _size_t nmemb, _FILE *stream) {
    sys_write(stream->fd, str, size * nmemb);
}

/**
 * Read from the stream.
 * 
 * The function is used to read the data
 * from the stream.
 * 
 * @param ptr pointer to the data
 * @param size size of the data
 * @param nmemb number of members
 * @param stream stream to read
*/
void _fread(char *str, _size_t size, _size_t nmemb, _FILE *stream) {
    sys_read(stream->fd, str, size * nmemb);
}

#endif // __STDIO_H__