/**
 * stdioh.c - an example usage of the 
 * standard input/output library remake.
 * 
 * This file uses only few functions from the
 * _stdio.h library, such as _printf, _scanf,
 * _fopen, _fwrite, _fclose and _exit, you can
 * find the full list of functions in the
 * _stdio.h file. (line 96)
 *
 * Author: ruxixa
 * 
 * Date: 20.05.2024
*/

#include <_stdio.h>

int main() {
    int num;

    _scanf("Enter a number: %d", &num);
    _printf("You entered: %d\n", num);
    
    _FILE* file = _fopen("test.txt", "w+");
    _fwrite("Hello, World!", 1, 13, file);

    _printf("Wrote to file test.txt: %d\n");

    _fclose(file);

    _exit(0);
}