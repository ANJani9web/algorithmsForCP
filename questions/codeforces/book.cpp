//https://codeforces.com/contest/1573/problem/C

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>& adjList,vector<int>& visited,vector<int>& temp,vector<int>& indegree){
    visited[node]=1;
    for(auto it: adjList[node]){
        if(visited[it]) continue;
        indegree[it]--;
        if(indegree[it]==0){
            visited[it]=1;
            if(it<node) temp.push_back(it);
            dfs(it,adjList,visited,temp,indegree);
        }
    }
}

void solve(){
  int n;cin>>n;
    vector<vector<int>> adjList(n+1);
    vector<int> indegree(n+1,0);
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        indegree[i]+=k;
        while(k--){
            int x;cin>>x;
            adjList[x].push_back(i);
        }
    }

    // first method
    set<int>st;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) st.insert(i);
    }

    int ans = 0;
        set<int> done;
		while(st.size()) {
			ans++;
 
			set<int> del;
 
			for(auto x: st) {
				done.insert(x);
				del.insert(x);
				for(auto y: adjList[x]) {
					indegree[y]--;
					if(indegree[y]==0) {
						st.insert(y);
					}
				}
			}
 
			for(auto x: del) st.erase(x);
		}
 
		if(done.size()==n) cout<<ans<<endl;
		else cout<<-1<<endl;

    // second method using toposort
    
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}