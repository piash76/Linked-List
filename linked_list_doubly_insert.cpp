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

void insert_at_first(int val)
{
    struct node *t=new node;
    t->prev=NULL;
    t->data=val;
    t->next=head;
    head->prev=t;
    head=t;
}


void insert_at_last(int val)
{
    struct node *t=new node;
    t->prev=last;
    t->data=val;
    t->next=NULL;
    last->next=t;

    last=t;
}

void insert_at_pos(int pos,int val)  ///after pos
{
    struct node *p=new node;
    p=head;
    int c=1;

    while(p)
    {
        if(c==pos)
        {
            struct node *q=p->next;

            struct node *t=new node;
            t->prev=p;
            t->data=val;
            t->next=q;

            p->next=t;
            q->prev=t;
            break;

        }
        c++;
        p=p->next;
    }

}


int main()
{
    cin>>n;

    creation();
    display();
   // int x;cin>>x;
   // insert_at_first(x);
   //insert_at_last(x);
   int pos,x;cin>>pos>>x;
   insert_at_pos(pos,x);
    display();



}

