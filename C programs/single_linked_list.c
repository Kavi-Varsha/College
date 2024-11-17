#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * link;
};
typedef struct node nd;

 nd* insert_front( nd * f)
 {
    nd *t;
    printf("Enter the element : ");
    t = (nd *) malloc(sizeof(nd));
    scanf("%d", &(t->data));
    t->link=0;
    if(f != NULL)
    {
        t->link = f;
    }
    return t;
}

void display( nd * f)
{
    if(f == NULL)
    {
    printf("LL is empty\n");
    return;
    }

    printf("Contents of SLL are\n");
    for( ; f != NULL ;f = f->link ){
        printf("%d\n", f->data);
    }
 }

 nd* insert_end(nd * f)
 {
    nd* last;
    nd* t = (nd *) malloc(sizeof(nd));
    scanf("%d", &(t->data)); t->link = NULL;
    if (f == NULL)
        return t;
    for(last=f; last->link != NULL; last=last->link);
    last->link = t;
    return f;
    //not at all modified
 }

nd* insert_at_pos( nd * f )
 {
    int pos,cnt=0;
    nd *t,*prev,*next;
    printf("Enter the pos value\n");
    scanf("%d",&pos);

    // to count no of nodes in LL
    for(t=f; t!=0; t=t->link, cnt++);
    
    if ( pos < 1 || pos > cnt+1)
    {
        printf("Insertion not possible\n");
        return f;
    }

    //front insertion; pos = 1
    if ( pos == 1)
        return(insert_front(f));

    //rear insertion
    if ( pos > cnt)
        return(insert_end(f));

    pos--;
    for( prev=0,next=f; pos>0; pos--,prev=next,next=next->link);

    t=malloc(sizeof(nd));
    printf("Enter value for data\n");
    scanf("%d",&(t->data));
    t->link=NULL;

    prev->link = t;
    t->link = next;
    return f;
 }

nd* delete_front( nd * f )
 {
    nd * t;
    if(f == NULL)
    {
        printf("LL is empty\n");
        return f;
    }
    printf("Element deleted is %d\n", f->data);
    t=f;
    f=f->link;
    free(t);
    return f;
 }

nd* delete_end( nd * f )
 {
    nd *prev, *last;
    if ( f == NULL) // situation 1
    {
        printf("LL is empty\n");
        return f; // return 0;
    }

    if ( f->link == NULL) // situation 2
    {
        printf("Information deleted is %d\n", f->data);
        free(f);
        return 0;
    }

    for(prev=0, last=f; last->link != 0; prev=last,last=last->link);
    printf("Element deleted is %d\n", last->data);
    free(last);
    prev->link = 0;
    return f;
 }

nd* delete_at_pos(nd * f)
 {
    nd *t, *n, *p;
    int cnt,pos;
    if ( f == NULL)
    { 
        printf("LL is empty\n"); 
        return f; 
    }
    // counting no of ondes in LL
    for(cnt=0,t=f; t!=0; t=t->link, cnt++);

    printf("Enter pos value\n");
    scanf("%d",&pos);
    if (pos > cnt || pos < 1)
    { 
        printf("Wrong pos value\n"); 
        return f; 
    }

    pos--;
    for(p=0,n=f;pos>0; pos--, p=n, n=n->link);

    if (p == 0) // first node deletion
        return (delete_front(f));

    if ( n->link == 0) //if n is pointing to the last node
        return (delete_end(f));

    printf("Element to be deleted is %d\n",n->data);
    p->link = n->link; 
    free(n);
    return f;
 }
 

int main(){
    nd *first=NULL;
    int n,ch;
    printf("1. insert front  2. insert rear  3. insert pos  4. display  5. delete_front  6. delete_rear 8.delete_at_pos 7.exit\n");
    while(1){
        
        printf("Choice "); 
        scanf("%d",&ch);
            switch(ch){
                case 1: first = insert_front(first); 
                        break;
                case 2: first = insert_end(first); 
                        break;
                case 3: first = insert_at_pos(first);
                        break;
                case 5: first = delete_front(first);
                        break;
                case 6: first=delete_end(first);
                        break;
                case 4: display(first); 
                        break;
                case 8: first=delete_at_pos(first);
                        break;
                case 7: return 0;
    }
    }
}