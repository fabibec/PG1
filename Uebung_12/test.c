#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_base(unsigned int dna1,unsigned int dna2);

int main() {
    unsigned int dna1 = 0b00000000000000000000000000100111;
    unsigned int dna2 = 0b11100100000000000000000000000000;
    return check_base(dna1,dna2);
}

/**
 *
 * @param dna1
 * @param dna2
 * @return 1 when
 */
int check_base(unsigned int dna1,unsigned int dna2) {
    int dna2reversed = 0;
    int shift = 0;
    for (int i = 0; i < (sizeof(int) / 2); i += 2) {
        shift = (i != 0) ? 2 : 0;
        dna2reversed = (dna2reversed << shift) | ((dna2 >> i) & 3);
    }
    return dna1 != dna2reversed;
}