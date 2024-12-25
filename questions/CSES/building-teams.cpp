//https://cses.fi/problemset/task/1668

#include<bits/stdc++.h>
using namespace std;

bool check = false;
void dfs(int child,int parent,vector<vector<int>>& adjList,vector<int>& visited,int color){
    visited[child]=color;
    if(check) return;
    for(auto it : adjList[child]){
        if(visited[it]==0){
          if(color==1) dfs(it,child,adjList,visited,2);
          else dfs(it,child,adjList,visited,1);
        }
        else {
          if(it!=parent and parent!=-1 and visited[it]==visited[child]) check = true;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjList(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        check = false;
        if(visited[i]==0) dfs(i,-1,adjList,visited,1);
        if(check==true){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for(auto it : visited) cout<<it<<" ";
    cout<<endl;

}