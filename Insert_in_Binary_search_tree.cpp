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

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* res= root;
        TreeNode* pnt=root;
        while(1){
            if(pnt){
                if(pnt->val>val){
                    pnt=pnt->left;
                } 
                else if(pnt->val<val){
                    pnt=pnt->right;
                }    
            }
            else{
                pnt->val=val;
                break;
            }
        }

        return res;
    }
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root){
            if(root->val>val){
                root->left = insertIntoBST(root->left, val);
            } 
            else if(root->val<val){
                root->right = insertIntoBST(root->right, val);
            }
        }
        else{
            TreeNode* a = new TreeNode(val);
            return a;
        }
        return root;
    }
};