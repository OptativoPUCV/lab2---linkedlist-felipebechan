#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    //
    List *ListaNueva= malloc(sizeof(List));
    ListaNueva -> head=NULL;
    ListaNueva -> tail=NULL;
    ListaNueva -> current=NULL;
    return ListaNueva;
}

void * firstList(List * list) {
    //
    if(!list-> head)
    {
        list -> current = list -> head;
        return NULL;
    }
    else
    { 
        return (list -> head -> data);
    }
}

void * nextList(List * list) {
    //
    if(list -> current==NULL || list -> current -> next == NULL)
    {
        return NULL;
    }

    list -> current = list -> current -> next;

    return list -> current -> data;
}

void * lastList(List * list) {
    //

    if( list -> tail)
    {
        list -> current = list -> tail;
    }

    return list -> current -> data;
}

void * prevList(List * list) {
    //
    if (list -> current == NULL)
    {
        return NULL;
    }
    if (list -> current -> prev == NULL)
    {
        return NULL;
    }

    list -> current = list -> current -> prev;

    return list -> current -> data;
}

void pushFront(List * list, void * data) {
    // 
    Node* nuevoNodo = createNode(data);
    nuevoNodo -> next = list -> head;
    if (list -> head == NULL)
    {
        list -> head= nuevoNodo;
        list -> tail= nuevoNodo;
    }
    list -> head -> prev = nuevoNodo -> next;
    list -> head= nuevoNodo;
    }

void pushBack(List * list, void * data) {

}

void pushCurrent(List * list, void * data) {

    Node * nuevoNodo = createNode(data);

    nuevoNodo -> prev = list -> current;

    if(list -> current == NULL)
    {
        return;
    }

    //check checkear si estmaos en la ultima
    if(list -> current == list -> tail)
    {
    //se corre 
    list -> tail = nuevoNodo;
    list -> current -> next = nuevoNodo;
    } 
    if(list -> current != list -> tail)
    {
    nuevoNodo -> next = list -> current -> next;
    list -> current -> next = nuevoNodo;
    }   
}

void * popFront(List * list) {

}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}