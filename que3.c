#include<stdio.h>
#include<stdlib.h>
//linked list node struture
typedef struct list_item
{
   int data;
   struct list_item *next;
}list_item;
//Non-recursive linked list space release function
void erase_list(list_item *head)
{
   list_item *current=head;
   list_item *next;
   while(current!=NULL)
  {
   next = current->next;
   free(current);
   current=next;
  }
}

