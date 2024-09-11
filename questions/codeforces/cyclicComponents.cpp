#include<bits/stdc++.h>
using namespace std;
bool check=1;
void dfs(int node,vector<vector<int>>adjList,vector<int>& visited,vector<int>& indegree){
    visited[node]=1;
    if(indegree[node]!=2) check = check and 0;
    for(auto it : adjList[node]){
        if(!visited[it]) dfs(it,adjList,visited,indegree);
    }
    if(check==0) return;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> nodes(n+1);
    vector<vector<int>> adjList(n+1);
    vector<int> indegree(n+1,0);
    for(int edges = 0;edges<m;edges++){
        int x,y;cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        indegree[x]++;
        indegree[y]++;
    }
    int count = 0;
    vector<int> visited(n+1,0);

    for(int i=1;i<=n;i++){
       if(!visited[i]) {
        // check=1;
        // dfs(i,adjList,visited,indegree);
        // if(check){
        //     count++;
        // }
        check = 1;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int node = q.front();
            q.pop();
            visited[node]=1;
            check = (check and indegree[node]==2);
            for(auto it : adjList[node]){
                if(visited[it]==0) q.push(it);
            }
        }
        if(check) count++;
       }
       
       
    }
    
    cout<<count<<endl;

}