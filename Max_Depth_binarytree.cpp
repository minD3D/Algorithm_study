#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    int res=1;
    queue<TreeNode*> t,t2;
    if(!root)
        return res;
    
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

int main(){
    TreeNode a1 = TreeNode(1);
    TreeNode a2 = TreeNode(2);
    TreeNode a3 = TreeNode(3);
    TreeNode a4 = TreeNode(4);
    TreeNode a5 = TreeNode(5);
    
    a1.left=&a2;
    a1.right=&a3;
    a2.left=&a4;
    a3.right=&a5;

    int res= maxDepth(&a1);
    // cout<<res[1][1];

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