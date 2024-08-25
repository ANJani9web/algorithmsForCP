//https://cses.fi/problemset/task/1682

#include<bits/stdc++.h>
using namespace std;

int otime = 0;

void findOutTime(int node,vector<pair<int,int>>& outTime,vector<int>& visited,vector<int> adjList[]){
    visited[node]=1;
    for(auto it : adjList[node]){
        if(visited[it]==0){
            otime++;
            findOutTime(it,outTime,visited,adjList);
        }
    }
    otime++;
    outTime[node] = {otime,node};
}

void dfs(int node,vector<int>& visited,vector<int> reverseAdjList[],vector<int>& temp){
    visited[node]=1;
    temp.push_back(node);
    for(auto it : reverseAdjList[node]){
        if(visited[it]==0){
            dfs(it,visited,reverseAdjList,temp);
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> adjList[n];
    vector<int> reverseAdjList[n];

    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        adjList[x].push_back(y);
        reverseAdjList[y].push_back(x);
    }

    vector<pair<int,int>> outTime(n);
    vector<int> visited(n,0);

    for(int i=0;i<n;i++){
        if(visited[i]==0) findOutTime(i,outTime,visited,adjList);
    }

    sort(outTime.rbegin(),outTime.rend());
    // cout<<"node "<<" "<<"outTime "<<endl;
    // for(auto it : outTime){
    //    cout<<it.second<<" "<<it.first<<endl;
    // }
    for(int i=0;i<n;i++) visited[i]=0;

    vector<vector<int>> store;

    for(int i=0;i<outTime.size();i++){
        int node = outTime[i].second;
        if(visited[node]==0){
          vector<int> temp;
          dfs(node,visited,reverseAdjList,temp);
          store.push_back(temp);
        }
    }

    if(store.size()==1) cout<<"YES\n";
    else{
      cout<<"NO\n";
      cout<<store[1][0]+1<<" "<<store[0][0]+1<<endl;
    }
}