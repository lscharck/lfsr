#ifndef NEW_R
#define NEW_R

#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

struct Class
{
    size_t size;
    void * (*ctor) (void *self, va_list *app);
    void * (*dtor) (void *self);
    void * (*clone) (const void *self);
    int (*differ) (const void *self, const void *b);
    void (*update_state) (void *self);
    size_t (*get_random) (void *self);
    void (*printer) (const void *self);
};

// consider this a generic template for a class

#endif // NEW_R
