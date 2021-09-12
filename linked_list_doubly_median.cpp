
#include<bits/stdc++.h>

using namespace std;



struct Node
{
    Node* prev;
    int data;
    Node* next;
};


Node* create()
{
    Node* head=NULL;
    Node* last=NULL;

    while(1)
    {
        int user_data;cin>>user_data;

        if(user_data==-1) break;

        Node* cur=new Node;
        cur->prev=last;
        cur->data=user_data;
        cur->next=NULL;


        if(head==NULL)
        {
            head=cur;
            last=cur;
        }
        else
        {
            last->next=cur;
            last=cur;
        }
    }

    return head;
}


void traverse(Node* head)
{
    Node* temp=head;

    while(temp)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}


Node* median(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}





int main()
{
    Node* head=create();
    traverse(head);

    cout<<endl;

    Node* nd=median(head);
    cout<<nd->data<<endl;

}


