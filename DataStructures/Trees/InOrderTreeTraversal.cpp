/**
Complete the inOrder function in your editor below, which has 11 parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

Input Format

Our hidden tester code passes the root node of a binary tree to your inOrder function.

Output Format

Print the tree's inorder traversal as a single line of space-separated values.

Sample Input

BTinput.png

Sample Output

1 5 4 3 6 2
*/

/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Inorder(node *root) 
{   
    if (root==NULL) return;
    // Post Order traversal = Left-Data-Right
    
    // Recurse
    Inorder(root->left);
    cout<<(root->data)<<" ";
    Inorder(root->right);
    
}