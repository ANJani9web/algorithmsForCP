// https://codeforces.com/problemset/problem/1559/D1

#include<bits/stdc++.h>
using namespace std;

int findParent(int i,vector<int>& parent){
   if(i==parent[i]) return parent[i] = i;
   return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent){
    int x = findParent(i,parent);
    int y = findParent(j,parent);
    if(x==y) return;
    if(rank[x]>rank[y]){
        parent[y] = x;
    }
    else if(rank[x]<rank[y]){
        parent[x] = y;
    }
    else {
        rank[x]++;
        parent[y] = x;
    }
}

int main(){
    int n;cin>>n;
    vector<int> parentForMocha(n+1);
    vector<int> parentForDiana(n+1);

    for(int i=1;i<=n;i++) parentForDiana[i] = i;
    for(int i=1;i<=n;i++) parentForMocha[i]=i;

    vector<int> rankForMocha(n+1,1);
    vector<int> rankForDiana(n+1,1);
    
    int m1,m2;
    cin>>m1>>m2;

    for(int i=1;i<=m1;i++){
        int u,v;cin>>u>>v;
        int x = findParent(u,parentForMocha);
        int y = findParent(v,parentForMocha);
        if(x!=y) unionByRank(u,v,rankForMocha,parentForMocha);
    }

    for(int i=1;i<=m2;i++){
        int u,v;cin>>u>>v;
        int x = findParent(u,parentForDiana);
        int y = findParent(v,parentForDiana);
        if(x!=y) unionByRank(u,v,rankForDiana,parentForDiana);
    }

    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x1 = findParent(i,parentForMocha);
            int y1 = findParent(j,parentForMocha);

            int x2 = findParent(i,parentForDiana);
            int y2 = findParent(j,parentForDiana);

            if(x1!=y1 and x2!=y2){
                unionByRank(i,j,rankForDiana,parentForDiana);
                unionByRank(i,j,rankForMocha,parentForMocha);
                ans.push_back({i,j});
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto it : ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

}