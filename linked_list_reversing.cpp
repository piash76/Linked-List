
///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;


int n;

struct node    ///self referential structure
{
    int data;
    struct node *next;  ///pointing to next node
};

struct node *head=NULL,*last;

void creation()
{
    int i,val;
    struct node *t;

    head=new node;

    cin>>val;
    head->data=val;
    head->next=NULL;

    last=new node;
    last=head;  ///saving head in last


    for(i=1;i<n;i++)
    {
        cin>>val;
        t=new node;

       t->data=val;
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


void reversing()
{
    struct node *p,*q,*r;
    p=head;
    q=p->next;
    p->next=NULL;

    while(q!=NULL)
    {
        r=q->next;
        q->next=p;

        p=q;
        q=r;
    }
    head=p;
}


Node* reversing(Node* head)
{

    Node* first=head;
    Node* second=first->next;
    first->next=NULL;

    Node* third;

    while(second!=NULL)
    {
        third=second->next;
        second->next=first;

        first=second;
        second=third;
    }

    return first;
}

int main()
{
    cin>>n;

    creation();
    display();

    cout<<"AFTER "<<endl;
    reversing();
    display();



}
