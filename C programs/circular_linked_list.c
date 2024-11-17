 # include <stdio.h>
 # include <stdlib.h>
 struct node
 {
    int data;
    struct node *link; // recursive definition
 };
 typedef struct node nd;


void insert_front(nd *h) //h receives address of “header”
 {
    nd *t = malloc(sizeof(nd));
    scanf("%d",&(t->data));
    if (h->link==h)//CSLL is empty
        t->link=h;
    else
        t->link=h->link;
    h->link=t;
 }


 void display(nd *h)
 {
    nd *t;
    if (h->link == h)
    { 
        printf("CSLL is empty\n"); 
        return; 
    }
    for(t=h->link; t!=h; t=t->link)
    printf("%d ",t->data);
 }

 int main()
 {
    nd header = {.link = &header};
    insert_front(&header);
    insert_front(&header);
    display(&header);
    return 0;
 }
 