
#include <stdio.h>
#include <stdlib.h>
    struct list
    {
        int *p;
        int len;
        int size;
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
            free(list1->p);
            list1->p=p2;
            (list1->len)+=1;
            (list1->p[list1->len-1])=k;
            
        }
        else
        {
            (list1->len)+=1;
            (list1->p)[list1->len-1]=k;
        }
}
//this method is working but I think that it will cost a problem in the memorie so I need to try something else;
int fpop(struct list *l)
{
    int a=l->p[0];
    l->p+=1;

    l->len-=1;
    return a;
}

int main()
{
    


    struct list list1;
    list1.len=0;
    list1.size=1;
    list1.p=(int*)malloc((list1.size) * sizeof(int));
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