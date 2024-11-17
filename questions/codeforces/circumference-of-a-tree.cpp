//https://codeforces.com/gym/102694/problem/A

#include<bits/stdc++.h>
using namespace std;

void dfs(int child,int parent,vector<vector<int>>& adj,vector<int>& visited,vector<int>& distance){
    visited[child]=1;
    distance[child] = 1 + distance[parent];
    for(auto it : adj[child]){
        if(it!=parent){
            dfs(it,child,adj,visited,distance);
        }
    }
}

int main(){
    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        //x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> visited(n+1,0);
    vector<int> distance(n+1,0);
    dfs(1,0,adj,visited,distance);
    // for(int i=1;i<=n;i++){
    //     cout<<"Distance of "<<i<<" from 1 : "<<distance[i]<<endl;
    // }

    int node = 0;
    int dis = INT_MIN;
    for(int i=1;i<=n;i++){
        if(distance[i]>dis) {
            node = i;
            dis = distance[i];
        }
    }

    for(int i=0;i<=n;i++) visited[i]=0,distance[i]=0;

    dfs(node,0,adj,visited,distance);

    cout<<3 *( *max_element(distance.begin(),distance.end()) - 1)<<endl;

}