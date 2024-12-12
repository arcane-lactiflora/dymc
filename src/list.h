#ifndef DYMC_LIST_H_
#define DYMC_LIST_H_

#include "basic_types.h"

typedef struct list *List;
typedef struct list_node *ListIter;

List new_List();

int64_t  List_size(List self);
ListIter List_begin(List self);
ListIter List_end(List self);

ListIter List_getIter(List self, int n);
Object   List_get(List self, int n);
Object   List_front(List self);
Object   List_back(List self);

void List_insert(List self, ListIter iter, Object obj);
void List_remove(List self, ListIter iter);
void List_pushBack(List self, Object obj);
void List_pushFront(List self, Object obj);

void List_popBack(List self);
void List_popFront(List self);

ListIter ListIter_next(ListIter self);
ListIter ListIter_prev(ListIter self);
Object   ListIter_getValue(ListIter self);


#endif


