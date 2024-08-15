//https://www.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	bool cycle = false;
	vector<int> ans;
	void dfs(int node,vector<int>& instack,vector<int>& visited,vector<int> adj[]){
	    visited[node]=1;
	    instack[node]=1;
	    for(auto it : adj[node]){
	        if(!visited[it]) {
	            dfs(it,instack,visited,adj);
	        }
	        else{
	            if(instack[it]){
	                cycle = true;
	                return;
	            }
	        }
	    }
	    instack[node]=0;
	    ans.push_back(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> instack(V,0);
	    vector<int> visited(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i]) dfs(i,instack,visited,adj);
	        if(cycle) return {};
	    }
	    reverse(ans.begin(),ans.end());
	   // for(auto it : ans) cout<<it<<" ";
	    return ans;
	}
};