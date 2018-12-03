#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode* a, TreeNode* b){
    if(!a&&!b)
        return true;
    if(!a||!b)
        return false;

    return (a->val == b->val) && check(a->left,a->right) && check(b->left,b->right);
}

bool isSymmetric(TreeNode* root) {
    if(!root)return true;

    return check(root->left,root->right);
}


int main(){
    TreeNode a1 = TreeNode(1);
    TreeNode a2 = TreeNode(2);
    TreeNode a3 = TreeNode(3);
    TreeNode a4 = TreeNode(3);
    TreeNode a5 = TreeNode(2);
    
    a1.left=&a2;
    a1.right=&a3;
    a2.left=&a4;
    a3.left=&a5;

    cout<<isSymmetric(&a1);
  

}

// vector<int> inorderTraversal(TreeNode* root) {
//     vector<int> result;
//     vector<TreeNode*> tmp1;
//     vector<TreeNode*> tmp2;
//     TreeNode* mid;
//     tmp1.push_back(root);    
//     while(!tmp1.empty()){    
//         mid=tmp1.back();
//         tmp1.pop_back();
//         tmp2.push_back(mid);
//         if(mid->left){
//             tmp1.push_back(mid->left);
//         }
//         if(mid->right){
//             tmp1.push_back(mid->right);
//         }
//     }
//     while(!tmp2.empty()){
//         mid=tmp2.back();
//         tmp2.pop_back();
//         result.push_back(mid->val);
//     }
//     return result;

// }