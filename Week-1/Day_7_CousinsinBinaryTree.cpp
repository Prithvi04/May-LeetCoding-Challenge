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
//Use level-order traversal (Breadth First Search) and keep track of level and parent of x and y when found
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL || (root->val==x || root->val==y))
            return false;
        queue<pair<TreeNode*,int>>q;
        pair<int,int>x1;
        pair<int,int>y1;
        bool f1=false,f2=false;
        q.push(make_pair(root,0));
        while(q.empty()==false)
        {
            if(f1==false || f2==false)
            {
                pair<TreeNode*,int>h=q.front();
                q.pop();
            
                if(h.first->left!=NULL)
                {
                    if(h.first->left->val==x)
                    {
                        x1=make_pair(h.first->val,h.second+1);
                        q.push(make_pair(h.first->left,h.second+1));
                        f1=true;
                    }
                    else if(h.first->left->val==y)
                    {
                        y1=make_pair(h.first->val,h.second+1);
                        q.push(make_pair(h.first->left,h.second+1));
                        f2=true;
                    }
                    else
                    {
                        q.push(make_pair(h.first->left,h.second+1));
                    }
                }
                if(h.first->right!=NULL)
                {
                    if(h.first->right->val==x)
                    {
                        x1=make_pair(h.first->val,h.second+1);
                        q.push(make_pair(h.first->right,h.second+1));
                        f1=true;
                    }
                    else if(h.first->right->val==y)
                    {
                        y1=make_pair(h.first->val,h.second+1);
                        q.push(make_pair(h.first->right,h.second+1));
                        f2=true;
                    }
                    else
                    {
                        q.push(make_pair(h.first->right,h.second+1));
                    }
                                   
                }
                
            }
            else
                break;

        }
        if(x1.first!=y1.first && x1.second==y1.second)
            return true;
        
        return false;
        
        
    }
};