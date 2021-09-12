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
    head->next=head;

    last=new node;
    last=head;  ///saving head in last

    for(i=1;i<n;i++)
    {
        cin>>val;
        t=new node;

       t->data=val;
        t->next=last->next;

        last->next=t;

        last=t;


    }


}


void display()
{

    struct node *p=new node;
    p=head;


    /*do
    {
        printf("%d\n",p->data);
        p=p->next;
    }while(p!=head);*/
    while(1)
    {
         printf("%d\n",p->data);
         if(p->next==head) break;
        p=p->next;
    }


}

void delete_first()
{
    struct node *p=new node;
    p=head;

    struct node *q=new node;
    q=head;

    while(p->next!=head)
    {
        p=p->next;
    }

    head=q->next;
    delete q;

    p->next=head;

}

void delete_the_pos(int pos)
{
    int c=1;
    struct node *p=new node;
    p=head;

    while(1)
    {
        if(c==pos-1)
        {
            struct node *q=new node;
            q=p->next;
            p->next=q->next;
            delete q;

            break;
        }
        c++;
        p=p->next;
    }

}


void delete_last()
{

    struct node *p=new node;
    p=head;


    while(p->next->next!=head)
    {
        p=p->next;
    }

    struct node *q=new node;
    q=p->next;
    p->next=q->next;
    delete q;


}










int main()
{
    cin>>n;

    creation();
    display();
    cout<<"After "<<endl;
   // delete_first();
   //int pos;cin>>pos;
   //delete_the_pos(pos);
   delete_last();
    display();



}

