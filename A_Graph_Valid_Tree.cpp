#include<map>
#include<vector>
#include<queue>
using namespace std;
//Valid tree doesn't have a round connection
//So Have to check if this graph has round connect
//Do DFS and check if each of dfs visit same edge again
//Every edge has to be connected

class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool res;
public:
    void DFS(int e,int b){
        if(visited[e]){
            res=false;
            return;
        }
        if(graph[e].size()==0)return;        
        visited[e]=true;
        for(int i=0; i<graph[e].size(); i++){//O(n)
            int tmp=graph[e][i];
            if(tmp!=b)
                DFS(tmp,e);
        }
        return;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n==1)return true;
        res=true;
        for(int i=0; i<n; i++){//O(n)
            visited.push_back(false);
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for(int i=0; i<edges.size(); i++){//O(n)
            int e1=edges[i].first;
            int e2=edges[i].second;
            graph[e1].push_back(e2);
            graph[e2].push_back(e1);
        }

        DFS(0,0);//O(n^2)
        for(int i=0; i<n; i++){//O(n)
            if(!visited[i])
                res=false;
        }        
        return res;
    }
};

//O(3n+n^2)=O(n^2)
