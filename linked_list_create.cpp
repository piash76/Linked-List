
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

void rectraverse(Node* head)
{
    if(head==NULL) return;
    else
    {
        cout<<head->data<<endl;
        rectraverse(head->next);
    }
}

void insert_after_pos(Node* cur,int p,int x)
{
    if(p==1)
    {
        Node* tmp=new Node;
        tmp->data=x;
        tmp->next=cur->next;

        cur->next=tmp;
    }
    else
    {
        insert_after_pos(cur->next,p-1,x);
    }
}

void insert_at_first(int val)  /// 0(1)
{
    struct node *t=new node;
    t->data=val;
    t->next=head;
    head=t;
}

void insert_at_last(int val)   ///0(1)
{
    struct node *t=new node;
    t->data=val;
    t->next=NULL;
    last->next=t;
    last=t;
}

void insert_after_pos(int pos,int val)   ///0(N)
{
    struct node *p=new node;
    p=head;

    int cnt=1;
    while(p)
    {
        if(cnt==pos)
        {
            struct node *t=new node;
            t->data=val;
            t->next=p->next;
            p->next=t;
            break;
        }
        cnt++;
        p=p->next;
    }


}


void delete_first()
{
    struct node *p;
    p=new node;
    p=head;
    head=head->next;

    delete p;
}

void delete_the_pos(Node* head,int pos) ///deleting the nth node
{
    int cnt=1;
     Node* p;
    p=head;


    while(p)
    {
        if(cnt==pos-1)
        {
            Node* t;
            t=p->next;
            p->next=t->next;

            delete t;
            break;

        }
        cnt++;
        p=p->next;
    }


}

void delete_first_occu(Node* head,int x) ///deleting the first occurence of x
{
    Node* cur=head;

    while(cur)
    {
        if(cur->next->data==x)
        {
            Node* temp=cur->next;

            cur->next=temp->next;

            delete temp;

            break;

        }
        cur=cur->next;
    }

}

///p--q--r

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
        new_node->next=head;
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


Node* middleNode(Node* head)
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
    ///rectraverse(head);

   /// insert_after_pos(head,3,10);
    ///traverse(head);

    cout<<endl;

   /// delete_first_occu(head,3);
   /// traverse(head);

   Node* head2=reversing(head);

   traverse(head2);



    return 0;

}



