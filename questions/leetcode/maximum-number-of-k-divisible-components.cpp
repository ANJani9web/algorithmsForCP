//https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    void dfs(vector<vector<int>>& adjList,vector<int>& parents,int node,int parent,vector<int>& visited){
        visited[node]=1;
        parents[node] = parent;
        for(auto it : adjList[node]){
            if(visited[it]==0){
                dfs(adjList,parents,it,node,visited);
            }
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> parents(n,-1);
        vector<int> degree(n,0);
        vector<vector<int>> adjList(n);
        for(int i=0;i<n-1;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++) degree[i]=adjList[i].size();
        dfs(adjList,parents,0,-1,visited);
        // for(auto it : degree) cout<<it<<" ";cout<<endl;
        // for(auto it : parents) cout<<it<<" ";
        // cout<<endl;
        // return 2;
        vector<long long> v(n);
        for(int i=0;i<n;i++) v[i]=values[i];
        queue<int> q;
        int numberOfComponents = 0;
        for(int i=0;i<n;i++){
            if(degree[i]==1 and i!=0) q.push(i);
            visited[i]=0;
        }
        parents[0]=0;
        while(q.size()){
            int node = q.front();
            cout<<"Node value is : "<<node<<endl;
            q.pop();
            if(node==0) continue;
            long long  value = v[node];
            int parent = parents[node];
            //if(parent)
            if(value%k==0){
                numberOfComponents++;
                degree[parent]--;
                if(degree[parent]==1) q.push(parent);
            }
            else{
                degree[parent]--;
                v[parent]+=value;
                if(degree[parent]==1) q.push(parent);
            }
        }
        numberOfComponents++;
        return numberOfComponents;
    }
};

// another way also
class Solution2 {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0) componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};