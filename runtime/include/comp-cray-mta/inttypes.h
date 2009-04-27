#ifndef _CHPL_MTA_INT_TYPES_H_
#define _CHPL_MTA_INT_TYPES_H_

// subset of standard C's inttypes.h for MTA

#include <stdint.h>

#define PRId8 "hhd"
#define PRId16 "hd" /* this may not be correct! */
#define PRId32 "hd"
#define PRId64  "d"
#define PRIu8 "hhu"
#define PRIu16 "hu" /* this may not be correct! */
#define PRIu32 "hu"
#define PRIu64  "u"
#define PRIxPTR "x"

#define SCNd32 "hd"
#define SCNd64 "d"
#define SCNu32 "hu"
#define SCNu64 "u"

#endif
