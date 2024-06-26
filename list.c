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

List * createList() 
{
  List * newLista = (List *)malloc(sizeof(List));
  newLista->head = NULL;
  newLista->tail = NULL;
  newLista->current = NULL;
  return newLista;
}

void * firstList(List * list)
{
  list->current = list->head;
  if(list->current)
  {
    return list->current->data;
  }
  return NULL;
}
void * nextList(List * list) 
{
  if(list->current != NULL)
  {
    if(list->current->next != NULL)
    {
      list->current = list->current->next;
      return list->current->data;
    }
    
      
  }
  return NULL;
}

void * lastList(List * list) 
{
  list->current = list->tail;
  if(list->current)
  {
    return list->current->data;
  }
  return NULL;
}

void * prevList(List * list) 
{
  if(list->current != NULL)
  {
    if(list->current->prev != NULL)
    {
      list->current = list->current->prev;
      return list->current->data;
    }
  }
  return NULL;
}

void pushFront(List * list, void * data) 
{
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
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