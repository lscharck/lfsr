#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include "new.h"
#include "lfsr.h"

int main()
{

    // TODO: Should the user be allowed to pass the seed?
    // And the user should probably only be allowed to call update_state
    // or get_random ie. no disp.
    uint64_t seed = 0;
    arc4random_buf(&seed, sizeof(seed));

    void *a = new(lfsr, seed);
    void *b = clone(a);
    void *c = new(lfsr, seed);

    printf("Seed: %llu\n", seed);
    disp(a);
    disp(b);
    disp(c);

    update_state(a);
    disp(a);

    printf("\nRandom: %llu\n", (uint64_t)get_random(b));
    disp(b);


    delete(a);
    delete(b);
    delete(c);

//    uint64_t i = 0;
//    reg |= 0xFFFF; // initialize the register to all ones
/*
    do {
        reg = step(reg);
        print_bit(reg);
        i++;
    }
    while (reg != init_reg);
    printf("Period: %llu\n", i);
*/

}
