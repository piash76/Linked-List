#include<bits/stdc++.h>
using namespace std;


int n,a[50];

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL,*last;


void creation()
{
    head= new node;
    head->data=a[0];
    head->next=NULL;

    last=head;

    for(int i=1;i<n;i++)
    {
        struct node *t;
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

void delete_first()
{
    struct node *p;
    p=new node;
    p=head;
    head=head->next;

    delete p;
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    creation();
    display();

    cout<<"AFTER "<<endl;
    delete_first();
    display();





}
