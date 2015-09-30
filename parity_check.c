#include <stdio.h>

int parityCheck(int n, int bits);

int main() {
    int parity;
    parity = parityCheck(35, 6);
    printf("parity check result is %d\n", parity);

    return 0;
}

int parityCheck(int n, int bits) {
    int parity = 0;

    while (bits > 0) {
        parity += n&1;
        n = n>>1;
        bits--;
    }

    return (parity % 2) == 0;
}
