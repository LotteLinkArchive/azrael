#pragma once
#include <limits.h>

#define __az_rol(n, d) ((n << d) | (n >> ((sizeof(n) * CHAR_BIT) - d)))
#define __az_ror(n, d) ((n >> d) | (n << ((sizeof(n) * CHAR_BIT) - d)))
#define __az_swap_s(x, y)          \
   do {                            \
      __typeof__(x) _SWAPVTMP = x; \
      x = y;                       \
      y = _SWAPVTMP;               \
   } while (0)
#define __az_min(a, b)        \
   __extension__({            \
      __typeof__(a) _a = (a); \
      __typeof__(b) _b = (b); \
      _a < _b ? _a : _b;      \
   })
#define __az_max(a, b)        \
   __extension__({            \
      __typeof__(a) _a = (a); \
      __typeof__(b) _b = (b); \
      _a > _b ? _a : _b;      \
   })
#define __az_clamp(minv, x, maxv) (__az_min(__az_max((x), (minv)), (maxv)))
#define __az_unused(x) (void)(x)
#define __az_withini(minv, x, maxv) ((x) <= (maxv) && (x) >= (minv))