/**

This challenge is part of a tutorial track by MyCodeSchool

Given pointers to the head nodes of 22 linked lists that merge together at some point, find the Node where the two lists merge. 
It is guaranteed that the two head Nodes will be different, and neither will be NULL.

In the diagram below, the two lists converge at Node x:

[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
Complete the int FindMergeNode(Node* headA, Node* headB) method so that it finds and returns the Node where the two lists merge.

Input Format

The FindMergeNode(Node*,Node*) method has two parameters, headAheadA and headBheadB, which are the non-null head Nodes of two separate linked lists that are guaranteed to converge. 
Do not read any input from stdin/console.

Output Format

Each Node has a data field containing an integer; return the integer data for the Node where the two lists converge. 
Do not write any output to stdout/console.

Sample Input

The diagrams below are graphical representations of the lists that input Nodes headAheadA and headBheadB are connected to. Recall that this is a method-only challenge; the method only has initial visibility to those 22 Nodes and must explore the rest of the Nodes using some algorithm of your own design.

Test Case 0

 1
  \
   2--->3--->NULL
  /
 1
Test Case 1

1--->2
      \
       3--->Null
      /
     1
Sample Output

2
3
Explanation

Test Case 0: As demonstrated in the diagram above, the merge Node's data field contains the integer 22 (so our method should return 22). 
Test Case 1: As demonstrated in the diagram above, the merge Node's data field contains the integer 33 (so our method should return 33).

*/

/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
// c1 = length of LL1 : c2 = length of LL2
// d = abs(c1-c2)
// Traverse the bigger list from head->d so that both LL's now have equal count of Nodes
// Traverse both LL's in parallel until we find a common node

int getCount(Node *head)
{
    Node *current = head;
    int c = 0;
    while(current!=NULL)
    {
        c++;
        current = current->next;
    }
    return c;
}

int getIntersection(Node *headA, Node *headB, int d)
{
    Node *curr1 = headA;
    Node *curr2 = headB;
    
    //Traverse till d of longer LL
    for(int i=0; i<d; i++)
    {
        if(curr1 == NULL)
            return -1;
        curr1 = curr1->next;
    }
    
    while(curr1 != NULL && curr2 != NULL) //Now traverse ||el
    {
        if(curr1==curr2)
            return(curr1->data);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    //else
    return -1;
}

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    int C1 = getCount(headA);
    int C2 = getCount(headB);
    int d;
    if(C1>C2)
    {
        d = C1-C2;
        return(getIntersection(headA,headB,d));
    }
    else
    {
        d = C2-C1;
        return(getIntersection(headB,headA,d));
    }
    
}