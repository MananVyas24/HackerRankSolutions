/**
This challenge is part of a tutorial track by MyCodeSchool and is accompanied by a video lesson.

You’re given the pointer to the head node of a linked list and the position of a node to delete. 
Delete the node at the given position and return the head node. A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. 
The list may become empty after you delete the node.

Input Format 
You have to complete the Node* Delete(Node* head, int position) method which takes two arguments - the head of the linked list and the position of the node to delete. 
You should NOT read any input from stdin/console. position will always be at least 0 and less than the number of the elements in the list.

Output Format 
Delete the node at the given position and return the head of the updated linked list. Do NOT print anything to stdout/console.

Sample Input

1 --> 2 --> 3 --> NULL, position = 0 
1 --> NULL , position = 0

Sample Output

2 --> 3 --> NULL
NULL
Explanation 
1. 0th position is removed, 1 is deleted from the list. 
2. Again 0th position is deleted and we are left with empty list.

*/

/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    // Complete this method
    Node *current = head;
    Node *previous = NULL;
    
    for(int i=0; i<position; i++)
    {
        previous = current; //Prev contains N-1th element
        current = current->next; // Current contains Nth element
    }
    if(position != 0)
        previous->next = current->next;
    else //Head
        head = head->next;
    
    delete(current);
    return head;
        
}
