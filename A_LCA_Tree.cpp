#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

//To find LCA
//1. Do DFS to find first node
//2. when visiting node check visited
//3. Also save the path
//4. For find second node do DFS again 
//5. Save path for second node too
//6. compare 1st path and 2nd path

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    map<int,bool> visited;
    TreeNode* Troot;
    
    vector<TreeNode*> DFS(TreeNode* findNode){
        stack<TreeNode*> st;
        visited.clear();
        TreeNode* cur=Troot;
        st.push(Troot);
        while(cur!=findNode){
            if(!visited[cur->val]){
                st.push(cur);
                visited[cur->val]=true;
            }
            if(cur->left!=nullptr&&!visited[cur->left->val]){
                cur=cur->left;
                continue;
            }
            else if(cur->right!=nullptr&&!visited[cur->right->val]){
                cur=cur->right;
                continue;
            }
            else{
                if(!st.empty()){
                    st.pop();
                    cur=st.top();
                }
                continue;
            }
        }
        st.push(findNode);
        vector<TreeNode*> ret;
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Troot=root;
        vector<TreeNode*> FirstPath;
        FirstPath=DFS(p);
        vector<TreeNode*> SecondPath;
        SecondPath=DFS(q);

        TreeNode* res;
        for(int i=0; i<FirstPath.size(); i++){
            for(int j=0; j<SecondPath.size(); j++){
                if(FirstPath[i]->val==SecondPath[j]->val){
                    return FirstPath[i];
                }
            }
        }
        return res;
    }
};



//Easy Better Solution!!!!
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}