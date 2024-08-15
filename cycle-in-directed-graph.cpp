//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check = false;
    
    void dfs(int node,int parent,vector<int>& visited,vector<int> adj[],vector<int>& instack){
        visited[node]=1;
        instack[node]=1;
        for(auto it : adj[node]){
            if(!visited[it]) dfs(it,node,visited,adj,instack);
            else{
                if(instack[it]) {
                    check = true;
                    return;
                }
            }
        }
        instack[node]=0;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> instack(V,0);
        // instack[i] means 1 means that one path is going and 0 means that
        // the dfs has lost its control
        for(int i=0;i<V;i++){
            dfs(i,-1,visited,adj,instack);
            if(check) return true;
        }
        return false;
    }
};