/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)return res;
        
        vector<vector<int>> str;
        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);
        
        vector<int> tmp;
        int sz=q.size();
        while(!q.empty()){
            while(sz--){
                cur=q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->right!=nullptr)
                    q.push(cur->right);
                if(cur->left!=nullptr)
                    q.push(cur->left);
            }
            str.push_back(tmp);
            tmp.clear();
            sz=q.size();
        }
        
        for(int i=0; i<str.size(); i++){
            res.push_back(str[i][0]);
        }
        return res;
    }
};