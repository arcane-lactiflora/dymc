#ifndef DYMC_STR_H_
#define DYMC_STR_H_

#include <stdio.h>
#include <stddef.h>

#include "basic_types.h"
#include "vector.h"

String String_strip(String s);
Vector String_split(String str, char delim);

// StringBuilder
typedef struct string_builder* StringBuilder;
StringBuilder new_StringBuilder();
void StringBuilder_append(StringBuilder self, String format, ...);
void StringBuilder_appendChar(StringBuilder self, char c);
String StringBuilder_getString(StringBuilder self);
size_t StringBuilder_size(StringBuilder self);


// Utilities
String fgetline(FILE *fp);
int fpeek(FILE *fp);

#endif
