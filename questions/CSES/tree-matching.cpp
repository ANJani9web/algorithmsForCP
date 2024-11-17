//https://cses.fi/problemset/task/1130

#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void dfs(int parent,int current,vector<vector<int>>& adj,vector<int>& visited){
   for(auto it : adj[current]){
        if(it!=parent){
            dfs(current,it,adj,visited);
            if(visited[it]==0 and visited[current]==0){
                ans++;
                visited[it]=1;
                visited[current]=1;
            }
        }
   }
}

int main(){
    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++) {
        int x,y;cin>>x>>y;
        //x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> visited(n+1,0);
    dfs(0,1,adj,visited);
    cout<<ans<<endl;
}