//https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> adjList(n); // node, weight
        for(auto it : edges){
            int node1 = it[0];
            int node2 = it[1];
            int cost = it[2];
            adjList[node2].push_back({node1,cost});
        }

        vector<int> visited(n,0);
        vector<int> degree(n,0);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); // weight = 0, node =1;
        
        int ans = INT_MIN;
        while(pq.size()){
            int node = pq.top().second;
            int weight = pq.top().first;
            // visited[node]++;
            pq.pop();
            if(visited[node]) continue;

            if(degree[node]<threshold){
                degree[node]++;
                ans = max(ans,weight);
                visited[node]=1;
            }
            else continue;

            for(auto it : adjList[node]){
               int adjNode = it.first;
               int cost = it.second;
               if(visited[adjNode]==0) pq.push({cost,adjNode});
            }
            
        }
        for(int i=0;i<n;i++) if(visited[i]==0) {
            return -1;
        }
        return ans;
    }
};