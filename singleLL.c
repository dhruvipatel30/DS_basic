#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL, *last=NULL;

int main(){
    struct node *tmp,*p;
    int num,i;
    for(i=1;i<=5;i++){
        printf("\nEnter number: ");
        scanf("%d",&num);
        if(head==NULL){
            head=(struct node*)malloc(sizeof(struct node));
            head->data=num;
            head->next=NULL;
            last = head;
        }else{
           tmp=(struct node*)malloc(sizeof(struct node));
           tmp->data=num;
           tmp->next=NULL;
           last->next=tmp;
           last = tmp; 
        }
    }
    printf("\nSingle linked List\n");
    p=head;
    while(p!=NULL){
        printf("%d -> ",p->data);
        p=p->next;
    }
    return 0;
}