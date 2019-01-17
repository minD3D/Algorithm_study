#include <iostream>
#include <stack>

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
 //use stack and dfs
class Solution {
public:
    int maxval(int a, int b){
        return a>=b ? a : b;
    }
    int dfs(TreeNode* node, int sum){
        if(node==nullptr)return sum;
        
        int maxmrl=sum;
        int ml,mr,l,r;
        //me+left
        if(node->left!=nullptr){
            ml=dfs(node->left,sum+node->left->val);
            l=dfs(node->left,sum);
            maxmrl=max(l,ml)>maxmrl ? max(l,ml) : maxmrl;
        }
        //me+right
        if(node->right!=nullptr){
            mr=dfs(node->right,sum+node->right->val);
            r=dfs(node->right,sum);
            maxmrl=max(mr,r)>maxmrl ? max(mr,r) : maxmrl;
        }
        //me+left+right
        if(node->right!=nullptr&&node->left!=nullptr){
            int mrl=ml+mr-node->val;
            maxmrl=mrl>maxmrl ? mrl : maxmrl;
        }
        return maxmrl;
    }
    int maxPathSum(TreeNode* root) {
        return dfs(root, root->val);
    }
};

//    -10
//    / \
//   9  20
//     /  \
//    15   7

//  -10
// 9   20
//   35  27


//  7
//  20
//15 -10
//     9