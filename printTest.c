#include <stdio.h>

#define FORMAT "%s! C is cool!\n"

int main(void) {
    printf("%c%c%c", 'H', 105, '\41');

    printf("He sold the painting for $%2.2f.\n", 2.345e2);

    printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);

    printf("%4X\n", 0x8A);

    printf("%10f\n", 232.346);

    printf("%12e\n", 2.33e+002);

    int x;
    printf("%d\n", 3/5*22.0);

    printf(FORMAT, FORMAT);

    return 1;
}
