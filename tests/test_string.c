#include "dymc.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "str.h"

int main() {
    StringBuilder builder = new_StringBuilder();
    StringBuilder_append(builder, "test %d", 1);
    StringBuilder_append(builder, ", %d", 2);
    assert(strcmp("test 1, 2", StringBuilder_getString(builder)) == 0);
    assert(StringBuilder_size(builder) == 9);

    String s = "a,bc,def";
    Vector str_list = String_split(s, ',');
    assert(Vector_size(str_list) == 3);
    assert(strcmp("a", (String)Vector_get(str_list, 0)) == 0);
    assert(strcmp("bc", (String)Vector_get(str_list, 1)) == 0);
    assert(strcmp("def", (String)Vector_get(str_list, 2)) == 0);

    printf("[PASSED] String\n");
    return 0;
}
