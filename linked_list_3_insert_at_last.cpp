///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;

int a[50];
int n;

struct node    ///self referential structure
{
    int data;
    struct node *next;  ///pointing to next node
};

struct node *head=NULL,*last;

void creation()
{
    int i;
    struct node *t;

   head=new node;
    head->data=a[0];
    head->next=NULL;

    last=head;  ///saving head in last


    for(i=1;i<n;i++)
    {
       t=new node;
        t->data=a[i];
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

void insert_at_last(int val)   ///0(1)
{
    struct node *t=new node;
    t->data=val;
    t->next=NULL;
    last->next=t;
    last=t;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    creation();
    display();


     ///insert at last
     int val=n+1;
    cout<<"AFTER INSERTING AT last "<<endl;
    insert_at_last(val);
    display();
}

