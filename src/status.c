#include "../include/status.h"

const char *az_statstr(az_stat_t status_code)
{
   switch (status_code) {
   case AZ_STATUS_OKAY:
      return "everything is fine";
   default:
      return "unknown error";
   }
}