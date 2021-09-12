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

    do
    {
        printf("%d\n",p->data);
        p=p->next;
    }while(p!=head);
   /* while(1)
    {
         printf("%d\n",p->data);
         if(p->next==head) break;
        p=p->next;
    }*/
}


void insert_at_first(int val)   ///same as last
{
    struct node *p=new node;
    p=head;

    struct node *t=new node;
    t->data=val;
    t->next=head;

    while(1)
    {
        if(p->next==head)
        {
            p->next=t;
            break;
        }
        p=p->next;
    }

    head=t;

}

void insert_after_pos(int val,int pos)
{

    struct node *p=new node;
     p=head;

     int c=1;
     while(1)
     {
         if(c==pos)
         {
             struct node *t=new node;
             t->data=val;
             t->next=p->next;

             p->next=t;
             break;
         }
         if(p->next==head)
         {
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


     int p;cin>>p;
     int x;cin>>x;

    cout<<"AFTER "<<endl;
    //insert_at_first(x);


    insert_after_pos(x,p);
    display();






}

