/**

This challenge is part of a tutorial track by MyCodeSchool

You’re given the pointer to the head node of a doubly linked list. 
Reverse the order of the nodes in the list. 
The head node might be NULL to indicate that the list is empty.

Input Format 
You have to complete the Node* Reverse(Node* head) method which takes one argument - the head of the doubly linked list. 
You should NOT read any input from stdin/console.

Output Format 
Change the next and prev pointers of all the nodes so that the direction of the list is reversed. 
Then return the head node of the reversed list. Do NOT print anything to stdout/console.

Sample Input

NULL 
NULL <-- 2 <--> 4 <--> 6 --> NULL

Sample Output

NULL
NULL <-- 6 <--> 4 <--> 2 --> NULL
Explanation 
1. Empty list, so nothing to do. 
2. 2,4,6 become 6,4,2 o reversing in the given doubly linked list.

*/

/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

/*
swap prev and next pointers for all nodes, change prev of the head (or start) and change the head pointer in the end.
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    Node *temp = NULL;
    Node *current = head;
    
    //Swap next and current for all nodes in the DLL
    while(current!=NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    //Adjust Head
    if(temp != NULL)
        head = temp->prev;
    return head;
}