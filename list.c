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

    // no da puntaje
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    // no da puntaje
    list->current = list->tail;
    return popCurrent(list);
}

void* popCurrent(List* list) {
    //porfa funciona 
    Node* current = list -> current;

    // check si current es head
    if (current -> prev == NULL)
    {
        list -> head = current -> next;
    }
    else
    {
        current -> prev -> next = current -> next;
    }

    // check si current es tail
    if (current -> next == NULL)
    {
        list -> tail = current -> prev;
    }
    else
    {
        current -> next -> prev = current -> prev;
    }

   

    // free current
    free(current);
    list->current = NULL;

    return data;
}



void cleanList(List * list) {
    // no da puntaje
    while (list->head != NULL) {
        popFront(list);
    }
}