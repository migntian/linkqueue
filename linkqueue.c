#include"linkqueue.h"
void linkqueue_init(linkqueue *link)
{
    if(link == NULL)
    {
        return;
    }
    link->head = link->tail = (linkqueuenode *)malloc(sizeof(linkqueuenode));
    if(link->head == NULL)
    {
        return;//空间申请失败
    }
    link->head->next = NULL;
}
void linkqueue_print(linkqueue *link)
{
    if(link == NULL)
    {
        return;
    }
    if(link->head->next == NULL)
    {
        return;//空链表
    }
    linkqueuenode *cur = link->head->next;
    while(cur != NULL)
    {
        printf("[%c] ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}
void linkqueue_push(linkqueue *link,linkqueuetype value)
{
    if(link == NULL)
    {
        return;
    }
    linkqueuenode *newnode = (linkqueuenode *)malloc(sizeof(linkqueuenode));
    newnode->data = value;
    newnode->next = NULL;
    linkqueuenode *cur = link->tail;
    cur->next = newnode;
    link->tail = newnode;

    
}
void linkqueue_pop(linkqueue *link)
{
    if(link == NULL)
    {
        return;
    }
    if(link->head->next == NULL)
    {
        return;
    }
    linkqueuenode *cur = link->head;
    //linkqueuenode *todelet = link->head->next;
    //cur->next = todelet->next;
    link->head->next = cur-> next->next;
    free(cur);
    cur = NULL;
}
int linkqueue_gettop(linkqueue *link,linkqueuetype* value)
{
    if(link == NULL||value == NULL)
    {
        return -1;
    }
    if(link->head->next == NULL)
    {
        return 0;
    }
    linkqueuenode *cur = (link->head->next);
    *value = cur->data;
    return 1;
}







/////////////////////////////////////////
//测试
/////////////////////////////////////////

void testpush()
{
    HEADER;
    linkqueue link;
    linkqueue_init(&link);
    linkqueue_push(&link,'a');
    linkqueue_push(&link,'b');
    linkqueue_push(&link,'c');
    linkqueue_push(&link,'d');
    linkqueue_print(&link);
}
void testpop()
{
    HEADER;
    linkqueue link;
    linkqueue_init(&link);
    linkqueue_push(&link,'a');
    linkqueue_push(&link,'b');
    linkqueue_push(&link,'c');
    linkqueue_push(&link,'d');
    linkqueue_print(&link);
    linkqueue_pop(&link);
    linkqueue_print(&link);

}
void testgettop()
{
    HEADER;
    linkqueue link;
    linkqueue_init(&link);
    linkqueue_push(&link,'a');
    linkqueue_push(&link,'b');
    linkqueue_push(&link,'c');
    linkqueue_push(&link,'d');
    linkqueue_print(&link);
    linkqueuetype value;
    int ret = linkqueue_gettop(&link,&value);
    printf("expected is 1,actul is %d\n",ret);
    printf("expected is a,actul is %c\n",value);

}

int main()
{
    testpush();
    testpop();
    testgettop();
    return 0;
}








