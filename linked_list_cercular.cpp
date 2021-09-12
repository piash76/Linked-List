


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

        last->next=head;
    }


    return head;

}



void traverse(Node* head)
{

    Node* t=head;

    do
    {
        cout<<t->data<<endl;
        t=t->next;

    }while(t!=head);


}

bool is_circular(Node* head)
{

    Node* temp=head;

    do
    {
        if(temp==NULL) return false;

        temp=temp->next;

    }while(temp!=head);


    return true;
}


int main()
{
    Node* head=create();

    traverse(head);

    cout<<endl;

    Node* temp=head;

    temp=temp->next->next;

    traverse(temp);

    if(is_circular(head)) cout<<"YES"<<endl;


}
