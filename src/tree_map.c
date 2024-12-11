#include "tree_map.h"
#include "rb_tree.h"

#include <string.h>

#include "gc_prelude.h"

TreeMap new_TreeMap(CompareFunc cmp_fn) {
    TreeMap tree = malloc(sizeof(rb_tree_t));
    *tree = (rb_tree_t){NULL, cmp_fn, NULL};
    return tree;
}

void TreeMap_set(TreeMap self, Object key, Object value) {
    TreeMapIter iter = rb_tree_find(self, &key);
    if (iter == NULL) {
        iter = malloc(sizeof(*iter));
        iter->key = key;
        iter->value = value;
        rb_tree_insert(self, iter);
    } else {
        iter->value = value;
    }
}

Object TreeMap_get(TreeMap self, Object key) {
    TreeMapIter iter = rb_tree_find(self, key);
    if (iter == NULL) return NULL;
    return iter->value;
}

void TreeMap_erase(TreeMap self, Object key) {
    rb_tree_remove(self, key);
}

TreeMapIter TreeMap_begin(TreeMap self) {
    return rb_tree_min(self);
}

TreeMapIter TreeMap_next(TreeMap self, TreeMapIter iter) {
    return rb_tree_next(self, iter);
}

Object TreeMapIter_getKey(TreeMapIter iter) {
    return iter->key;
}

Object TreeMapIter_getValue(TreeMapIter iter) {
    return iter->value;
}
