#include<map>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
#include<set>
using namespace std;
//Find order from first letters
//Push at same queue if first letters are same 
//Do 1,2 in queue
//Merge connections
class Solution {
private:
    map<char, set<char>> adj;
    set<char> vertices;
public:
    void compare(string word1, string word2){
        int len= min(word1.length(), word2.length());
        for(int i=0; i<len; i++){
            if(word1[i]!=word2[i]){
                adj[word1[i]].insert(word2[i]);
                break;
            }
        }

        for(auto ch:word1)
            vertices.insert(ch);

        for(auto ch:word2)
            vertices.insert(ch);
    }

    bool topologicalSort(stack<char> &stack, unordered_map<char,int>&visited, char v){
        visited[v]=1;

        for(auto val: adj[v]){
            if(visited[val]==1)return false;
            if(visited[val]==0)
                if(!topologicalSort(stack,visited,val))return false;
        }
        stack.push(v);
        visited[v]=2;
        return true;
    }
    string alienOrder(vector<string>& words) {
        if(words.size()==1)
            return words[0];
        stack<char> stack;
        for(int i=0; i<words.size()-1; i++){
            compare(words[i],words[i+1]);
        }
        unordered_map<char,int>visited;

        for(auto vertex: vertices){
            visited[vertex]=0;
            if(adj.find(vertex)==adj.end()){
                adj[vertex]=set<char>();
            }
        }

        for(auto vertex:vertices){
            if(visited[vertex]==0){
                if(!topologicalSort(stack,visited,vertex)) return "";
            }
        }
        
        string s="";
        while(!stack.empty()){
            s+=stack.top();
            stack.pop();
        }
        return s;
    }
};

// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// w e r
//     r t
//       t f
