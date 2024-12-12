#include "list.h"
#include "gc_prelude.h"

struct list {
    int64_t size;
    ListIter prebegin;
    ListIter end;
};

struct list_node {
    ListIter prev;
    ListIter next;
    Object value;
};

static ListIter new_ListIter() {
    ListIter self = malloc(sizeof(struct list_node));
    self->prev = NULL;
    self->next = NULL;
    self->value = NULL;
    return self;
}

List new_List() {
    List self = malloc(sizeof(struct list));
    self->size = 0;
    self->prebegin = new_ListIter();
    self->end = new_ListIter();
    self->prebegin->next = self->end;
    self->end->prev = self->prebegin;
    return self;
}

int64_t  List_size(List self) {
    return self->size;
}

ListIter List_begin(List self) {
    return self->prebegin->next;
}

ListIter List_end(List self) {
    return self->end;
}

ListIter List_getIter(List self, int n) {
    ListIter ret = self->prebegin->next;
    for (int i = 0; i < n; i++) {
        if (ret == NULL) return ret;
        ret = ret->next;
    }
    return ret;
}

Object   List_get(List self, int n) {
    return List_getIter(self, n)->value;
}

Object   List_front(List self) {
    return List_begin(self)->value;
}

Object   List_back(List self) {
    return List_end(self)->prev->value;
}

void List_insert(List self, ListIter iter, Object obj) {
    ListIter prev = iter->prev;
    ListIter next = iter;
    ListIter new = new_ListIter();
    new->prev = prev;
    new->next = next;
    next->prev = new;
    prev->next = new;
    new->value = obj;
    self->size++;
}

void List_remove(List self, ListIter iter) {
    ListIter prev = iter->prev;
    ListIter next = iter->next;
    prev->next = next;
    next->prev = prev;
    self->size--;
}

void List_pushBack(List self, Object obj) {
    List_insert(self, List_end(self), obj);
}

void List_pushFront(List self, Object obj) {
    List_insert(self, List_begin(self), obj);
}

void List_popBack(List self) {
    if (self->end->prev == self->prebegin) return;
    List_remove(self, List_end(self)->prev);        
}

void List_popFront(List self) {
    if (self->prebegin->next = self->end) return;
    List_remove(self, self->prebegin->next);
}

ListIter ListIter_next(ListIter self) {
    return self->next;
}

ListIter ListIter_prev(ListIter self) {
    return self->prev;
}

Object   ListIter_getValue(ListIter self) {
    return self->value;
}
