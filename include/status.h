#pragma once
#include "global.h"

enum az_stat_e {
   /* See az_statstr() in status.c */
   AZ_S_OKAY,
   AZ_S_MOOM
};

typedef unsigned char az_stat_t;

AZ_EXTERN const char *az_statstr(az_stat_t status_code);