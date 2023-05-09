#include <stdio.h>
#include <stdlib.h>
struct node
{ 
    int data;          // 4
    struct node *next; // 8  s
} *head = NULL, *last = NULL;
void addNode()
{
    int num;
    struct node *tmp;
    printf("\nEnter number");
    scanf("%d", &num); // 10
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
        last = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

void display()
{
    struct node *s;
    s = head;
    while (s != NULL)
    {
        printf(" %d ", s->data); // 10 20 30 40 50
        s = s->next;
    }
}

void addNodeBeg()
{
    int num;
    struct node *tmp;
    printf("\nEnter number");
    scanf("%d", &num); // 10
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
        last = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = head;
        head = tmp;
    }
}

void search(int num)
{
    int isFound = 0; // not found
    struct node *s = head;

    while (s != NULL)
    {
        if (s->data == num)
        {
            isFound = 1;
            break;
        }
        s = s->next;
    }
    if (isFound == 0)
    {
        printf("\n%d not found...", num);
    }
    else
    {
        printf("\n%d Found..", num);
    }
}
void insertAfter(){
    int num,val;
    struct node *p=head,*q,*temp;
    printf("\nEnter search data:");
    scanf("%d",&num);
    printf("\nEnter new data");
    scanf("%d",&val);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    while(p != NULL){
        if(p->data == num){
            break;
        }
        p=p->next;
    }
    q=p->next;
    p->next=temp;
    temp->next=q;
}
void insertBefore(){
    int num,val;
    struct node *p=head,*q,*temp;
    if(head==NULL){
        printf("Empty LL");
    }else{
        printf("\nEnter search data:");
        scanf("%d",&num);
        printf("\nEnter new data");
        scanf("%d",&val);
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data=val;
        while(p != NULL){
            if(p->data == num){
                break;
            }
            q=p;
            p=p->next;
        }
        q->next=temp;
        temp->next=p;
        }
}
int main()
{
    int choice;
    int num;

    while (1)
    {
        printf("\n0 For Exit\n1 For Add\n2 For Display\n3 For insertBeg\n4 For search\n5 For insert after\n6 For insert before\nEnter choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNode();
            break;
        case 2:
            display();
            break;
        case 3:
            addNodeBeg();
            break;
        case 4:
            printf("\nEnter num for search");
            scanf("%d", &num);
            search(num);
            break;
        case 5:
            insertAfter();
            break;
        case 6:
            insertBefore();
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}