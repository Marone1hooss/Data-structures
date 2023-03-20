
#include <stdio.h>
#include <stdlib.h>
    struct list
    {
        int *p;
        int len;
        int size;
    }list;
void append(struct list *list1,int k)
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
            (list1->p[n])=k;
        }
        else
        {
            (list1->len)+=1;
            (list1->p)[list1->len-1]=k;           
        }
    }
    


int main()
{
    //defining a dynamic array of int


    struct list list1;
    list1.len=0;
    list1.size=1;
    list1.p=(int*)malloc((list1.size) * sizeof(int));



for (int i=0;i<100;i++)
{
    append(&list1,i);
}
for (int i=0;i<list1.len;i++)
{
    printf("%d;",list1.p[i]);
}
    return 0;
}



