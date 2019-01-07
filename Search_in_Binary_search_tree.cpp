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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root){
            // cout<<root->val<<endl;
            if(root->val==val)
                return root;
            else if(root->val>val){
                return searchBST(root->left,val);
            } 
            else if(root->val<val){
                return searchBST(root->right,val);
            }    
        }
        return NULL;
    }
};

int main(){
    TreeNode* root;
    root->val=4;
    TreeNode* n;
    root->right=n;
    root->left=n;
    root->right->val=7;
    root->left->val=2;
    root->left->left->val=1;
    root->left->right->val=3;
    Solution a;
    a.searchBST(root,2);
}