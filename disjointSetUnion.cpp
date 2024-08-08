// Implement disjont sets union data structure. You have to perform queries of two types:

//     union u v — unite two sets that contain u and v, respectively;
// get u v — check that two elements u and v belong to the same set. 

// Input

// The first line of the input contains two integers n and m (1≤n,m≤105) — the number of elements and the number of queries. Next m lines contain queries, one per line. 
// For a query union the line looks like union u v (1≤u,v≤n). For a query get the line looks like get u v (1≤u,v≤n ).
// Output

// Output the result of each query get one per line in the respected order: "YES", if the elements belong to the same set, and "NO", otherwise.

#include<bits/stdc++.h>
using namespace std;

int findParent(int i,vector<int>& parent){
    if(i==parent[i]) return parent[i]=i;

    return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent){
   int x = findParent(i,parent);
   int y = findParent(j,parent);
   if(x==y) return;

   if(rank[x]>rank[y]){
    parent[y] = parent[x];
    return;
   }
   if(rank[y]>rank[x]){
    parent[x] = parent[y];return;
   }
   if(rank[x]==rank[y]){
    rank[x]++;
    parent[y] = parent[x];
   }
   
}

void unionBySize(int i,int j,vector<int>& size,vector<int>& parent){
   int x = findParent(i,parent);
   int y = findParent(j,parent);
   if(x==y) return;

   if(size[x]>=size[y]){
    parent[y] = parent[x];
    size[x] += size[y];
   }
   else{
    parent[x]=parent[y];
    size[y]+=size[x];
   }
}

int main(){
    int elements,queries;
    cin>>elements>>queries;

    vector<int> parent(elements+1);
    for(int i=1;i<=elements;i++) parent[i]=i;

    vector<int> rank(elements+1,1);
    vector<int> size(elements+1,1);

    for(int i=1;i<=queries;i++){
        string str;
        int u,v;
        cin>>str>>u>>v;
        if(str=="union"){
            //unionByRank(u,v,rank,parent);
            unionBySize(u,v,size,parent);
        }
        else{
          int x = findParent(u,parent);
          int y = findParent(v,parent);
          if(x==y) cout<<"YES\n";
          else cout<<"NO\n";
        }
    }

}