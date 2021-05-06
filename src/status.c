#include "../include/status.h"

const char *az_statstr(az_stat_t status_code)
{
   switch (status_code) {
   case AZ_S_OKAY: return "everything is fine";
   case AZ_S_MOOM: return "malloc out of memory";

   /* If an error code doesn't appear here, it'll just be recorded as "unknown" */
   default: return "unknown error";
   }
}