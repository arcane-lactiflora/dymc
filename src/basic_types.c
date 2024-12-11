#include "basic_types.h"

#include "gc_prelude.h"

Integer new_Integer(int32_t val) {
    Integer ret = malloc(sizeof(val));
    *ret = val;
    return ret;
}

Long new_Long(int64_t val) {
    Long ret = malloc(sizeof(val));
    *ret = val;
    return ret;
}

Float new_Float(float val) {
    Float ret = malloc(sizeof(val));
    *ret = val;
    return ret;
}

Double new_Double(double val) {
    Double ret = malloc(sizeof(val));
    *ret = val;
    return ret;
}
