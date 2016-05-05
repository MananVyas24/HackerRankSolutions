/**

Complete the preOrder function in your editor below, which has 11 parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

Input Format

Our hidden tester code passes the root node of a binary tree to your preOrder function.

Output Format

Print the tree's preorder traversal as a single line of space-separated values.

Sample Input

BTinput.png

Sample Output

3 5 1 4 2 6

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

void Preorder(node *root) 
{   
    if (root==NULL) return;
    // Pre Order traversal = Data-Left-Right
    cout<<(root->data)<<" ";
    // Recurse
    Preorder(root->left);
    Preorder(root->right);
    
}