#include <stdio.h>
#include <stdlib.h>
typedef  struct d_node
    {
        int data;
        struct d_node* next;
        struct d_node* previous;

    }node;

node*last;
node*start;
node*last2;
node*start2;
void append(node**last,int k)
{
    node*p=(node*)malloc(sizeof(node));
    p->data=k;
    p->next=NULL;
    p->previous=*last;
    (*last)->next=p;
    *last=p;

}

int pop(node**last)
{
    int a =(*last)->data;
    node* p=(*last)->previous;
    (p)->next=NULL;
    free(*last);
    *last=p;

    return a;
}

void delete(node*node1,int x)
{
    

while(1)
{
        node*n=node1->next;
    if (node1->data==x)
    {
        node*p=node1->previous;
        node*c=p->next;
        if(p!=NULL)p->next=n;else break;
        if (n!=NULL)n->previous=p;
        free(node1);
    }
    if(n !=NULL){
    node1=n;}
    else break;
}

}

node* some(node*head1,node*head2)
{
    short c=0;
    node*headsom=(node*)malloc(sizeof(node));
    headsom->previous=NULL;
    int s =head1->data+head2->data ;
    head1=head1->next;
    head2=head2->next;
    c=(s-s%10)/10;
    headsom->data=s-c*10;
    node*som=(node*)malloc(sizeof(node));
    headsom->next=som;

    while (head1!=NULL && head2!=NULL)
    {
    s =head1->data+head2->data + c;
     c=(s-s%10)/10;
    som->data=s-c*10;
    node*p=(node*)malloc(sizeof(node));
    som->next=p;
    head1=head1->next;
    head2=head2->next;   
    som->next=NULL;
    }
    if(head1==NULL) head1=head2;


    return headsom;
}



int main()
{
node head;
node node2;
head.data=1;
node2.data=3;
head.next=&node2;
node2.next=NULL;
node2.previous=&head;
head.previous=NULL;
start=&head;
last=&node2;

append(&last,555);
append(&last,66);
append(&last,14);
append(&last,66);
append(&last,155);
//pop(&last);
//delete(start,66);
node *node1 =some(start,start);
while(node1!=NULL)
{
    printf("%d\n",node1->data);
    
    node1=node1->next;
    
}


}


