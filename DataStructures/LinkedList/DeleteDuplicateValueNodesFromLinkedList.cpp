/**

This challenge is part of a tutorial track by MyCodeSchool

You're given the pointer to the head node of a sorted linked list, where the data in the nodes is in ascending order. 
Delete as few nodes as possible so that the list does not contain any value more than once. 
The given head pointer may be null indicating that the list is empty.

For now do not be concerned with the memory deallocation. In common abstract data structure scenarios, deleting an element might also require deallocating the memory occupied by it. 
For an initial intro to the topic of dynamic memory please consult: http://www.cplusplus.com/doc/tutorial/dynamic/

Input Format 
You have to complete the Node* RemoveDuplicates(Node* head) method which takes one argument - the head of the sorted linked list. 
You should NOT read any input from stdin/console.

Output Format 
Delete as few nodes as possible to ensure that no two nodes have the same data. Adjust the next pointers to ensure that the remaining nodes form a single sorted linked list. 
Then return the head of the sorted updated linked list. 
Do NOT print anything to stdout/console.

Sample Input

1 -> 1 -> 3 -> 3 -> 5 -> 6 -> NULL
NULL
Sample Output

1 -> 3 -> 5 -> 6 -> NULL
NULL
Explanation 
1. 1 and 3 are repeated, and are deleted. 
2. Empty list remains empty.

*/

/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

//Traverse the list from the head (or start) node. While traversing, compare each node with its next node. If data of next node is // same as current node then delete the next node. Before we delete a node, we need to store next pointer of the node
Node* RemoveDuplicates(Node *head)
{
    // This is a "method-only" submission. 
    // You only need to complete this method. 
    Node *current = head;
    Node *nextOfDuplicate;
    
    //Emptly
    if(current == NULL)
        return head;
    
    // Traverse
    while(current->next != NULL)
    {
        // Compare next with current
        if(current->data == current->next->data)
        {
            nextOfDuplicate = current->next->next;
            delete(current->next);
            current->next = nextOfDuplicate;
        }
        else
            current = current->next;
    }    
    return head;
}

/* Delete Duplicates from unsorted LL 
/* Function to remove duplicates from a unsorted linked list 
void removeDuplicates(struct node *start)
{
  struct node *ptr1, *ptr2, *dup;
  ptr1 = start;
 
  /* Pick elements one by one 
  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;
 
     /* Compare the picked element with rest of the elements 
     while(ptr2->next != NULL)
     {
       /* If duplicate then delete it 
       if(ptr1->data == ptr2->next->data)
       {
          /* sequence of steps is important here 
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          free(dup);
       }
       else /* This is tricky 
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}
*/