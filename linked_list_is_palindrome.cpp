

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


bool is_palindrome(Node* head)
{
    ///null or single linked list

    if(head==NULL or head->next==NULL) return true;

    stack<int> s;
    Node* temp=head;

    while(temp)
    {
        s.push(temp->data);
        temp=temp->next;
    }

    bool f=true;

    Node* temp2=head;

    while(temp2)
    {
        int val=s.top();
        s.pop();

        if(temp2->data!=val)
        {
            f=false;break;
        }
        temp2=temp2->next;
    }

    return f;

}





int main()
{

    Node* head=create();
    traverse(head);


    if(is_palindrome(head)) cout<<"YES "<<endl;
    else cout<<"No"<<endl;






}
