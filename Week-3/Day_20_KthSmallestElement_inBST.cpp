/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count,x;
    void kthrec(TreeNode *root,int k)
    {
        if(root==NULL)
            return;
        kthrec(root->left,k);
        count++;
        if(count==k)
        {
            x=root->val;
            return;
        }
        kthrec(root->right,k);
   
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return -1;
        count=0;
        kthrec(root,k);
        return x;
      
        
    }
};
//Traverse The BST in preorder and decrement K, to find Kth smallest element.