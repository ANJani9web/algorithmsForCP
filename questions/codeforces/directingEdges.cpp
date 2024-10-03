//https://codeforces.com/contest/1385/problem/E

#include<bits/stdc++.h>
using namespace std;

// finding the topo sort the directed part

void dfs(int node,vector<int>& visited,vector<vector<int>>& adjList,vector<int>& order){
    visited[node]=1;
    for(auto it : adjList[node]) if(!visited[it]) dfs(it,visited,adjList,order);
    order.push_back(node);
}

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> adjList(n);
  vector<pair<int,int>> edges;

  for(int i=1;i<=m;i++){
    int x,u,v;
    cin>>x>>u>>v;
    u--;v--;
    if(x==1){
        adjList[u].push_back(v);
    }
    edges.push_back({u,v});
  }

  vector<int> order;
  vector<int> visited(n,0);
  
  // doing the dfs for finding the correct order
  // of the topo sort
  for(int i=0;i<n;i++){
    if(!visited[i]) dfs(i,visited,adjList,order);
  }

  reverse(order.begin(),order.end());

  vector<int> position(n);
  
  for(int i=0;i<n;i++) position[order[i]]=i;

  bool check = false;

  for(int i=0;i<n;i++){
    for(auto j : adjList[i]){
        if(position[i]>position[j]) {
            check = true;
            break;
        }
    }
  }

  if(check) {
    cout<<"NO\n";
    return;
  }

  cout<<"YES\n";

  for(int i=0;i<edges.size();i++){
     int u = edges[i].first;
     int v = edges[i].second;
     if(position[u]<position[v]){
       cout<<u+1<<" "<<v+1<<endl;
     }
     else cout<<v+1<<" "<<u+1<<endl;
  }
  

}

int main(){
    int t;cin>>t;
    while(t--) solve();


}