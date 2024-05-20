/**
 * _ctype.h - Standard mapping and testing library remake.
 *
 * Author: ruxixa
 * 
 * Date: 20.05.2024
*/

#ifndef _CTYPE_H
#define _CTYPE_H

/**
 * Library functions:
 * 
 * > Character modification:
 *  @fn _tolower changes the given character to lowercase.
 *  @fn _toupper changes the given character to uppercase.
 * 
 * > Character classification:
 *  @fn _isalnum checks if the given character is alphanumeric.
 *  @fn _isalpha checks if the given character is alphabetic.
 *  @fn _iscntrl checks if the given character is a control character.
 *  @fn _isdigit checks if the given character is a digit. 
 *  @fn _isgraph checks if the given character is a graphical character.
 *  @fn _islower checks if the given character is a lowercase letter.
 *  @fn _isprint checks if the given character is a printable character.
 *  @fn _ispunct checks if the given character is a punctuation character.
 *  @fn _isspace checks if the given character is a whitespace character.
 *  @fn _isupper checks if the given character is an uppercase letter.
 *  @fn _isxdigit checks if the given character is a hexadecimal digit.
*/

/**
 * Check if the given character is alphanumeric.
 * 
 * Alphanumeric characters are either alphabetic 
 * characters (A-Z, a-z) or digits (0-9).
 * 
 * In the ASCII table, alphanumeric characters range
 * from 'A' to 'Z', 'a' to 'z' and '0' to '9'.
 * 
 * @param character The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 * 
*/
int _isalnum(int character) {
    return (character >= 'A' && character <= 'Z') ||
           (character >= 'a' && character <= 'z') ||
           (character >= '0' && character <= '9');
}

/**
 * Check if the given character is alphabetic.
 * 
 * In the ASCII table, alphabetic characters 
 * range from 'A' to 'Z' and 'a' to 'z'.
 * 
 * @param character The character to check.
 * @return 1 if the character is alphabetic, 0 otherwise.
 * 
*/
int _isalpha(int character) {
    return (character >= 'A' && character <= 'Z') ||
           (character >= 'a' && character <= 'z');
}

/**
 * Check if the given character is a 
 * control character.
 * 
 * Control characters are non-printable characters 
 * that are used to control the display of text and 
 * the flow of data.
 *
 * Examples of control characters include:
 * - Newline character '\n' (ASCII code 10)
 * - Carriage return '\r' (ASCII code 13)
 * - Horizontal tab '\t' (ASCII code 9)
 * 
 * In the ASCII table, control characters range 
 * from 0 to 31 and 127.
 *
 * @param character The character to check.
 * @return 1 if the character is a control character, 
 * 0 otherwise.
 */
int _iscntrl(int character) {
    return (character >= 0 && character <= 31) || (character == 127);
}

/**
 * Check if the given character is a digit.
 * 
 * In the ASCII table, digits range from '0' to '9'.
 *
 * @param character The character to check.
 * @return 1 if the character is a digit, 0 otherwise. 
*/
int _isdigit(int character) {
    return (character >= '0' && character <= '9');
}

/**
 * Check if the given character is a graphical 
 * character.
 * 
 * Graphical characters are characters that have a 
 * visible representation on the screen or display.
 * This includes all printable characters except 
 * for the space character ' ' (ASCII code 32).
 * 
 * In the ASCII table, graphical characters range 
 * from 33 to 126.
 * 
 * @param character The character to check.
 * @return 1 if the character is a graphical
 * character, 0 otherwise.
 * 
*/
int _isgraph(int character) {
    return (character >= 33 && character <= 126);
}

/**
 * Check if the given character is a lowercase letter.
 * 
 * In the ASCII table, lowercase letters range from 
 * 'a' to 'z'.
 * 
 * @param character The character to check.
 * @return 1 if the character is a lowercase 
 * letter, 0 otherwise.
*/
int _islower(int character) {
    return (character >= 'a' && character <= 'z');
}

