//https://cses.fi/problemset/task/1680

#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;

    vector<int> adjList[n+1];
    vector<int> parent(n+1,-1);
    parent[1]=0;
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

    vector<int> dis(n+1,INT_MIN);
    dis[1]=1;

    for(int i=0;i<topoSort.size();i++){
        int node = topoSort[i];
        for(auto it : reverseAdjList[node]){
            if(dis[node]<dis[it]+1){
                dis[node] = dis[it] + 1;
                parent[node]=it;
            }
        }
    }

    int node = n;
    vector<int> ans;
    while(node!=0 and node!=-1){
        ans.push_back(node);
        node = parent[node];
    }

    if(node==-1) {
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

}