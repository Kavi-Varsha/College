# include <stdio.h>
 # include <stdlib.h>
 struct node {
    struct node *llink;
    int info;
    struct node *rlink;
 };
 typedef struct node nd;

 nd * BST_creation (nd * root, int key)
 {
    nd *cur=root, *prev=0;
    nd *t= (nd *) malloc(sizeof(nd));
    t->info=key; t->llink=t->rlink=0;

    if (!cur) 
        return t;
    while(cur)
    {
        if (t->info == cur->info)
        {
        printf("Redundancy\n");
        free(t);
        return root;
        }

        prev=cur;
        if (t->info < cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if (t->info < prev->info)
        prev->llink=t;
    else
        prev->rlink=t;
    return root;
 }

void preorder( nd *r)
 {
    if (r)
    {
        printf("%d ",r->info);
        preorder(r->llink);
        preorder(r->rlink);
    }
 }

 void postorder( nd *r)
 {
    if (r)
    {
        postorder(r->llink);
        postorder(r->rlink);
        printf("%d ",r->info);
    }
 }

void inorder( nd *r)
{
    if (r)
    {
        inorder(r->llink);
        printf("%d ",r->info);
        inorder(r->rlink);
    }
 }

 void it_inorder( nd * r)
 {
    nd *c;
    nd *st[20]; // stack of pointers of type nd
    int top=-1;
    
    if ( !r )
    {
        printf("Tree is empty\n");
        return;
    }

    c=r;
    for(;;)
    {
        while( c!= 0)
        {
            st[++top] = c;//storing nodes info on stack
            c = c->llink;
        }
        if ( top !=-1)
        {
            c = st[top--];
            printf("%d ",c->info);
            c=c->rlink;
        }
        else
            return;
    }
 }

void levelorder( nd * root)
{
    int f=0,r=-1;
    nd *c, *q[20]={0};
    if ( !root )
    {
            printf("Binary tree is empty\n");
    return;
    }

    q[++r] = root;
    for(;;) 
    {
        c = q[f++];
        if ( c )
        {
            printf("%d ",c->info);
            if ( c->llink )
            q[++r] = c->llink;
            if ( c->rlink )
            q[++r] = c->rlink;
        }
        else
            break;
    }
}

 int main()
 {
    nd *root=0;
    int ch,i,key;
    FILE *fp;
    fp=fopen("data1","r");
    for(;;) 
    {
        printf("1. Insert\n2. Preorder T\n");
        printf("3. Inorder T\n 4. Postorder T\n");
        printf("5. Iterative Order T\n 6. Level order T\n");
        printf("7. Searching a Value in BST\n8. Exit \n");
        printf("Enter choice ");
        scanf("%d",&ch);
        switch(ch) {
        case 1: fscanf(fp,"%d",&ch);
            for(i=0;i<ch;i++)
            {
            fscanf(fp,"%d",&key);
            root=BST_creation(root,key);
            }
            break;
        case 2:preorder(root);
            break;
        case 3:inorder(root);
            break;
        case 4:postorder(root);
            break;
        case 5:it_inorder(root);
            break;
        case 6:levelorder(root);
            break;
        case 7:
            break;
        
        default: return 0;
        } }}