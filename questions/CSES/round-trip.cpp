//https://cses.fi/problemset/task/1669

#include<bits/stdc++.h>
using namespace std;

int node1=-1,node2=-1;

bool dfs(int child,int parent,vector<vector<int>>& adjList,vector<int>& visited,vector<int>& parents){
    visited[child]=1;
    parents[child]=parent;
    for(auto it : adjList[child]){
       if(visited[it]==0){
        parents[it]=child;
        if(dfs(it,child,adjList,visited,parents)) return true;
       }
       else {
        if(it!=parent) {
            node1=it,node2=child;
            return true;
        }
       }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjList(n);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    vector<int> visited(n,0);
    vector<int> parents(n);
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            if(dfs(i,-1,adjList,visited,parents)) {
                break;
            }
        }
    }
    
    if(node1==-1) {
        cout<<"IMPOSSIBLE\n";return 0;
    }
    vector<int> ans;
    int x = node2;
    //cout<<node1<<" "<<node2<<endl;
    while(x!=node1){
        ans.push_back(x);
        x = parents[x];
    }
    ans.push_back(node1);
    ans.push_back(node2);
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it+1<<" ";

}