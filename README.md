<p align="center">
  <img src="assets/LOGO.png" alt="# RawC"/>
</p>

RawC is an educational remake of C standard libraries

# Libraries remade

### Remade Libraries:
- stdio.h 

### Planned:
- math.h
- stdlib.h
- string.h

# Usage

1. Clone the repository
```sh
git clone https://github.com/ruxixa/RawC.git
```

2. Copy the **src** folder content to your project include folder
3. Include **RawC** libraries

### Example usage

```C
#include <include/rawc/_stdio.h>

int main() {
    int num;

    _scanf("Enter a number: %d", &num);
    _printf("You entered: %d\n", num);
    
    _FILE* file = _fopen("test", "w+");
    _fwrite("Hello, World!", 1, 13, file);
    _fclose()

    _exit(0);
}
```

# Contributing

You can find more about contributing [here](CONTRIBUTING.md)

# Changelog

All changes are being noted [here](CHANGELOG.md)