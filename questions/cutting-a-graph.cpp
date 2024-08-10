// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

#include<bits/stdc++.h>
using namespace std;

int findParent(int i,vector<int>& parent){
    if(i==parent[i]) return parent[i] = i;
    return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent){
    i = findParent(i,parent);
    j = findParent(j,parent);
    if(i==j) return;

    if(rank[i]>rank[j]){
        parent[j] = i;
    }
    if(rank[j]>rank[i]){
        parent[i] = j;
    }
    if(rank[i]==rank[j]){
        rank[i]++;
        parent[j] = i;
    }
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    set<pair<int,int>> edges;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;   // putting x smaller and y  bigger
        if(x>y) swap(x,y);
        edges.insert({x,y});
    }

    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) parent[i] = i;

    vector<int> rank(n+1,1);
    
    vector<pair<string,pair<int,int>>> store;
    for(int i=1;i<=k;i++){
        string str;
        int u,v;
        cin>>str>>u>>v;
        if(u>v) swap(u,v);
        store.push_back({str,{u,v}});
    }

    reverse(store.begin(),store.end());
    vector<string> ans;
    
    for(int i=0;i<k;i++){
        string str = store[i].first;
        int u = store[i].second.first;
        int v = store[i].second.second;

        if(str=="ask"){
            int x = findParent(u,parent);
            int y = findParent(v,parent);
            if(x==y) ans.push_back("YES");
            else ans.push_back("NO");
        }
        else{
            if(edges.count({u,v}))
            unionByRank(u,v,rank,parent);
        }
    }

    reverse(ans.begin(),ans.end());
    for(auto it : ans) {
        cout<<it<<endl;
    }

}