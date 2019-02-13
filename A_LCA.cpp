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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> pst;
        deque<TreeNode*> qst;
        map<TreeNode*, bool> visit;
        TreeNode* cur= root;
        while(cur!=nullptr){
            // cout<<cur->val;
            if(cur==p){
                pst.push_back(cur);
                break;   
            }
            else{
                if(cur->left!=nullptr&&!visit[cur->left]){
                    pst.push_back(cur);
                    visit[cur]=true;
                    cur=cur->left;                    
                }
                else if(cur->right !=nullptr&&!visit[cur->right]){
                    pst.push_back(cur);
                    visit[cur]=true;
                    cur= cur->right;                    
                }
                else{
                    visit[cur]=true;
                    cur=pst.back();
                    pst.pop_back();                    
                }
            }
        }
        cur=root;
        visit.clear();
        while(cur!=nullptr){
            // cout<<cur->val;
            // cout<<visit[cur]<<endl;
            if(cur==q){
                qst.push_back(cur);
                break;   
            }
            else{
                if(cur->left!=nullptr&&!visit[cur->left]){
                    qst.push_back(cur);
                    visit[cur]=true;
                    cur=cur->left;                    
                }
                else if(cur->right !=nullptr&&!visit[cur->right]){
                    qst.push_back(cur);
                    visit[cur]=true;
                    cur= cur->right;                    
                }
                else{
                    visit[cur]=true;
                    cur=qst.back();
                    qst.pop_back();                    
                }
            }
        }
        TreeNode* res;
        while(1){
            if(qst.front()==pst.front()){
                res=qst.front();
                qst.pop_front();
                pst.pop_front();
            }
            else{
                break;
            }
        }
        return res;
    }
};