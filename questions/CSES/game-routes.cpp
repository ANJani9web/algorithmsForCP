//https://cses.fi/problemset/task/1681

#include<bits/stdc++.h>
using namespace std;

#define int long long int 

signed main(){
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> adjList[n+1];
    vector<int> indegree(n+1,0);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        indegree[y]++;
    }

    vector<int> topoSort;
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indegree[i]==0){
            q.push(i);
            topoSort.push_back(i);
        }
    }

    while(q.size()){
        int node = q.front();
        q.pop();
        for(auto it : adjList[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
                topoSort.push_back(it);
            }
        }
    }
    
    vector<int> reverseAdjList[n+1];
    for(int i=1;i<=n;i++){
        for(auto it : adjList[i]){
            reverseAdjList[it].push_back(i);
        }
    }

    vector<int> ans(n+1,0);
    int mod = 1e9 + 7;
    ans[1]=1;
    for(int i=0;i<topoSort.size();i++){
        int node = topoSort[i];
        for(auto it : reverseAdjList[node]){
            ans[node] = (ans[node]+ans[it])%mod;
        }
    }

    cout<<ans[n]<<endl;
}