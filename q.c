
#include <stdio.h>
#include <stdlib.h>
    struct list
    {
        int*op;
        int *p;
        int len;
        int size;
        char first;
    }list;
void add(struct list *list1,int k)
{
    int n=list1->len;
    int s=list1->size;
        
        if(n==s)
        {
            list1->size=s*2;
            int*p2=(int*)malloc(s*2*sizeof(int));
            for (int i=0;i<n;i++)
            {
                p2[i]=(list1->p)[i];
            }
            free(list1->op);
            list1->op=p2;
            list1->p=list1->op;
            (list1->len)+=1;
            (list1->p[list1->len-1])=k;
            
        }
        else
        {
            (list1->len)+=1;
            (list1->p)[list1->len-1]=k;
        }
}
//Now I solved the problem by adding an original painter and copying the hall list and freeing the memori each time 
// the diffrence between the two pointers is more than the half of the size reserved in the memorie.
void pop(struct list *l)
{

int d=(l->p)-l->op;
if(d>=l->size/2)
{
    l->size=l->size/2;
    int*p2=(int*)malloc(l->size*sizeof(int));
    for (int i=0;i<l->len;i++)
        {
            p2[i]=(l->p)[i];
        }
    free(l->op);
    l->op=p2;
    l->p=l->op;
}
    l->first=l->p[0];
    l->p+=1;
    l->len-=1;
    return l->first;
}
int peak(struct list *l)
{
    return l->first;
}

int main()
{
    


    struct list list1;
    list1.len=0;
    list1.size=1;
    list1.op=(int*)malloc((list1.size) * sizeof(int));
    list1.p=list1.op;
    for (int i=0;i<10;i++)
    {
        add(&list1,i);
    }
    for (int j=0;j<list1.len;j++)
    {
        
        printf("%d;",list1.p[j]);
    }
    int test[10];
    for (int i=0;i<10;i++)
    {
        test[i]=fpop(&list1);
    }
        for (int j=0;j<10;j++)
    {
        
        printf("%d;",test[j]);
    }

}