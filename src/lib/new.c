#include "new.h"

void *new(const void *_class, ...)
{

    //create a new object with the given class pointer and arguments
    const struct Class *class = _class;
    const void *p = calloc(1, class->size);

    assert(p);
    *(const struct Class **) p = class;

    if (class->ctor) {
        va_list ap;

        va_start(ap, _class);
        p = class->ctor(p, &ap);
        va_end(ap);
    }

    return p;

}

void delete(void *self)
{

    // delete the given object
    const struct Class **cp = self;

    if (self && *cp && (*cp)->dtor) {
        self = (*cp)->dtor(self);
    }

    memset(self, 0x00, (*cp)->size);
    free(self);

}

void *clone(const void *self)
{

    // clone an object
    const struct Class * const * cp = self;

    assert(self && *cp && (*cp)->clone);
    return (*cp)->clone(self);

}

int differ(const void *self, const void *b)
{

    // compare two objects
    const struct Class * const * cp = self;

    assert(self && *cp && (*cp)->differ);
    return (*cp)->differ(self, b);

}

size_t sizeOf(const void *self)
{

    // get the size of the object
    const struct Class * const * cp = self;

    assert(self && *cp);
    return (*cp)->size;

}

void update_state(void *self)
{

    // get something from the object
    const struct Class * const * cp = self;

    assert(self && *cp && (*cp)->update_state);
    (*cp)->update_state(self);

}

size_t get_random(void *self)
{

    // get something from the object
    const struct Class * const * cp = self;

    assert(self && *cp && (*cp)->update_state);
    return (*cp)->get_random(self);

}

void disp(const void *self)
{

    // print the needed contents of the object
    const struct Class * const * cp = self;

    assert(self && *cp);
    (*cp)->printer(self);

}
