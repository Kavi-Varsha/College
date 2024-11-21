# include <stdio.h>
 # include <stdlib.h>
 # include <math.h>
 struct term {
    int coef, xexp, yexp, zexp;
    struct term *link;
 };
 typedef struct term tm;

 void create(tm *);
 void display(tm *);
 void evaluate(tm *);
 void add( tm *, tm *, tm *);
 void delete( tm *,tm *);

 int main()
 {
    tm p1={.link=&p1},p2={.link=&p2},p3={.link=&p3};
    int ch;
    while(1)
    {
        printf("1. Evaluate\n2. Polynomial addition\n3. Exit\n");
        printf("Choice: "); 
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if (p1.link != &p1) p1.link = &p1;
                    create(&p1);
                    printf("Terms in polynomials are...\n");
                    display(&p1);
                    evaluate(&p1);
                    break;
            
            case 2: if (p1.link != &p1) p1.link = &p1; //to empty p1
                    if (p2.link != &p2) p2.link = &p2;
                    if (p3.link != &p3) p3.link = &p3;

                    create(&p1); create(&p2);
                    printf("Terms in poly1 are...\n");
                    display(&p1);
                    printf("Terms in poly2 are...\n");
                    display(&p2);
                        
                    add(&p1,&p2,&p3);
                    printf("Resultant polynomial...\n");
                    display(&p3);
                    break;

            case 3: return 0;
        }
    }
 }
 
void delete(tm *p, tm *tp)
 {
    tm *prev = p, *next = p->link;
    while(next!=tp)
    {
        prev = next;
        next = next->link;
    }
    prev->link = next->link;
    free(next);
 }

void attach(int s, tm *p, tm *r)
 {
    tm *t = (tm *) malloc(sizeof(tm));
    t->coef=(s!=0)?s:p->coef;
    t->xexp = p->xexp; t->yexp = p->yexp;
    t->zexp = p->zexp;
    //insert front
    t->link =r->link;
    r->link = t;
 }

int compare(tm * p, tm *q)
 {
    if ( (p->xexp == q->xexp) && (p->yexp == q->yexp) &&(p->zexp == q->zexp) )
        return 1;
    return 0;
 }

 void add(tm *p, tm *q, tm *r)
 {
    int val;
    tm *tp=p->link, *tq, *temp=NULL;
    while(tp != p)
    {
        tq = q->link; val=0; //needed for dataset 2
        while (tq != q)
        {
            val = compare(tp,tq);
            if (val)
                break;
            tq = tq->link;
        }

         switch(val)
        {
            case 0: attach(0,tp,r);
                    break;
            case 1: val = tp->coef + tq->coef;
                    attach(val,tp,r);
                    delete(q,tq);
                    break;
        }
        temp = tp;
        tp = tp->link;
        delete(p,temp);
    }
    //Remaining terms in P2 will be added to resultant polynomial
    tq=q->link;
    while (tq != q)
    {
        attach(0,tq,r);
        tq = tq->link;
    }
 }

 void evaluate(tm *p)
 {
    int x,y,z,res=0; tm *t;
    printf("Enter value of x,y and z\n");
    scanf("%d%d%d",&x,&y,&z);
    for(t=p->link; t!=p ; t=t->link)
        res=res+t->coef*pow(x,t->xexp)*pow(y,t->yexp)*pow(z,t->zexp);
    printf("Evaluation of polynomial is %d\n",res);
 }


 void display(tm *p)
 {
    tm *t;
    if (p->link == p)
    {
        printf("SCLL is empty\n");
        return;
    }
    for(t=p->link; t!=p ; t=t->link)
        printf("(%dx^%dy^%dz^%d) +",t->coef,t->xexp,t->yexp,t->zexp);
    printf("\b \n");
 }

void create(tm *p)
 {
    int n,i;
    tm *t;
    printf("Enter number of terms\n"); scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        t = (tm *) malloc(sizeof(tm));
        printf("Enter coef, xexp, yexp and zexp of the term\n");
        scanf("%d%d%d%d",&(t->coef),&(t->xexp),&(t->yexp),&(t->zexp));
        t->link = p->link;
        p->link = t;
    }
 }