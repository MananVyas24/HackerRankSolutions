/**
Complete the postOrder function in your editor below, which has 11 parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

Input Format

Our hidden tester code passes the root node of a binary tree to your postOrder function.

Output Format

Print the tree's postorder traversal as a single line of space-separated values.

Sample Input

BTinput.png

Sample Output

1 4 5 6 2 3
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

void Postorder(node *root) 
{   
    if (root==NULL) return;
    // Post Order traversal = Left-Right-Data
    
    // Recurse
    Postorder(root->left);
    Postorder(root->right);
    cout<<(root->data)<<" ";
    
}