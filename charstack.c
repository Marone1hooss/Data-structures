#include <stdio.h>
#include <stdlib.h>
    struct list
    {
        char *p;
        char* len;
        int size;
        char last;
    }list;
void push(struct list *list1,char k)
{
    int n=list1->len;
    int s=list1->size;
        if(n==s)
        {
            list1->size=s*2;
            char*p2=(char*)malloc(s*2*sizeof(char));
            for (int i=0;i<n;i++)
            {
                p2[i]=(list1->p)[i];
            }
            free(list1->p);
            list1->p=p2;
            (list1->len)+=1;
            (list1->p[list1->len-1])=k;
            (list1->last)=k;
            
        }
        else
        {
            (list1->len)+=1;
            (list1->p)[list1->len-1]=k;

        }
    }
void pop(struct list *l)
{
    l->len=l->len-1;
    l->last=l->p[l->len-1];


}

