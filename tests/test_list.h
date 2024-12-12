#include <stdio.h>

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

    printf("[PASSED] List")
}
