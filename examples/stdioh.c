#include <_stdio.h>

int main() {
    int num;

    _scanf("Enter a number: %d", &num);
    _printf("You entered: %d\n", num);
    
    _FILE* file = _fopen("test", "w+");
    _fwrite("Hello, World!", 1, 13, file);
    _fclose()

    _exit(0);
}