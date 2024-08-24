//https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// Important regarding SCC
// i) SCC -> part of the component in which we can go each pair nodes 
// ii) There is no effect on reversing the graph the SCC will remain the same
// iii) if there is an edge from node i to node j then the outTime of i > outTime of j (if it is undirected graph then inTime of i < inTime of j)
// iv) after decompositon of the graph it will be become DAG where the decomposition means clubing all the SCC nodes in one packet

// How to find SCC
// i) find the out time of each node
// ii) sort the nodes on the basis of the out time
// iii) do the dfs from each node of the new out time vector where when ever the nodes changes we are entering in a new SCC
// iv) a single node can be a SCC


#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	int time = 0;
	void findOutTime(int node,vector<pair<int,int>>& outTime,vector<vector<int>>& adj,vector<int>& visited){
	    visited[node]=1;
	    for(auto it : adj[node]){
	        if(visited[it]==0) {
	            time++;
	            findOutTime(it,outTime,adj,visited);
	        }
	    }
	    time++;
	    outTime[node] = {time,node};
	}
	
	void dfs(int node, vector<int>& visited,vector<vector<int>>& reverseAdj){
	    visited[node]=1;
	    for(auto it : reverseAdj[node]){
	        if(visited[it]==0) {
	            dfs(it,visited,reverseAdj);
	        }
	    }
	}
	
    int kosaraju(int v, vector<vector<int>>& adj){
        vector<pair<int,int>> outTime(v);  // first-> time, second->node
        vector<int> visited(v,0);
        
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                findOutTime(i,outTime,adj,visited);
            }
        }
        sort(outTime.rbegin(),outTime.rend());
        vector<vector<int>> reverseAdj(v);
        for(int i=0;i<v;i++){
            for(auto it : adj[i]) reverseAdj[it].push_back(i);
        }
        int ans = 0;
        for(int i=0;i<v;i++) visited[i]=0;
        for(int i=0;i<v;i++){
            int node = outTime[i].second;
            if(visited[node]==0){
                ans++;
                dfs(node,visited,reverseAdj);
            }
        }
        return ans;
    }
};

int main(){
    int t;cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<vector<int>> adj(v);

        for(int i=0;i<e;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
        }
    Solution obj;
    cout<<obj.kosaraju(v,adj)<<endl;
    }
}