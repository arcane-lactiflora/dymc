#include "tree_map.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "gc_prelude.h"

int main() {
    TreeMap dict = new_TreeMap((CompareFunc)strcmp);
    
    Integer i = new_Integer(1);
    TreeMap_set(dict, "1", i);
    
    i = new_Integer(2);
    TreeMap_set(dict, "2", i);

    i = new_Integer(3);
    TreeMap_set(dict, "3", i);

    i = new_Integer(4);
    TreeMap_set(dict, "4", i);

    assert(*(Integer)TreeMap_get(dict, "3") == 3);

    TreeMapIter iter = TreeMap_begin(dict);
    for (int i = 1; i <= 4; i++) {
        assert(*(Integer)TreeMapIter_getValue(iter) == i);
        iter = TreeMap_next(dict, iter);
    }

    printf("[PASSED] TreeMap\n");
    return 0;
}
