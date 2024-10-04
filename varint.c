#include <stdint.h>
#include <x86intrin.h>

uint64_t f(uint32_t n) {
    return _pdep_u64(n, ~(~0LU / 510)) |
           _pdep_u64((1 << ((63 - __builtin_clzll(n)) / 7)) - 1, ~0LU / 510);
}
