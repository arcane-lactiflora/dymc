#ifndef DYMC_MAP_H_
#define DYMC_MAP_H_

#include "basic_types.h"

typedef struct rb_tree *TreeMap;
typedef struct rb_node *TreeMapIter;
typedef int (*CompareFunc)(Object a, Object b);

TreeMap new_TreeMap(CompareFunc compare);
void TreeMap_set(TreeMap self, Object key, Object value);
Object TreeMap_get(TreeMap self, Object key);
void TreeMap_erase(TreeMap self, Object key);

TreeMapIter TreeMap_begin(TreeMap self);
TreeMapIter TreeMap_next(TreeMap self, TreeMapIter iter);

Object TreeMapIter_getKey(TreeMapIter self);
Object TreeMapIter_getValue(TreeMapIter self);

#endif
