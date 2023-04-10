#include <stdio.h>
#include <stdlib.h>
typedef struct list
    {
        int *p;
        int len;
        int size;
    }list;

void append(list *list1,int k)
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
    
typedef struct Qlist
    {
        int*op;
        int *p;
        int len;
        int size;
        char first;
    }Q;

void add(Q*list1,int k)
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

int pop(Q*l)
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
//a function that uses BFS algorithm to check if the graph is connected 
int is_connected_BFS(list ** graph,int n,int e)
{
    Q *Quee=(Q*)malloc(sizeof(Q));
    Quee->len=0;
    Quee->size=1;
    Quee->op=(int*)malloc((Quee->size) * sizeof(int));
    Quee->p=Quee->op;
    
    int visited[n];
    for (int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    
int v=0;
int s=0;
for (int i=0;i<n;i++)
    {
    if (visited[i]==1) continue;
    s++;
    add(Quee,i);
    while(Quee->len!=0)
        {
            int x=pop(Quee);
            if (visited[x]==1) continue;
            visited[x]=1;
            for (int i=0;i<graph[x]->len;i++)
            {
                add(Quee,graph[x]->p[i]);
            }
        }
        if (i==0)
        {
            for (int i=0;i<n;i++)
                {
                    if (visited[i]==0) v=1;
                }
        }
    }
if (v==0) return 0;
else return s;

}

//defining a function that uses the stack of the recurcive function calls to impliment a dfs algorithm
void dfs(list**graph,int d,int * visited)
{
    for (int i=0;i<graph[d]->len;i++)
    {
        if (visited[graph[d]->p[i]]==0)
        {
            visited[graph[d]->p[i]]=1;
            dfs(graph,graph[d]->p[i],visited);   
        }
    }
}
int is_connected_DFS(list**graph,int n,int e)
{
int visited[n];
    for (int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    int v=0;
for (int i=0;i<n;i++)
{
    if (visited[i]==1) continue;
    if (i!=0) v=1;
    visited[i]=1;
    dfs(graph,i,visited);
}
return v;
}
//cheking if there is a cycle in the graph using dfs 
int is_cycle(list**graph,int d,int*visited,int p)
{
    for (int i=0;i<graph[d]->len;i++)
    {
        if (visited[graph[d]->p[i]]==1 && graph[d]->p[i]!=p) return 1;
        if (visited[graph[d]->p[i]]==0)
        {
            visited[graph[d]->p[i]]=1;
            is_cycle(graph,graph[d]->p[i],visited,d);   
        }
    }
    return 0;
}
int is_tree(list**graph,int n,int e)
{
    //if (e!=n-1) return 1;
    //if (is_connected_DFS(graph,n,e)==1) return 1;
    int visited[n];
    for (int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    visited[0]=1;
   return is_cycle(graph,0,visited,0);
}
int main(int argc,char*argv[])
{
    if (argc!=3) {printf("we need two numbers as arguments !!");return 0;}
    int  n=atoi(argv[1]);
    char e=atoi(argv[2]);
    list **heads =(list**)malloc(n*sizeof(list*));
    for (int i=0;i<n;i++)
    {
    list* list1=(list*)malloc(sizeof(list));
    list1->len=0;
    list1->size=2;
    list1->p=(int*)malloc((list1->size) * sizeof(int));

    heads[i]=list1;
    
    }
    for(int i=0;i<e;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        append(heads[a-1],b-1);
        append(heads[b-1],a-1);

    }
    for (int i=0 ;i<n;i++)
    {   
            printf("%d:",i+1);
        for (int j=0;j<heads[i]->len;j++)
        {
            printf("%d ",heads[i]->p[j]+1);
        }
        printf("\n");

    }

    if (is_connected_BFS(heads,n,e)==0) printf("The graph is connected!! (BFS)\n");
    else printf("The graph is not connected and it contains %d subgraphs (BFS)\n",is_connected_BFS(heads,n,e));
    if (is_connected_DFS(heads,n,e)==0) printf("The graph is connected!!(DFS)\n");
    else printf("The graph is not connected!!(DFS)\n");
    if (is_tree(heads,n,e)==0) printf("The graph is a tree!!");
    else printf("the graph is not a tree!!");
    return 0;
}