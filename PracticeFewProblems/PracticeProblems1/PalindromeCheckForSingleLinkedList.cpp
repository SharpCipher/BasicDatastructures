/*Given the head of a singly linked list, return true if it is a palindrome.*/

/*Without using Stack DS */

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node* reverse(Node* head)
{
if(head==NULL)
        return head  ;
    
    if(head->next==NULL)
    { 
   		return head ;
    }
    
    Node* prev = NULL ;
    Node* cur = head ;
    Node* nextnd = head->next ;
    
    while(cur->next!=NULL)
    {
        cur->next = prev ;
        prev = cur ;
        cur = nextnd ;
        nextnd = nextnd->next ;
        
        if(nextnd==NULL)
        {
            cur->next = prev ;
            prev = cur ;
            break ;
        }
    }
    
    head = prev;
    
    return head ;
}

bool isPalindrome(Node *head)
{
    if(head ==NULL || head->next ==NULL)
        return true ;
   
    int mid = 0 ;
    Node* temp = head ;
    while(temp!=NULL)
    {
        mid++;
        temp = temp->next ;
    }
    mid =mid/2 ;
    temp = head ;
    while(mid--)
    {
        temp = temp ->next ;
    }
    
   Node* head2 =reverse(temp) ;
    
    while(head2!=NULL && head!=NULL)
    {
        if(head->data == head2->data )
        {
            head=head->next ;
            head2 = head2->next ;
        }
        else
            return false ;
        
    }
    return true ;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	
	
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	

	return 0;
}