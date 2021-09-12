


bool is_palindrome(ListNode* head)
{
    stack<int> s;
    ListNode* temp=head;

    while(temp)
    {
        s.push(temp->val);
        temp=temp->next;
    }

    bool f=true;

    ListNode* temp2=head;

    while(temp2)
    {
        int val=s.top();
        s.pop();

        if(temp2->val!=val)
        {
            f=false;break;
        }
        temp2=temp2->next;
    }

    return f;

}
