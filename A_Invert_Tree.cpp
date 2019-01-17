#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        
        TreeNode* res = new TreeNode(root->val);
        queue <TreeNode*> q;
        queue <TreeNode*> pntq;
        q.push(root);
        pntq.push(res);
        TreeNode* cur;
        TreeNode* pnt;

        while(!q.empty()){
            int qs= q.size();
            while(qs--){
                cur=q.front();
                q.pop();
                pnt=pntq.front();
                pntq.pop();
                if(cur->right!=nullptr){
                    pnt->left=new TreeNode(cur->right->val);
                    q.push(cur->right);
                    pntq.push(pnt->left);
                }
                if(cur->left!=nullptr){
                    pnt->right=new TreeNode(cur->left->val);
                    q.push(cur->left);
                    pntq.push(pnt->right);
                }
            }
            if(qs==0){
                qs=q.size();
            }
        }
        return res;
    }
};

//q
//    4
//  7   2
// 9 6    1
// 00000000

//pntq
//   4
//  2   7
//1    6  9
