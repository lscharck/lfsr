#include "lfsr.h"
#include "new.h"

struct lfsr
{
    const void *Class;
    __uint128_t state;
    uint64_t count;
};

static const struct Class _lfsr = {
    sizeof(struct lfsr),
    lfsr_ctor, lfsr_dtor,
    lfsr_clone, lfsr_differ,
    lfsr_update, lfsr_random,
    lfsr_printer
};

// consider the above as a lfsr class; new returns a pointer to an instance of
// this class aka an object

const void *lfsr = &_lfsr;

__uint128_t step(__uint128_t reg);

static void *lfsr_ctor(void *_self, va_list *app)
{

    struct lfsr *self = _self;
    uint64_t seed = va_arg(*app, uint64_t);

    self->state = 0;
    self->state = (__uint128_t)seed;

    self->count = 0;

    return self;

}

static void *lfsr_dtor(void *_self)
{

    struct lfsr *self = _self;

    self->state = 0x0;

    return self;

}

static void *lfsr_clone(const void *_self)
{

    const struct lfsr *self = _self;

    return new(lfsr, self->state);

}

static int lfsr_differ(const void *_self, const void *_b)
{

    const struct lfsr *self = _self;
    const struct lfsr *b = _b;

    if (self == b) {
        return 0;
    }
    else if (!b || b->Class != lfsr) {
        return 1;
    }
    else if (self->state == b->state) {
        return 0;
    }
    else if (self->state != b->state) {
        return 1;
    }
    else {
        return 1;
    }

}

static void lfsr_update(void *_self)
{

    struct lfsr *self = _self;

    for (uint8_t i = 0; i < 64; i++) {
        self->state = step(self->state);
        self->count+=1;
    }

}

static size_t lfsr_random(void *_self)
{

    struct lfsr *self = _self;

    for (uint8_t i = 0; i < 64; i++) {
        self->state = step(self->state);
        self->count+=1;
    }

    return (uint64_t)(self->state >> 64);

}

static void lfsr_printer(const void *_self)
{

    const struct lfsr *self = _self;

    printf("Count: %llu\n\t", self->count);
    printf("Value: %llu\n", (uint64_t)(self->state >> 64));

}

__uint128_t step(__uint128_t reg)
{

    // return a new state
    return (reg << 1) + (((((reg >> 63) ^ (reg >> 62)) ^ (reg >> 60)) ^ (reg >> 59)) & 0x1);
    //return (reg << 1) + (((((reg >> 31) ^ (reg >> 21)) ^ (reg >> 1)) ^ (reg >> 0)) & 0x1);

}
