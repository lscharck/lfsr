#ifndef LFSR_H
#define LFSR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include "new.h"
#include "types.h"

extern const void *lfsr;

static void *lfsr_ctor(void *self, va_list *app);

static void *lfsr_dtor(void *self);

static void *lfsr_clone(const void *self);

static int lfsr_differ(const void *self, const void *b);

static void lfsr_update(void *self);

static size_t lfsr_random(void *self);

static void lfsr_printer(const void *self);

#endif // LFSR_H
