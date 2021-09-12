
#include<bits/stdc++.h>
using namespace std;


int n;

struct node    ///self referential structure
{
    int data;
    int flag;
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
    head->flag=0;
    head->next=NULL;

    last=new node;
    last=head;  ///saving head in last


    for(i=1;i<n;i++)
    {
        cin>>val;
        t=new node;

       t->data=val;
       t->flag=0;
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

bool detect_loop()
{
    struct node *p=new node;
    p=head;

    while(p)
    {
        if(p->flag==1) return true;
        p->flag=1;
        p=p->next;
    }

    return false;

}




int main()
{
    cin>>n;

    creation();
    display();

    head->next->next->next->next = head;  ///for n=4;

    if(detect_loop()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;



}

