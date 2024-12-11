#ifndef DYMC_BASIC_TYPE_H_
#define DYMC_BASIC_TYPE_H_

#include <stdint.h>

typedef int32_t * Integer;
typedef int64_t * Long;
typedef float * Float;
typedef double * Double;
typedef const char* String;
typedef char* ByteArray;
typedef void* Object;

Integer new_Integer(int32_t val);
Long new_Long(int64_t val);
Float new_Float(float val);
Double new_Double(double val);

#endif
