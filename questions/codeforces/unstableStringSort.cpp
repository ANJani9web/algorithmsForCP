#include<bits/stdc++.h>
using namespace std;

int currentTime = 0;

void findOutTimeForEachNode(int node,vector<int>& visited,vector<pair<int,int>>& outTime,vector<vector<int>>& adjList){
    visited[node]=1;
    for(auto it:adjList[node]){
        
        if(!visited[it]) {
            currentTime++;
            findOutTimeForEachNode(it,visited,outTime,adjList);
        }
    }
    currentTime++;
    outTime[node] = {currentTime,node};
}
int ans = 0;
void dfs(int node,vector<int>& visited,vector<vector<int>>& reverseAdjList,vector<int>& temp){
    visited[node]=1;
    temp.push_back(node);
    for(auto it: reverseAdjList[node]) if(visited[it]==0) dfs(it,visited,reverseAdjList,temp);
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<vector<int>> adjList(n);
    int last = -1,current = -1;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        x--;
        if(i==0) {
            last = x;
        }
        else{
            adjList[last].push_back(x);
            last = x;
        }
    }

    for(int i=0;i<n;i++){
        int x;cin>>x;x--;
        if(i==0){
            last = x;
        }
        else{
            adjList[last].push_back(x);
            last = x;
        }
    }

    // let us count the number of the connected components
    vector<pair<int,int>> outTime(n);
    vector<int> visited(n,0);

    for(int i=0;i<n;i++){
      if(!visited[i]) findOutTimeForEachNode(i,visited,outTime,adjList);
    }

    //for(int i=0;i<n;i++) cout<<"The node is "<<outTime[i].second<<" and the corresponding outTime is: "<<outTime[i].first<<endl;

    sort(outTime.rbegin(),outTime.rend());

    vector<vector<int>> reverseAdjList(n);
    for(int i=0;i<n;i++){
        for(auto j : adjList[i]) reverseAdjList[j].push_back(i);
    }

    // for(int i=0;i<n;i++){
    //     cout<<"The node is : "<<i<<" ";
    //     cout<<"And the neighbours are: ";
    //     for(auto it: reverseAdjList[i]) cout<<it<<" ";
    //     cout<<endl;
    // }

    vector<vector<int>> connectedComponents;

    // let us do dfs from the nodes on the basis of the sorted outtime in decreasing
    for(int i=0;i<n;i++) visited[i]=0;

    for(int i=0;i<n;i++){
        int node = outTime[i].second;
        vector<int> temp;
        if(visited[node]==0){
            dfs(node,visited,reverseAdjList,temp);
            if(temp.size()>0) connectedComponents.push_back(temp);
            // cout<<"The current Node is: "<<i<<" and the neighbours are: ";
            // for(auto it: temp) cout<<it<<" ";
            // cout<<endl;
            temp.clear();
        }
    }

    // for(int i=0;i<connectedComponents.size();i++){
    //     cout<<"Connected component number is : "<<i<<" ";
    //     cout<<"And the connectedComponets elements that are present is: ";
    //     for(auto it : connectedComponents[i]) cout<<it<<" ";
    //     cout<<endl;
    // }

    if(connectedComponents.size()<k) cout<<"NO\n";
    else{
        string ans(n,'.');
        for(int i=0;i<connectedComponents.size();i++){
            char c = 'a';
            c += min(i,k-1);
            for(int j=0;j<connectedComponents[i].size();j++){
                ans[connectedComponents[i][j]]=c;
            }
        }
        	cout<<"YES"<<endl;
	cout<<ans<<endl;
    }
}