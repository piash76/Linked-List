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

void delete_at_first()
{
    struct node *p,*q;
    p=head;

    q=head->next;

    delete p;

    q->prev=NULL;

    head=q;



}

void delete_last()
{
    struct node *p=new node;
    p=head;

    while(p->next)
    {
        p=p->next;
    }

    struct node *q=new node;
    q=p->prev;
    q->next=NULL;
    last=q;

    delete p;

}

void delete_at_pos(int pos)
{
    struct node *p=new node;
    p=head;

    int c=1;
    while(p)
    {
        if(c==pos)
        {
            struct node *nxt,*prv;
            nxt=new node;
            nxt=p->next;

            prv=new node;
            prv=p->prev;

            prv->next=nxt;
            nxt->prev=prv;

            delete p;
            break;
        }
        p=p->next;
        c++;
    }
}








int main()
{
    cin>>n;

    creation();
    display();

    cout<<endl;

    //delete_at_first();
    //delete_last();
    int pos;cin>>pos;
    delete_at_pos(pos);
    display();



}
