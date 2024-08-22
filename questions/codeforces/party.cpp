#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<int> adjList[n+1];
    vector<int> indegree(n+1,0);
    for(int i=1;i<=n;i++){
      int x;cin>>x;
      if(x==-1) continue;
      adjList[x].push_back(i);
      indegree[i]++;
    }
    
    // second way of doing this
    queue<int> q;
    vector<int> topoSortedVector;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) {
            q.push(i);
            topoSortedVector.push_back(i);
        }
    }

    while(q.size()){
        int node = q.front();
        q.pop();
        for(auto it : adjList[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
                topoSortedVector.push_back(it);
            }
        }
    }

    vector<int> reversedAdjList[n+1];
    for(int i=1;i<=n;i++){
        for(auto it : adjList[i]){
            reversedAdjList[it].push_back(i);
        }
    }
    
    vector<int> dis(n+1,1);
    for(auto i : topoSortedVector){
       int maxi = 0;
       for(auto it : reversedAdjList[i]){
        maxi = max(dis[it],maxi);
       }
       dis[i] = maxi + 1;
    }

    cout<<*max_element(dis.begin(),dis.end())<<endl;
    
    // this is one of the method
    // int ans = 1;
    // vector<int> visited(n+1,0);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) visited[j]=0;
    //    if(visited[i]==0){
    //      int count = 0;
    //      queue<pair<int,int>> q;
    //      q.push({i,1});
    //      while(q.size()){
    //         int node = q.front().first;
    //         int level = q.front().second;
    //         count = max(count,level);
    //         q.pop();
    //         visited[node]=1;
    //         for(auto it : adjList[node]){
    //             if(!visited[it]) {
    //                 q.push({it,level+1});
    //             }
    //         }
    //      }
    //      ans = max(ans,count);
    //    }
    // }

    // cout<<ans<<endl;
}