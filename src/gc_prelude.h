#ifndef DYMC_GC_PRELUDE_H_
#define DYMC_GC_PRELUDE_H_

#include <gc.h>

#define malloc(x) GC_malloc((x))
#define free(x) GC_free((x))
#define realloc(x, y) GC_realloc((x), (y))

#endif
