#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr = ptr->next;
    }
}
struct node *insertatfirst(struct node *head , int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct node *insertatindex(struct node *head , int data , int index)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}