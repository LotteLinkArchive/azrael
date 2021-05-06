#include "../include/buffer.h"

#include "../include/util.h"

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void *az_brealloc(void *udata, void *target, size_t newsize)
{
   __az_unused(udata);

   return realloc(target, newsize);
}

void az_bfree(void *udata, void *target)
{
   __az_unused(udata);

   free(target);
}

const az_alloc_t az_galloc = { .realloc = az_brealloc, .free = az_bfree, .data = NULL };

const az_buf_t az_defbuf = { .bytes = 0, .data = NULL, .mi = &az_galloc };

az_buf_t az_mkbuf(const az_alloc_t *allocator)
{
   az_buf_t template = az_defbuf;

   if (allocator) template.mi = allocator;

   return template;
}

az_stat_t az_rzbuf(az_buf_t *buffer, size_t bytes, bool zero)
{
   size_t old_size = buffer->bytes;

   buffer->mi->realloc(buffer->mi->data, buffer->data, bytes);
   if (!buffer->data) return AZ_S_MOOM;

   if (zero && bytes > old_size) memset((char *)buffer->data + old_size, 0, bytes - old_size);

   buffer->bytes = bytes;

   return AZ_S_OKAY;
}

void az_frbuf(az_buf_t *buffer)
{
   if (buffer->data) buffer->mi->free(buffer->mi->data, buffer);
}
