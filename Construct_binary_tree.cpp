#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* ittr(vector<int>::iterator ins, vector<int>::iterator ine, vector<int>::iterator pos, vector<int>::iterator poe){
    if(ins==ine)return nullptr;
    int rootval = *(poe-1);
    auto init= find(ins,ine,rootval);
    auto poit= pos+(init-ins);
    TreeNode* crrt = new TreeNode(rootval);
    crrt->left=ittr(ins,init,pos,poit);
    crrt->right=ittr(init+1,ine,poit,poe-1);
    return crrt;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    ittr(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    
}


int main(){
  

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