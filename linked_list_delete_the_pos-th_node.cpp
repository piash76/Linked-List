
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


void delete_the_pos(int pos)
{
    int cnt=1;
    struct node *p;
    p=new node;
    p=head;


    while(p)
    {
        if(cnt==pos-1)
        {
            struct node *t;
            t=p->next;
            p->next=t->next;

            delete t;
            break;

        }
        cnt++;
        p=p->next;
    }


}




int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    creation();
    display();

    cout<<"AFTER "<<endl;
    int p=4;
    delete_the_pos(p);
    display();



}
