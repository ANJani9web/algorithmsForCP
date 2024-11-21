//https://codeforces.com/contest/1006/problem/E

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent,vector<vector<int>>& adjList,vector<int>& store,vector<int>& numberOfSubCoordinates){
    store.push_back(node);
    int x = 0;
    for(auto it : adjList[node]){        
        dfs(it,node,adjList,store,numberOfSubCoordinates);
        x = x + numberOfSubCoordinates[it];
    }
    numberOfSubCoordinates[node] = x + 1;
    //cout<<"Node : "<<node<<" and the value of x:  "<<x<<endl;
}

int main(){
    int n;cin>>n;
    int queries;cin>>queries;

    vector<vector<int>> adjList(n+1);

    for(int i=2;i<=n;i++){
        int x;cin>>x;
        adjList[x].push_back(i);
    }
    
    vector<int> store;
    vector<int> numberOfCoordinates(n+1,0);
    dfs(1,0,adjList,store,numberOfCoordinates);

    map<int,int> mp;
    for(int i=0;i<store.size();i++) {
        mp[store[i]]=i;
    }

    for(int i=0;i<queries;i++){
        int u,k;cin>>u>>k;
        int index = mp[u];
        int newIndex = index + k -1;
        if(k<=numberOfCoordinates[u]) cout<<store[newIndex]<<endl;
        else cout<<-1<<endl;
    }

    //for(auto it : numberOfCoordinates) cout<<it<<" ";cout<<endl;
}
