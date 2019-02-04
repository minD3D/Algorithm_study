#include<vector>
#include<queue>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized_str="[";
        queue<TreeNode*> q;
        q.push(root);
        if(root!=nullptr)
            serialized_str+=root->val;
        else
            serialized_str+="null";

        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            serialized_str+=",";
            if(cur!=nullptr)
                serialized_str+=cur->val;
            else
            {
                serialized_str+="null";                
            }
            if(cur->left==nullptr&&cur->right==nullptr)
                continue;

            q.push(cur->left);
            q.push(cur->right);
        }
        serialized_str+="]";

        return serialized_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[null]")return nullptr;

        TreeNode* result_Tree= TreeNode(0);
        TreeNode* pnt=result_Tree;
        for(int i=1; i<data.length()-1; i++){
            int tmp=0;
            if(data[i]==','){
                if(pnt==nullptr)
                    pnt=new TreeNode(tmp);
                else
                    pnt->val=tmp;
            }
            else{
                if(data[i]=='n'){
                    i+=2;
                    pnt=nullptr;
                }
                if(data[i]=='-'){
                        tmp=-1;
                }
                else{
                    tmp*=10;
                    tmp+=(data[i]-'0');
                }
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//     1
//    / \
//   2   3
//      / \
//     4   5

// as "[1,2,3,null,null,4,5]"