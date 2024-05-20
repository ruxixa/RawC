/**
 * ctypeh.c - an example usage of the 
 * standard mapping and testing library remake.
 *
 * Author: ruxixa
 * 
 * Date: 20.05.2024
*/

#include <_ctype.h>
#include <_stdio.h>

int main() {
    char characters[] = {'A', 'z', '5', '!', '\n', ' ', 'a'};
    int size = sizeof(characters) / sizeof(characters[0]);

    for (int i = 0; i < size; i++) {
        char c = characters[i];
        _printf("Character: %c\n", c);
        _printf("isalnum: %d\n", _isalnum(c));
        _printf("isalpha: %d\n", _isalpha(c));
        _printf("isdigit: %d\n", _isdigit(c));
        _printf("isxdigit: %d\n", _isxdigit(c));
        _printf("islower: %d\n", _islower(c));
        _printf("isupper: %d\n", _isupper(c));
        _printf("ispunct: %d\n", _ispunct(c));
        _printf("isspace: %d\n", _isspace(c));
        _printf("isprint: %d\n", _isprint(c));
        _printf("isgraph: %d\n", _isgraph(c));
        _printf("iscntrl: %d\n", _iscntrl(c));
        _printf("\n");
    }

    return 0;
}