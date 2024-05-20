/**
 * ctype.h - an example usage of the 
 * standard mapping and testing library remake.
 *
 * Author: ruxixa
 * 
 * Date: 20.05.2024
*/

#include <_stdbool.h>
#include <stdio.h>

// example function returning a boolean value
_bool is_zero(int x) {
    if (x == 0) {
        return true;
    } 
    else {
        return false;
    }
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (is_zero(number)) {
        printf("%d is zero.\n", number);
    } 
    else {
        printf("%d is not zero.\n", number);
    }

    return 0;
}
