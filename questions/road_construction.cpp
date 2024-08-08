// https://cses.fi/problemset/task/1676/
#include<bits/stdc++.h>
using namespace std;

int ans = 1;
int findParent(int i,vector<int>& parent){
    if(i==parent[i]) return parent[i]=i;
    return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& size,vector<int>& parent){
    int x = findParent(i,parent);
    int y = findParent(j,parent);
    
    if(x==y) return;

    if(rank[x]>rank[y]){
        parent[y] = x;
        size[x] += size[y];
        ans = max(ans,size[x]);
    }
    else if(rank[x]<rank[y]){
        parent[x] = y;
        size[y] += size[x];
        ans = max(ans,size[y]);
    }
    else{
        rank[x]++;
        parent[y] = x;
        size[x] += size[y];
        ans = max(ans,size[x]);
    }

}

int main(){
    int n;cin>>n;
    vector<int> parent(n+1);
    vector<int> size(n+1,1);
    vector<int> rank(n+1,1);
    
    int m; cin>>m;
    for(int i=1;i<=n;i++) parent[i] = i;

    int components = n;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        
        if(findParent(u,parent)!=findParent(v,parent)){
            components--;
            unionByRank(u,v,rank,size,parent);
        }

        cout<<components<<" "<<ans<<endl;
    }
}