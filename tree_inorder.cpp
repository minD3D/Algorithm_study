#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    vector<TreeNode*> tmp;    
    while(root||!tmp.empty()){
        while(root){
            tmp.push_back(root);
            root=root->left;
        }
        root=tmp.back();
        result.push_back(root->val);
        tmp.pop_back();
        root=root->right;
    }
    return result;
}
