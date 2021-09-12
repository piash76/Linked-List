
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



Node* insert_as_sorted(Node* prev_head,int data)
{
    Node* new_node=new Node;
    new_node->data=data;
    new_node->next=NULL;



    Node* cur=prev_head;
    Node* head;
    ///if list is empty
    if(cur==NULL)
    {
        head=cur;
    }
    else if(new_node->data <= cur->data)  ///less or equal to head->data
    {
        new_node->next=cur;
        head=new_node;
    }
    else
    {
        head=prev_head;
        while(cur->next and new_node->data > cur->next->data)
        {
            cur=cur->next;
        }

        Node* next_node=cur->next;

        new_node->next=next_node;
        cur->next=new_node;

    }

    return head;
}

int main()
{
    Node* head=create();

    traverse(head);

    cout<<endl;

    Node* head2=insert_as_sorted(head,4);
    traverse(head2);
}
