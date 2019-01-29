#include<vector>
#include<queue>
using namespace std;
//Only need to check if there are round routine

class Solution {
private:
    vector<vector<int>> adj;
    int numOfEdges;
public:
    bool checkRoutine(int e){//O(n^2)=>BFS
        bool visited[numOfEdges];
        for(int i=0; i<numOfEdges; i++){
            visited[i]=false;
        }
        queue<int> q;
        q.push(e);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            visited[cur]=true;
            for(int i=0; i<adj[cur].size(); i++){
                if(adj[cur][i]==e){
                    return false;   
                }
                if(!visited[adj[cur][i]]){
                    q.push(adj[cur][i]);
                }
            }
        }
        return true;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.size()<=1)return true;
        numOfEdges=numCourses;
        for(int i=0; i<numCourses; i++){//O(n)
            vector<int> a;
            adj.push_back(a);
        }

        for(int i=0; i<prerequisites.size(); i++){//O(n)
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }

        for(int i=0; i<numCourses; i++){//O(n)
            if(!checkRoutine(i))return false;
        }
        return true;
    }
};