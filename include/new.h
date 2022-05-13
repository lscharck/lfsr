#ifndef NEW_H
#define NEW_H

#include <stdlib.h>
#include <stdarg.h>
#include <strings.h>
#include <assert.h>
#include <inttypes.h>
#include "types.h"

void *new(const void *type, ...);

void delete(void *item);

void *clone(const void *self);

int differ(const void *self, const void *b);

size_t sizeOf(const void *self);

void update_state(void *self);

size_t get_random(void *self);

void disp(const void *self);

#endif // NEW_H
