//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
    public:
    Node *reverseLL(Node *head) {
        if (!head || !head->next) return head;
        
        Node *rest = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return rest;
    }
    
    Node *compute(Node *head) {
        Node *dummy = new Node(0);
        Node *temp = dummy;
        
        head = reverseLL(head);
        int maxi = INT_MIN;
        
        while(head) {
            if (maxi <= head->data) {
                temp->next = new Node(head->data);
                maxi = head->data;
                
                temp = temp->next;
            }
            
            head = head->next;
        }
        
        return reverseLL(dummy->next);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends