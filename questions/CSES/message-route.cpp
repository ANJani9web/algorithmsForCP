//https://cses.fi/problemset/task/1667

#include<bits/stdc++.h>
using namespace std;

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
    vector<int> parent(n,-1);
    vector<int> distance(n,1e8);
    queue<int> q;
    distance[0]=0;
    q.push(0);
    while(q.size()){
        int node = q.front();
        visited[node]=1;
        q.pop();
        for(auto it : adjList[node]){
            if(visited[it]==0){
                distance[it] = min(distance[it],1+distance[node]);
                parent[it]=node;
                visited[it]=1;
                q.push(it);
            }
        }
    }
    if(distance[n-1]==1e8) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    int x = n-1;
    while(x!=-1){
        ans.push_back(x+1);
        x = parent[x];
    }
    cout<<ans.size()<<endl;
    while(ans.size()){
        cout<<ans.back()<<" ";
        ans.pop_back();
    }
}