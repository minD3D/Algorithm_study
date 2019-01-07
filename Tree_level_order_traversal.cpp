#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        Node *cur;
        queue<Node*> q;
        q.push(root);
        int s = 1;
        while(s--){
            cur=q.front();
            cout<<cur<<"->";
            q.pop();
            if(cur->right=nullptr)
                q.push(cur->right);
            if(cur->left=nullptr)
                q.push(cur->left);

            if(s==0)
                s=q.size();
        }

    }

}; //End of Solution