/**
This challenge is part of a tutorial track by MyCodeSchool and is accompanied by a video lesson.

You’re given the pointer to the head node of a linked list. 
Change the next pointers of the nodes so that their order is reversed. 
The head pointer given may be null meaning that the initial list is empty.

Input Format 
You have to complete the Node* Reverse(Node* head) method which takes one argument - the head of the linked list. 
You should NOT read any input from stdin/console.

Output Format 
Change the next pointers of the nodes that their order is reversed and return the head of the reversed linked list. 
Do NOT print anything to stdout/console.

Sample Input

NULL 
2 --> 3 --> NULL

Sample Output

NULL
3 --> 2 --> NULL
Explanation 
1. Empty list remains empty 
2. List is reversed from 2,3 to 3,2

*/

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

// Time Complexity: O(n)
// Space Complexity: O(1)
/*
    The trick to this algorithm is you need 3 Node pointers to accomplish the reversal.
    next - Tracks the pointer to the next item in the list.
    head - Initially contains the original head of the list but will then be set to the pointer to the next item in the list until     the NULL pointer is encountered.
    cursor - Initially is set to NULL but then tracks the new head of the list. At the end of the list, head equals NULL and the       value of cursor is returned to the caller.
*/
Node* Reverse(Node *head)
{
    Node *cursor = NULL;
    Node *next;
    while (head)
    {
        next = head->next;
        head->next = cursor;
        cursor = head;
        head = next;
    }
    return cursor;
}