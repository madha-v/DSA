#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next
} q;

q* enq(q*r)
{
    q*p=(q*)malloc(sizeof(q));
    if(p!=NULL)
    {
        int x;
        printf("enter the elemnt to add in the queue ::->");
        scanf("%d",&x);
        p->data=x;
        p->next=NULL;
        
        if(r==NULL)
        {
            return p;
        }
        else
        {
            r->next=p;
            return p;
        }
    }
    return r;
    
}

q* deq(q*f)
{
    if(f==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        q*p=f;
        printf("%d",f->data);
        f=f->next;
        free(p);
    }
    return f;
}

void printasstack(q*f)
{
    if(f==NULL)
    {
        printf("stack is empty (queue)");
    }
    
    printasstack(f->next);
    
    printf("%d",f->data);

}
void display(q*f)
{
    if(f==NULL)
    {
        printf("queue is empty");
        
    }
    else
    {
        while(f!=NULL)
        {
            printf("%d->",f->data);
            f=f->next;
        }
    }
}
int main()
{
    q *f=NULL;
    q *r=NULL;
    int ch;
    do{
        printf("1--enqueue , 2-- dequeue, 3--display  , 4--printasstack::->");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            r=enq(r);
            if(f==NULL)
            {
                f=r;
            }
            break;
            
            case 2:
            f=deq(f);
            if(f==NULL)
            {
                r==NULL;
            }
            break;
            
            case 3:
            display(f);
            break;
            
            case 4:
            printasstack(f);
            break;
            
            default:
            printf("invalid choice made by the user ");
            break;
        }
    } while(ch<=4);
    return 0;
}
    
