#include <stdio.h>
#include <stdlib.h>
    struct list
    {
        char*op;
        char *p;
        int len;
        int size;
        char first;
    }list;
void add(struct list *list1,char k)
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
char fpop(struct list *l)
{

int d=(l->p)-l->op;
if(d>=l->size/2)
{
    l->size=l->size/2;
    char*p2=(char*)malloc(l->size*sizeof(char));
    for (int i=0;i<l->len;i++)
        {
            p2[i]=(l->p)[i];
        }
    free(l->op);
    l->op=p2;
    l->p=p2;
}
    l->first=l->p[0];
    l->p+=1;
    l->len-=1;
    return l->first;
}
char get(struct list *l)
{
    return l->p[0];
}


