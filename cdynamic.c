
#include <stdio.h>
#include <stdlib.h>
    struct list
    {
        char *p;
        int len;
        int size;
    }list;
void append(struct list *list1,char k)
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
            (list1->p[n])=k;
           // (list1->p[n+1])='\0';


        }
        else
        {
            (list1->len)+=1;
            (list1->p)[list1->len-1]=k;  
            //(list1->p)[list1->len]='\0';  


        }
    }
    
    
int main()
{
     struct  list list2;
            list2.len=0;
            list2.size=1;
            list2.p=(char*)malloc(1*sizeof(char));
            for (int i=0;i<10;i++)
            {
                char c;
                scanf("%c",&c);
                append(&list2,c);
            }
            printf("%d",list2.len);
            for (int i=0;i<list2.len;i++)
            {
                
                printf("%c",list2.p[i]);
            }
}