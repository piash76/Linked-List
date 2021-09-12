
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

Node* insert_at_pos(Node* head,int val,int pos)
{
    if(pos==1)
    {
        Node* temp=new Node;
        temp->prev=NULL;
        temp->data=val;
        temp->next=head;
        head->prev=temp;

        head=temp;


    }
    else
    {
        Node* cur=head;

        int cnt=1;

        while(cur)
        {
           if(cnt==pos)
           {

              Node* nxt=cur->next;

              Node* temp=new Node;
              temp->prev=cur;
              temp->data=val;
              temp->next=nxt;

              cur->next=temp;
              if(nxt) nxt->prev=temp;
              break;

          }

         cnt++;
         cur=cur->next;
     }


    }

    return head;
}



Node* delete_at_pos(Node* head,int pos)
{
    Node* p=head;

    if(pos==1)
    {
        Node* nxt=head->next;

        delete p;

        nxt->prev=NULL;

        head=nxt;
    }
    else
    {

    int cnt=1;

    while(p)
    {
        if(cnt==pos)
        {

            Node* nxt=p->next;
            Node* prv=p->prev;

            prv->next=nxt;

            if(nxt) nxt->prev=prv;

            delete p;
            break;
        }
        p=p->next;
        cnt++;
    }

    }

    return head;
}



Node* reversing(Node* head)
{
    Node* cur=head;
    Node* prev;

    while(cur)
    {
       prev=cur->prev;
       cur->prev=cur->next;
       cur->next=prev;

       cur=cur->prev;
    }

    return prev->prev;

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

Node* insert_as_sorted(Node* prev_head,int data)
{
    Node* new_node=new Node;
    new_node->prev=NULL;
    new_node->data=data;
    new_node->next=NULL;

    Node* cur=prev_head;
    Node* head;

    if(cur==NULL)
    {
        head=new_node;
    }
    else if(new_node->data<=cur->data)
    {
        new_node->next=cur;
        cur->prev=new_node;

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

        new_node->prev=cur;
        new_node->next=next_node;


        cur->next=new_node;
        if(next_node!=NULL) next_node->prev=new_node;

    }

    return head;
}


int main()
{
    Node* head=create();
    traverse(head);

    cout<<endl;
   /// head=delete_at_pos(head,1);
   /// traverse(head);

  /// cout<<endl;

    ///head=insert_at_pos(head,100,3);
   /// traverse(head);

     head=insert_as_sorted(head,15);
     traverse(head);

}
