//https://cses.fi/problemset/task/1674

#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj,vector<int>& ans,int node){
    int x = 0;
   for(auto it : adj[node]){
    x = x + dfs(adj,ans,it);
    //cout<<node<<" "<<dfs(adj,ans,it)<<endl;
   }
   return ans[node] = x + adj[node].size();
}

int main(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int x;cin>>x;
        x--;
        adj[x].push_back(i);
    }

    vector<int> ans(n,0);
    dfs(adj,ans,0);
    for(auto it : ans) cout<<it<<" ";
}