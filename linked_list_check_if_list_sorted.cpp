

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

bool if_sorted(Node* head)
{
    Node* cur=head;

    bool f=true;

    while(cur->next)
    {
        if(cur->data > cur->next->data)
        {
            f=false;break;
        }
        cur=cur->next;
    }

    return f;
}


int main()
{
    Node* head=create();

    traverse(head);

    if(if_sorted(head)) cout<<"YES "<<endl;
    else cout<<"No "<<endl;


}
