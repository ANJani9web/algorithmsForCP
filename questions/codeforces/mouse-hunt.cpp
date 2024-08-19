//https://codeforces.com/contest/1027/problem/D

#include<bits/stdc++.h>
using namespace std;

void solve(){
   int n;cin>>n;
   vector<int> settingCost(n+1,0);
   for(int i=1;i<=n;i++) cin>>settingCost[i];
   vector<int> nextRoom(n+1,0);
   vector<int> indegree(n+1,0);
   vector<int> adjList[n+1];
   vector<int> outdegree(n+1,1);
   for(int i=1;i<=n;i++) {
    int x;
    cin>>x;
    nextRoom[i]=x;
    adjList[i].push_back(x);
    indegree[x]++;
   }

   vector<int> visited(n+1,0);
   
   queue<int> q;
   for(int i=1;i<=n;i++) {
    if(indegree[i]==0) q.push(i);
   }

   while(q.size()){
    int currentNode = q.front();
    q.pop();
    visited[currentNode]=1;
    for(auto it : adjList[currentNode]){
        indegree[it]--;
        if(indegree[it]==0) q.push(it);
    }
   }

   int ans = 0;
   for(int i=1;i<=n;i++){
    if(visited[i]==0){
       int cost = settingCost[i];
       visited[i]=1;
       queue<int> q;
       q.push(i);
       while(q.size()){
        int node = q.front();
        q.pop();
        visited[node]=1;
        for(auto it : adjList[node]){
            if(visited[it]==0){
                q.push(it);
                cost = min(cost,settingCost[it]);
            }
        }
       }
       ans += cost;
    }
   }
   cout<<ans<<endl;

}

int main(){
  solve();
}