/**
 * Check if the given character is a 
 * printable character.
 * 
 * Printable characters are characters that 
 * can be printed on the screen or displayed 
 * in some other way.
 * 
 * In the ASCII table, printable characters 
 * range from 32 to 126.
 * 
 * @param character The character to check.
 * @return 1 if the character is printable, 0 otherwise.
*/
int _isprint(int character) {
    return (character >= 32 && character <= 126);
}

/**
 * Check if the given character is a punctuation
 * 
 * Punctuation characters are characters that are
 * used to separate sentences or clauses in writing.
 * 
 * In the ASCII table, punctuation characters include:
 * - Comma ',' (ASCII code 44)
 * - Period '.' (ASCII code 46)
 * - Exclamation mark '!' (ASCII code 33)
 * 
 * and many others.
 * 
 * Punctuation characters range from 33 to 47, 58 to 64,
 * 91 to 96, and 123 to 126.
 * 
 * @param character The character to check.
 * @return 1 if the character is a punctuation character,
 * 0 otherwise.
*/
int _ispunct(int character) {
    return ((character >= 33 && character <= 47) ||
            (character >= 58 && character <= 64) ||
            (character >= 91 && character <= 96) ||
            (character >= 123 && character <= 126));
}

/**
 * Check if the given character is a whitespace character.
 * 
 * Whitespace characters are characters that are used to 
 * separate words or other elements in a text.
 * 
 * In the ASCII table, whitespace characters include:
 * - Space ' ' (ASCII code 32)
 * - Tab '\t' (ASCII code 9)
 * - Newline '\n' (ASCII code 10)
 * - Vertical tab '\v' (ASCII code 11)
 * - Form feed '\f' (ASCII code 12)
 * - Carriage return '\r' (ASCII code 13)
 * 
 * @param character The character to check.
 * @return 1 if the character is a whitespace character,
 * 0 otherwise.
*/
int _isspace(int character) {
    return (character == ' '  || character == '\t' ||
            character == '\n' || character == '\v' ||
            character == '\f' || character == '\r');
}

/**
 * Check if the given character is an uppercase letter.
 * 
 * In the ASCII table, uppercase letters range from 
 * 'A' to 'Z'.
 * 
 * @param character The character to check.
 * @return 1 if the character is an uppercase 
 * letter, 0 otherwise.
*/
int _isupper(int character) {
    return (character >= 'A' && character <= 'Z');
}

/**
 * Check if the given character is a hexadecimal digit.
 * 
 * Hexadecimal digits are digits that are used in the 
 * hexadecimal number system, which uses base 16.
 * 
 * In the ASCII table, hexadecimal digits include:
 * - Digits '0' to '9'
 * - Letters 'A' to 'F' and 'a' to 'f'
 * 
 * @param character The character to check.
 * @return 1 if the character is a hexadecimal digit,
 * 0 otherwise.
*/
int _isxdigit(int character) {
    return (character >= '0' && character <= '9') ||
           (character >= 'A' && character <= 'F') ||
           (character >= 'a' && character <= 'f');
}

/**
 * Convert the given character to lowercase.
 * 
 * If the character is an uppercase letter, it is 
 * converted to its lowercase equivalent.
 * 
 * If the character is not an uppercase letter, 
 * it is returned unchanged.
 * 
 * @param character The character to convert.
 * @return The lowercase equivalent of the character.
*/
int _tolower(int character) {
    if (isupper(character)) {
        // To convert an uppercase letter to lowercase,
        // we just need to add 32 to its ASCII code.
        return character + 32;
    }
    return character;
}

/**
 * Convert the given character to uppercase.
 * 
 * If the character is a lowercase letter, it is 
 * converted to its uppercase equivalent.
 * 
 * If the character is not a lowercase letter, 
 * it is returned unchanged.
 * 
 * @param character The character to convert.
 * @return The uppercase equivalent of the character.
*/
int _toupper(int character) {
    if (islower(character)) {
        // To convert a lowercase letter to uppercase,
        // we just need to subtract 32 from its ASCII code.
        return character - 32; 
    }
    return character;
}

#endif // _CTYPE_H
