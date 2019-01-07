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

    int height(Node* root) {
        queue<Node*> q;
        q.push(root);
        int h=0;
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right!=nullptr)
                q.push(cur->right);

            if(q.size()==0)
                h++;
        }
        // Write your code here.
        return h;
    }

}; //End of Solution