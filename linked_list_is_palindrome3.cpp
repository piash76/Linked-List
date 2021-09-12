#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* create()
{
    Node* head=NULL;
    Node* last;

    while(1)
    {
        int user_data;cin>>user_data;

        if(user_data==-1) break;

        Node* cur_node=new Node;
        cur_node->data=user_data;
        cur_node->next=NULL;

        if(head==NULL)
        {
            head=cur_node;
        }
        else
        {
            last->next=cur_node;

        }

        last=cur_node;
    }


    return head;

}


void traverse(Node* head)
{
    Node* t=head;

    while(t!=NULL)
    {
        cout<<t->data<<endl;
        t=t->next;
    }

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


Node* copy_of(Node* head)
{
    Node* head2=NULL;
    Node* cur=head;

    Node* last;

    while(cur)
    {
        Node* new_node=new Node;
        new_node->data=cur->data;
        new_node->next=NULL;

        if(head2==NULL)
        {
            head2=new_node;
        }
        else
        {
            last->next=new_node;

        }

        last=new_node;

        cur=cur->next;

    }

    head2=reversing(head2);

    return head2;
}

bool is_palindrome(Node* head1,Node* head2)
{
    Node* cur1=head1;

    Node* cur2=head2;

    bool f=true;
    while(cur1 and cur2)
    {
        if(cur1->data!=cur2->data)
        {
            f=false;break;
        }
        cur1=cur1->next;
        cur2=cur2->next;
    }

    return f;
}

int main()
{

    Node* head1=create();
    traverse(head1);

    cout<<endl;


    Node* head2=copy_of(head1);
    traverse(head2);

    cout<<endl;


    if(is_palindrome(head1,head2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

