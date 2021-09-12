#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int Data;
    Node* Next;
};

Node* Head;

void InsertEnd(int num)
{
    Node *NewNode;
    NewNode=new Node;
    NewNode->Data=num;
    NewNode->Next=NULL;

    Node* EndNode;
    EndNode=Head;

    if(EndNode == NULL)
       EndNode=NewNode;
    else
    {
        while(EndNode->Next!=NULL)
            EndNode=EndNode->Next;
        ///by now EndNode->Next is equal to null
        EndNode->Next=NewNode;///so this is what you need

    }
}
void PrintList()
{
	Node* NewNode=Head;
	cout<<"List is: ";
	while(NewNode!=NULL)
	{
		cout<<NewNode->Data<<" ";
		NewNode=NewNode->Next;
	}
	cout<<endl;
}

int main()
{
    Head=NULL;
    InsertEnd(90);
    InsertEnd(80);
    PrintList();

    return 0;
}
