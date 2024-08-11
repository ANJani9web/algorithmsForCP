// https://cses.fi/problemset/task/1675

#include<bits/stdc++.h>
using namespace std;

int findParent(int i,vector<int>& parent){
    if(parent[i]==i) return parent[i]=i;
    return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent){
    i = findParent(i,parent);
    j = findParent(j,parent);

    if(i==j) return;

    if(rank[i]>rank[j]){
        parent[j] = i;
    }
    if(rank[j]>rank[i]) parent[i] = j;
    else{
        rank[i]++;
        parent[j] = i;
    }
}

int main(){
    int n,m;cin>>n>>m;

    vector<pair<long long,pair<long long,long long>>> edges;
    for(int i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }

    sort(edges.begin(),edges.end());

    vector<int> parents(n+1);
    for(int i=1;i<=n;i++) parents[i]=i;
    vector<int> rank(n+1,1);
    
    long long ans = 0;
    
    for(int i=0;i<edges.size();i++){
        long long w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(findParent(u,parents)!=findParent(v,parents)){
            ans += w;
            unionByRank(u,v,rank,parents);
        }
    }

    bool bo = true;
    int count = 0;
    for(int i=1;i<=n;i++){
        if(i==parents[i]) count++;
    }

    if(count==1){
        cout<<ans<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
}