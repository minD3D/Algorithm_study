#include <iostream>
#include <vector>

using namespace std;
//Used BFS 
// Since I don't need to save path 
// I just cnt up when same level of nodes are ended

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res=1;
        queue<TreeNode*> t,t2;
        if(!root)
            return 0;

        t.push(root);
        TreeNode* crt;

        while(!t.empty()){
            crt=t.front();
            // cout<<crt->val;        
            t.pop();       

            if(crt->left)
                t2.push(crt->left);
            if(crt->right)
                t2.push(crt->right);
            if(t.empty()&&!t2.empty()){
                t.swap(t2);
                res++;
                cout<<res;

            }        
        }

        return res;

    }
};