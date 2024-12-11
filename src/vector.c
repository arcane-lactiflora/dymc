#include "vector.h"

#include <string.h>

#include "gc_prelude.h"

struct vector {
    size_t length;
    size_t capacity;
    void** buf;
};

static void Vector_enlarge(Vector self) {
    self->buf = realloc(self->buf, self->capacity * sizeof(Object) * 2);
    self->capacity = self->capacity * 2;
}

Vector new_Vector() {
    Vector vec = malloc(sizeof(struct vector));
    vec->length = 0;
    vec->capacity = 16;
    vec->buf = malloc(16 * sizeof(Object));
    return vec;
}

void Vector_pushBack(Vector self, Object obj) {
    if (self->length == self->capacity) Vector_enlarge(self);
    self->buf[self->length] = obj;
    self->length++;
}

Object Vector_get(Vector self, size_t n) {
    if (n < 0 || n >= self->length) return NULL;
    return self->buf[n];
}


void Vector_erase(Vector self, size_t n) {
    if (self->length <= n) {
        return;
    }
    memmove(self->buf + n, self->buf + n + 1, (self->length - n - 1) * sizeof(Object));
    self->length--;
}

size_t Vector_size(Vector self) {
    return self->length;
}

void Vector_reserve(Vector self, size_t n) {
    if (n <= self->capacity) {
        return;
    }
    self->buf = malloc(sizeof(void*) * n);
    self->capacity = n;
}

void Vector_insert(Vector self, size_t pos, Object obj) {
    if (self->length == self->capacity) {
        Vector_enlarge(self);
    }
    if (pos > self->length || pos < 0) return;
    memmove(self->buf + pos + 1, self->buf + pos, sizeof(void*) * (self->length - pos));
    self->buf[pos] = obj;
    self->length++;
}

