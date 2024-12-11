#include "str.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gc_prelude.h"
#include "vector.h"

void* str_split(String str, char delim) {
    void* ret = new_Vector();

    if (str == NULL) return NULL;
    if (*str == '\n') {
        return ret;
    }
    int count = 0;
    const char *begin = str;
    for (const char *p = str; *p != '\0'; p++) {
        if (*p != delim && !(delim == '\0' && isspace(*p))) {
            continue;
        }
        int size = p - begin;
        if (size > 0) count++;
    }
    count++;

    begin = str;
    int i = 0;
    bool finished = false;
    for (const char *p = str; !finished; p++) {
        if (*p == '\0') finished = true;
        if (*p != delim && *p != '\0' && !(delim == '\0' && isspace(*p))) {
            continue;
        }
        int size = p - begin;
        if (size == 0) {
            begin = p + 1;
            continue;
        }
        char *buf = malloc(sizeof(char) * (size + 1));
        buf[size] = '\0';
        memcpy(buf, begin, size * sizeof(char));
        begin = p + 1;
        Vector_pushBack(ret, buf);
    }
    return ret;
}

String str_strip(String str) {
    if (str == NULL) return NULL;
    int len = strlen(str);
    const char *begin = str;
    const char *end = str + len - 1;
    while (isspace(*begin) && begin < end) {
        begin++;
    }
    while (isspace(*end) && end >= begin) {
        end--;
    }
    len = end - begin + 1;
    char *buf = malloc(sizeof(char) * (len) + 1);
    buf[len] = '\0';
    memcpy(buf, begin, len);
    return buf;
}

struct string_builder {
    size_t size;
    size_t cap;
    char *buf;
};

StringBuilder new_StringBuilder() {
    StringBuilder self = malloc(sizeof(struct string_builder));
    *self = (struct string_builder){.size = 0, .cap = 16};
    self->buf = malloc(sizeof(char) * 17);
    return self;
}

static void StringBuilder_reserve(StringBuilder self, int extra) {
    if (self->size + extra <= self->cap) {
        return;
    }
    int new_cap = (self->size + extra) * 2;
    self->buf = realloc(self->buf, new_cap + 1);
    memset(self->buf + self->cap, 0, new_cap - self->cap + 1);
    self->cap = new_cap;
}

void StringBuilder_append(StringBuilder self, String format, ...) {
    va_list va1;
    va_list va2;
    va_start(va1, format);
    va_copy(va2, va1);
    int size = vsnprintf(NULL, 0, format, va1);
    StringBuilder_reserve(self, size);
    vsnprintf(self->buf + self->size, self->cap - self->size + 1, format, va2);
    self->size += size;
}

void StringBuilder_appendChar(StringBuilder self, char c) {
    StringBuilder_reserve(self, 1);
    self->buf[self->size] = c;
    self->size++;
}

String StringBuilder_getString(StringBuilder self) {
    return self->buf;    
}

size_t StringBuilder_size(StringBuilder self) {
    return self->size;
}

String fgetline(FILE *fp) {
    StringBuilder sb = new_StringBuilder();
    while (true) {
        int c = fgetc(fp);
        if (c == EOF && StringBuilder_size(sb) == 0) return NULL;
        if (c != EOF) StringBuilder_appendChar(sb, c);
        if (c == EOF || c == '\n') return StringBuilder_getString(sb);
    }
    return NULL;
}

int fpeek(FILE *fp) {
    int c = fgetc(fp);
    if (c == EOF) return c;
    ungetc(c, fp);
    return c;
}
