#include<iostream>
#include<queue>

using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

queue<TreeNode*> q;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root!=nullptr)
            q.push(root);
        int s=q.size();
        while(s--){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left!=nullptr){
                TreeNode* lv=cur->left;
                if(cur->val>=lv->val)
                    q.push(cur->left);
                else
                    return false;
            }
            if(cur->right!=nullptr){
                TreeNode* rv=cur->right;
                if(cur->val<=rv->val)
                    q.push(cur->right);
                else
                    return false;                                 
            }
            if(s==0)s=q.size();
        }
        return true;
    }
};


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root != nullptr) {
            TreeNode* lv = nullptr;
            TreeNode* rv = nullptr;
            queue<tuple<TreeNode*,TreeNode*,TreeNode*>> trav;
            trav.emplace(lv,root,rv);
            while (! trav.empty()) {
                std::tie(lv,root,rv) = trav.front(); trav.pop();
                if (((lv != nullptr) && (lv->val >= root->val)) ||
                    ((rv != nullptr) && (rv->val <= root->val))) {
                        return false;
                }
                if (root->left != nullptr) {
                    trav.emplace(lv, root->left, root);
                }
                if (root->right != nullptr) {
                    trav.emplace(root, root->right, rv);
                }
            }
        }
        return true;
    }
};
