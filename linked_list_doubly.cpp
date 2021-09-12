#include<bits/stdc++.h>
using namespace std;



int n;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head,*last;


void creation()
{
    int x;cin>>x;

    head=new node;
    head->prev=NULL;
    head->data=x;
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {

        int x1;cin>>x1;

        struct node *t=new node;
        t->prev=last;
        t->data=x1;
        t->next=NULL;

        last->next=t;
        last=t;

    }

}

void display()
{

    struct node *p=new node;
    p=head;

    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }

}


int main()
{
    cin>>n;

    creation();
    display();



}
