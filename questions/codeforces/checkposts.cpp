//https://codeforces.com/problemset/problem/427/C
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int otime = 0;

void findOutTime(int node,vector<int>& visited,vector<pair<int,int>>& outTime,vector<vector<int>>& adjList){
    visited[node]=1;
    for(auto it : adjList[node]){
        if(visited[it]==0){
            otime++;
            findOutTime(it,visited,outTime,adjList);
        }
    }
    otime++;
    outTime[node] = {otime,node};
}

void dfs(int node,vector<int>& visited,vector<int>& vec,vector<int>& cost,int& lowestCost,vector<vector<int>>& adjList){
   visited[node]=1;
   vec.push_back(node);
   lowestCost = min(lowestCost,cost[node]);
   for(auto it : adjList[node]){
        if(visited[it]==0) dfs(it,visited,vec,cost,lowestCost,adjList);
   }
}

signed main(){
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;

    vector<int> cost(n+1,0);
    for(int i=1;i<=n;i++) {
        cin>>cost[i];
    }

    int m;cin>>m;
    vector<vector<int>> adjList(n+1);
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        adjList[x].push_back(y);
    }

    vector<pair<int,int>> outTime(n+1);
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++){
       if(visited[i]==0) findOutTime(i,visited,outTime,adjList);
    }
    
    sort(outTime.rbegin(),outTime.rend());
    //for(auto it : outTime) cout<<it.first<<" "<<it.second<<endl;
    
    vector<vector<int>> reverseAdj(n+1);
    for(int i=1;i<=n;i++) for(auto it : adjList[i]) reverseAdj[it].push_back(i);
    int totalCost = 0;
    int totalWays = 1;
    int mod = 1e9 + 7;

    for(int i=1;i<=n;i++) visited[i]=0;

    for(int i=0;i<outTime.size();i++){
        int node = outTime[i].second;
        int lowestCost = INT_MAX;
        vector<int> vec;
        if(visited[node]==0){
           dfs(node,visited,vec,cost,lowestCost,reverseAdj);
        
        int count = 0;
        for(int j=0;j<vec.size();j++){
            int node = vec[j];
            if(lowestCost==cost[node]) count++;
        }
        totalWays = (totalWays*count)%mod;
        totalCost += lowestCost;
        }
    }
    cout<<totalCost<<" "<<totalWays<<endl;
}