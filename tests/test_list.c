#include <stdio.h>
#include <assert.h>

#include "list.h"


int main() {
    List lst = new_List();
    assert(List_size(lst) == 0);
    assert(List_front(lst) == NULL);
    assert(List_back(lst) == NULL);

    List_pushBack(lst, new_Integer(1));
    List_pushBack(lst, new_Integer(2));
    List_pushBack(lst, new_Integer(3));
    List_pushBack(lst, new_Integer(4));

    assert(List_size(lst) == 4);
    assert(*(Integer)List_front(lst) == 1);
    assert(*(Integer)List_back(lst) == 4);

    List_remove(lst, List_getIter(lst, 1));
    assert(List_size(lst) == 3);
    assert(*(Integer)ListIter_getValue(List_getIter(lst, 2)) == 4);

    printf("[PASSED] List\n");
}
