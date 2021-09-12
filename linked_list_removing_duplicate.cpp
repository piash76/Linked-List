
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
    head=new node;
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

void fun()    ///removing duplicate from sorted linked list
{
    struct node *p=new node;
    p=head;
    struct node *q=new node;
    q=head->next;

    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;

        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }

}








int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    creation();
    display();

    cout<<"AFTER"<<endl;
    fun();
    display();
}
