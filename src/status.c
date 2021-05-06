#include "../include/status.h"

const char *az_statstr(az_stat_t status_code)
{
   switch (status_code) {
   case AZ_S_OKAY: return "everything is fine";
   case AZ_S_OOM: return "out of memory";
   default: return "unknown error";
   }
}