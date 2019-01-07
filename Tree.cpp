#include<iostream>
#include<vector>
using namespace std;

struct Tree{
    int val;
    Tree* left;
    Tree* right;
    Tree(int x): val(x), left(NULL), right(NULL){}
};

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// class solution
// {
//     private:
//     public:
//         Tree* build(vector<int>& preorder){
            
//         }
// }

int main(){
    Tree* a = new Tree(1);
    a->left = new Tree(2);
    a->right = new Tree(3);

    cout<< a->val<<endl;
    cout<< a->left->val<<endl;
    cout<< a->right->val<<endl;
}