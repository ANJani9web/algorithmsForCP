//https://codeforces.com/problemset/problem/1106/D

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    vector<int> visited(n+1,0);
    visited[1]=1;
    vector<int> ans;
    while(pq.size()){
        int t = pq.top();
        pq.pop();
        ans.push_back(t);
        for(auto it : adjList[t]){
            if(visited[it]==0){
                visited[it]=1;
                pq.push(it);
            }
        }
    }
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
}