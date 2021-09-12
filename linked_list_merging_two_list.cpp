///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>
using namespace std;

int a[50],b[50];
int n;

struct node    ///self referential structure
{
    int data;
    struct node *next;  ///pointing to next node
};

struct node *head1,*head2,*head3,*last1,*last2,*last3;


void creation1()
{
    head1=new node;
    head1->data=a[0];
    head1->next=NULL;
    last1=head1;

    for(int i=1;i<n;i++)
    {
        struct node *t=new node;
        t->data=a[i];
        t->next=NULL;

        last1->next=t;
        last1=t;
    }
}

void creation2()
{
    head2=new node;
    head2->data=b[0];
    head2->next=NULL;
    last2=head2;

    for(int i=1;i<n;i++)
    {
        struct node *t=new node;
        t->data=b[i];
        t->next=NULL;

        last2->next=t;
        last2=t;
    }
}


void display(struct node *h)
{

   struct node *p=new node;
    p=h;

    cout<<"ELEMENTS "<<endl;

    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }


}

void merging()
{
    if(head1->data<head2->data)
    {
        head3=head1;
        head1=head1->next;

        head3->next=NULL;
        last3=head3;
    }
    else
    {
         head3=head2;
         head2=head2->next;

        head3->next=NULL;
        last3=head3;
    }

   // cout<<"data "<<head3->data<<endl;
   // cout<<"DATA 1 "<<head1->data<<endl;
    //cout<<"DATA 2 "<<head2->data<<endl;
       // cout<<"DATA L "<<last3->data<<endl;

    while(head1!=NULL and head2!=NULL)
    {
        // cout<<"YES"<<endl;
        if(head1->data<head2->data)
        {
           // cout<<"YES"<<endl;
           // cout<<"UPOR "<<endl;

            last3->next=head1;  ///connect with prev last

            last3=head1;       ///new last

            head1=head1->next;

            last3->next=NULL;




       // cout<<"DATA 1 "<<head1->data<<endl;
        //cout<<"DATA 2 "<<head2->data<<endl;
       //cout<<"DATA L "<<last3->data<<endl;


        }
        else
        {
           // cout<<"YES"<<endl;
              //cout<<"NICH "<<endl;
             last3->next=head2;  ///connect with prev last

            last3=head2;       ///new last
            head2=head2->next;

            last3->next=NULL;




             //cout<<"DATA 1 "<<head1->data<<endl;
        //cout<<"DATA 2 "<<head2->data<<endl;
       //cout<<"DATA L "<<last3->data<<endl;
        }

    }

    if(head1!=NULL) last3->next=head1;
    if(head2!=NULL) last3->next=head2;
}







int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    creation1();creation2();
    display(head1);
    display(head2);

    cout<<"AFTER "<<endl;
    merging();
    display(head3);

}

/*

3
1 3 5
2 4 6

*/
