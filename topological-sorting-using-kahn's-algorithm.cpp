//https://www.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++) {
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(q.size()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    return ans;
	}
};