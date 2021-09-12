
///https://www.youtube.com/watch?v=-DtNInqFUXs
///time complexity O(N) and space complexity O(1)

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


bool is_palindrome(Node* head)
{
    ///null or single linked list

    if(head==NULL or head->next==NULL) return true;

    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL and fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    slow->next=reversing(slow->next);
    slow=slow->next;

    bool f=true;

    Node* cur=head;

    while(slow!=NULL)
    {
        if(slow->data!=cur->data)
        {
            f=false;break;
        }

       slow=slow->next;
       cur=cur->next;
    }


    return f;

}



int main()
{

    Node* head=create();
    ///traverse(head);

    if(is_palindrome(head)) cout<<"YES "<<endl;
    else cout<<"NO "<<endl;
}

