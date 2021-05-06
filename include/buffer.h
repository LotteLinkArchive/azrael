#pragma once
#include <stdbool.h>
#include <stddef.h>

#include "global.h"
#include "status.h"

struct az_alloc_s {
   void *data;

   void *(*realloc)(void *, void *, size_t);
   void (*free)(void *, void *);
};

typedef struct az_alloc_s az_alloc_t;

struct az_buf_s {
   size_t bytes;
   void *data;

   const az_alloc_t *mi;
};

typedef struct az_buf_s az_buf_t;

#define AZ_MALLOC (&az_galloc)

extern const az_alloc_t az_galloc;
extern const az_buf_t az_defbuf;

AZ_EXTERN az_buf_t az_mkbuf(const az_alloc_t *allocator);
AZ_EXTERN az_stat_t az_rzbuf(az_buf_t *buffer, size_t bytes, bool zero);
AZ_EXTERN void az_frbuf(az_buf_t *buffer);