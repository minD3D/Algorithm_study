// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
// /**
//  * Definition for a binary tree node.

//  */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // bfs with null ptr
        queue <TreeNode*> pq;
        queue <TreeNode*> qq;
        if(p!=nullptr)
            pq.push(p);
        if(q!=nullptr)
            qq.push(q);
        TreeNode* curp;
        TreeNode* curq;

        while(!pq.empty()||!qq.empty()){
            curp=pq.front();
            pq.pop();
            curq=qq.front();
            qq.pop();
            // cout<<"aaa"<<endl;
            cout<<curp->val <<curq->val<<endl;

            if(curp->val!=curq->val){
                return false;
            }
            if(curp->val!=-999999999){
                if(curp->left!=nullptr){
                    pq.push(curp->left);
                }
                else{
                    pq.push(new TreeNode(-999999999));
                }
                if(curp->right!=nullptr){
                    pq.push(curp->right);
                }
                else{
                    pq.push(new TreeNode(-999999999));
                }
            }
            if(curq->val!=-999999999){
                if(curq->left!=nullptr){
                    qq.push(curq->left);
                }
                else{
                    qq.push(new TreeNode(-999999999));
                }
                if(curq->right!=nullptr){
                    qq.push(curq->right);
                }
                else{
                    qq.push(new TreeNode(-999999999));
                }
            }
        }        
        return true;
    }
};

// int main(){
//     Solution a;
//     TreeNode* b=new TreeNode(1);
//     TreeNode* c=new TreeNode(1);

//     cout<<a.isSameTree(b,c);
// }