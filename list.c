#include "list.h"
void add(LIST **head, LIST **tail, void *data)
{
    // TODO implement the function
    
    if(*head==NULL){
        *head = (LIST *)malloc(sizeof(LIST));
        (*head)->data=data;
        (*head)->next=NULL;
        *tail=*head;
    }
    else{
        LIST *temp = (LIST *)malloc(sizeof(LIST));
        temp->data=data;
        temp->next = NULL;
        (*tail)->next=temp;
        (*tail)=(*tail)->next;
    }
}

void clearIteratively(LIST **head, LIST **tail)
{
    if (*head == NULL)
        return;

    LIST *currNode = *head;
    LIST *nextNode = NULL;
    do
    {
        nextNode = currNode->next;

        if (currNode->data != NULL)
            free(currNode->data);

        free(currNode);

        currNode = nextNode;

    } while (currNode != NULL);

    *head = NULL;
    *tail = NULL;
}

void clearRecursively(LIST **currNode, LIST **tail)
{
    // TODO implement the function
}

void delete(LIST **head, LIST **tail, void *data)
{
    // TODO implement the function
    if (*head == NULL)
        return;
    LIST *currNode = *head;
    LIST *prevNode = NULL;
    if(currNode->data==data){
        *head=currNode->next;
        return;
    }
    while(currNode!=NULL){
        
        if(currNode->data==data){
            if(currNode==*tail){
                *tail=prevNode;
            }
            prevNode->next=currNode->next;
            break;
        }
        prevNode=currNode;
        currNode=currNode->next;

    }


}