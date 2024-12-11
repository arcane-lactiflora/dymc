#include <assert.h>
#include <stdio.h>

#include "vector.h"
#include "gc_prelude.h"

int main() {
    Vector v = new_Vector();
    Double n = new_Double(42.42);
    Vector_pushBack(v, n);
    assert(*(Double)Vector_get(v, 0) == 42.42);

    v = new_Vector();
    for (int i = 0; i < 10000; i++) {
        Integer x = new_Integer(i);
        Vector_pushBack(v, x);
        assert(Vector_size(v) == i + 1);
    }
    for (int i = 0; i < 10000; i++) {
        assert(*(Integer)Vector_get(v, i) == i);
    }

    printf("[PASSED] Vector\n");
}
