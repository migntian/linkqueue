#pragma once
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define HEADER printf("\n=============%s============\n",__FUNCTION__)
typedef char linkqueuetype;
typedef struct linkqueuenode{
    linkqueuetype data;
    struct linkqueuenode *next;

}linkqueuenode;

typedef struct linkqueue{
    linkqueuenode *head;
    linkqueuenode *tail;
}linkqueue;
void linkqueue_init(linkqueue *link);
void linkqueue_print(linkqueue *link);
void linkqueue_destory(linkqueue *link);
void linkqueue_push(linkqueue *link,linkqueuetype value);
void linkqueue_pop(linkqueue*link);
int linkqueue_gettop(linkqueue *link,linkqueuetype *value);
