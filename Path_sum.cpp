#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool findEnd(TreeNode* n,int sum,int fsum){
    if(!n->left&&!n->right){
        // cout<<fsum<<" s: "<<sum+n->val<<endl;
        if(fsum==sum+n->val)
            return true;
    }
    if(n->left&&!n->right)
        return findEnd(n->left,sum+n->val,fsum);
    if(n->right&&!n->left)
        return findEnd(n->right,sum+n->val,fsum);
    if(n->right&&n->left)
        return findEnd(n->right,sum+n->val,fsum)|| findEnd(n->left,sum+n->val,fsum);
    
    return false;
}

bool hasPathSum(TreeNode* root, int sum) {
    if(!root&&sum==0)
        return true;
    if(!root&&sum!=0)
        return false;    
    return findEnd(root,0,sum);
}

int main(){
    TreeNode a1 = TreeNode(1);
    TreeNode a2 = TreeNode(2);
    TreeNode a3 = TreeNode(3);
    TreeNode a4 = TreeNode(4);
    TreeNode a5 = TreeNode(5);
    
    a1.left=&a2;
    a1.right=&a3;
    a2.left=&a4;
    a3.left=&a5;

    cout<<hasPathSum(&a1,6)<<endl;
  

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