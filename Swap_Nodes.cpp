#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
struct Node{
    int val;
    Node* left;
    Node* right;
    bool visit=false;
    Node(int x) : val(x), left(NULL), right(NULL){}
};

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> res;    
    Node* Root = new Node(1);

    //insert nodes
    queue<Node*> q;
    q.push(Root);
    for(int i=0; i<indexes.size(); i++){
        Node* cur;
        if(!q.empty())
        {
            cur=q.front();
            q.pop();
        }
        if(indexes[i][0]!=-1){
            cur->left=new Node(indexes[i][0]);
            q.push((cur->left));
        }
        if(indexes[i][1]!=-1){
            cur->right=new Node(indexes[i][1]);
            q.push((cur->right));
        }
    }

    //add sepcific level node to q
    for(int i=0 ; i<queries.size(); i++){
        Node* cur = Root;
        int lv=1;
        vector<Node*> levelqa;
        vector<Node*> levelq;
        levelq.push_back(cur);
        cout<<queries[i]<<"!!"<<endl;
        if(queries[i]==1)levelqa.push_back(cur);
        while(!levelq.empty()){
            vector<Node*> leveltmp;
            lv+=1;
            for(int j=0; j<levelq.size(); j++){
                cur=levelq[j];
                if(cur->left!=nullptr){
                    if(lv%queries[i]==0)
                        levelqa.push_back(cur->left);
                    leveltmp.push_back(cur->left);
                }
                if(cur->right!=nullptr){
                    if(lv%queries[i]==0)
                        levelqa.push_back(cur->right);
                    leveltmp.push_back(cur->right);
                }
            }
            levelq.swap(leveltmp);
        }
        //swap left and right
        for(int j=0; j<levelqa.size(); j++){
            // cout<<"here"<<endl;
            cur=levelqa[j];
            Node* tmp;
            tmp=cur->left;
            cur->left=cur->right;
            cur->right=tmp;
            // cout<<cur->left->val<<"<->"<<cur->right->val<<endl;

        }

        //inorder treversal
        cur = Root;
        vector<int> t_res;
        stack<Node*> st;
        while(1){
            while(cur->left!=nullptr&&!cur->left->visit){
                st.push(cur);
                cur=cur->left;
            }
            t_res.push_back(cur->val);
            cout<<"->"<<cur->val<<endl;
            cur->visit=true;
            if(cur->right!=nullptr){
                st.push(cur);            
                cur=cur->right;
            }
            else{
                while(cur->visit){
                    if(st.empty())break;
                    cur=st.top();
                    st.pop();
                }
            }
            if(cur->visit)break;
        }
        res.push_back(t_res);
        queue<Node*> vq;
        vq.push(Root);
        while(!vq.empty()){
            cur=vq.front();
            vq.pop();
            cur->visit=false;
            if(cur->left!=nullptr)
                vq.push(cur->left);
            if(cur->right!=nullptr)
                vq.push(cur->right);
        }
    }

    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}


