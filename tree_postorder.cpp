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
    vector<TreeNode*> tmp1;
    vector<TreeNode*> tmp2;
    TreeNode* mid;
    tmp1.push_back(root);    
    while(!tmp1.empty()){    
        mid=tmp1.back();
        tmp1.pop_back();
        tmp2.push_back(mid);
        if(mid->left){
            tmp1.push_back(mid->left);
        }
        if(mid->right){
            tmp1.push_back(mid->right);
        }
    }
    while(!tmp2.empty()){
        mid=tmp2.back();
        tmp2.pop_back();
        result.push_back(mid->val);
    }
    return result;
}
