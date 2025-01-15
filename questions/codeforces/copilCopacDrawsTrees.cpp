//https://codeforces.com/problemset/problem/1830/A

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<vector<int>> adjList(n);
    map<pair<int,int>,int> mp;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x>y) swap(x,y);
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        mp[{x,y}]=i;
    }

    vector<int> visited(n);
    queue<pair<int,pair<int,int>>> q; //{node,{index,visitedValue}}
    q.push({0,{0,1}});
    visited[0]=1;
    while(q.size()){
        int s = q.size();
        while(s--){
            int currentNode = q.front().first;
            int currentIndex = q.front().second.first;
            int currentVisitedValue = q.front().second.second;
            q.pop();
            for(auto it : adjList[currentNode]){
                int adjNode = it;
                if(visited[it]==0){
                  if(it>currentNode){
                     int nextIndex = mp[{currentNode,it}];
                     if(nextIndex>=currentIndex){
                        q.push({adjNode,{nextIndex,currentVisitedValue}});
                        visited[it] = currentVisitedValue;
                     }
                     else{
                        q.push({adjNode,{nextIndex,currentVisitedValue+1}});
                        visited[it] = currentVisitedValue+1;
                     }
                  }
                  else{
                      int nextIndex = mp[{it,currentNode}];
                     if(nextIndex>=currentIndex){
                        q.push({adjNode,{nextIndex,currentVisitedValue}});
                        visited[it]=currentVisitedValue;
                     }
                     else{
                        q.push({adjNode,{nextIndex,currentVisitedValue+1}});
                        visited[it]=currentVisitedValue+1;
                     }
                  }
                }
            }
        }
    }

    // for(int i=0;i<n;i++) cout<<visited[i]<<" ";
    // cout<<endl;
    cout<<*max_element(visited.begin(),visited.end())<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}