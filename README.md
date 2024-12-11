# DymC

Programming C in Java-style with [bdwgc](https://github.com/ivmai/bdwgc).

## Dependencies

Arch Linux:

    sudo pacman -S libgc

Ubuntu/Debian:

    sudo apt install libgc libgc-dev

## Build

    make

Run tests:

    make test

## Examples

### Vector

    #include <stdio.h>

    #include "dymc.h"

    int main() {
        Vector v = new_Vector();
        
        Integer elem = new_Integer(100);
        Vector_pushBack(v, elem);

        elem = new_Integer(101);
        Vector_pushBack(v, elem);

        for (int i = 0; i < Vector_size(v); i++) {
            printf("%d\n", *(Integer)Vector_get(v, i));
        }

        return 0;
    }

### TreeMap

    #include <stdio.h>
    #include <string.h>

    #include "dymc.h"

    int main() {
        TreeMap dict = new_TreeMap((CompareFunc)strcmp);

        TreeMap_set(dict, "a", new_Integer(1));
        TreeMap_set(dict, "b", new_Integer(2));

        printf("%d\n", *(Integer)TreeMap_get(dict, "a"));

        TreeMapIter iter;
        for (iter = TreeMap_begin(dict);
                iter != NULL;
                iter = TreeMap_next(dict, iter)) {
            printf("key: %s, value: %d\n",
                    TreeMapIter_getKey(iter),
                    *(Integer)TreeMapIter_getValue(iter));
        }

        return 0;
    }

