// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C


#include<bits/stdc++.h>
using namespace std;

int findParent(int i,vector<int>& parent){
    if(i==parent[i]) return i;
    return findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent,vector<int>& score){
    int x = findParent(i,parent);
    int y = findParent(j,parent);

    if(x==y) return;

    if(rank[x]>rank[y]){
        parent[y] = x;
        score[y] -= score[x];
    }
    else if(rank[y]>rank[x]){
        parent[x] = y;
        score[x] -= score[y];
    }
    else {
        rank[x]++;
        parent[y] = x;
        score[y] -= score[x];
    }
}

int main(){
    int nodes,queries;
    cin>>nodes>>queries;

    vector<int> parent(nodes+1);
    for(int i=1;i<=nodes;i++) parent[i]=i;
    vector<int> rank(nodes+1,1);
    vector<int> score(nodes+1,0);

    for(int i=1;i<=queries;i++){
        string str;
        cin>>str;
        if(str=="add"){
            int node,points;
            cin>>node>>points;
            score[findParent(parent[node],parent)]+=points;
        }
        else if(str=="join"){
            int node1,node2;cin>>node1>>node2;
            unionByRank(node1,node2,rank,parent,score);
        }
        else{
            int node;
            cin>>node;
            int ans = 0;
            while(parent[node]!=node){
               ans += score[node];
               node = parent[node];
            }
            ans += score[node];
            cout<<ans<<endl;
        }
    }

}