/**
You are given a pointer to the root of a binary tree. You need to print the level order traversal of this tree. In level order traversal, we visit the nodes level by level from left to right. 
You only have to complete the function. 
For example:

         3
       /   \
      5     2
     / \    /
    1   4  6
For the above tree, the level order traversal is 3 -> 5 -> 2 -> 1 -> 4 -> 6.

Input Format

You are given a function,

void level_order(node * root)
{

}
Output Format

Print the values in a single line seperated by a space.

Sample Input

         3
       /   \
      5     2
     / \    /
    1   4  6
Sample Output

3 5 2 1 4 6
Explanation

Level 1:        3
              /   \
Level 2:     5     2
            / \    /
Level 3:   1   4  6
We need to print the nodes level by level. We process each level from left to right. 
Level Order Traversal: 3 -> 5 -> 2 -> 1 -> 4 -> 6

*/

#include<queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    if(!root)
        return;
    
    queue<node *>Q;
    
    for(Q.push(root); !Q.empty(); Q.pop())
    {
        const node * const temp = Q.front();
        cout<<(temp->data)<<" ";
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
  
}