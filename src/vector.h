#ifndef DYMC_VEC_H_ 
#define DYMC_VEC_H_ 

#include <stddef.h>

#include "basic_types.h"

typedef struct vector *Vector;

Vector new_Vector();
void Vector_pushBack(Vector self, Object obj);
void* Vector_get(Vector self, size_t n);
size_t Vector_length(Vector self);
void Vector_erase(Vector self, size_t n);
size_t Vector_size(Vector self);
void Vector_reserve(Vector self, size_t n);
void Vector_insert(Vector self, size_t pos, Object obj);

#endif
