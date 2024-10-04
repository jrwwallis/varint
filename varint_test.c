#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint64_t f(uint32_t n);

// uint64_t f(uint32_t n) {
//     return _pdep_u64(n, ~(~0LU / 510)) |
//            _pdep_u64((1 << ((63 - __builtin_clzll(n)) / 7)) - 1, ~0LU / 510);
// }

void hexdump(const uint8_t *octets, size_t length) {
    int i;
    for (i = 0; i < length; ++i) {
        printf(" %02x", octets[i]);
        if ((i & ~0xf)) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int testcases[] = {
        12345,
        0,
        1,
        127,
        25565,
        2097151,
        2147483647,
        -1,
        -2147483648,
        1113983
    };

    int i;
    for (i = 0; i < sizeof(testcases) / sizeof(testcases[0]); ++i) {
        uint64_t res64 = f(testcases[i]);
        char *result = (char *)&res64;
        hexdump(result, strlen(result) ?: 1);
    }

    return 0;
}
