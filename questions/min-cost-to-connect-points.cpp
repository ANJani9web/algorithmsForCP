//https://leetcode.com/problems/min-cost-to-connect-all-points/description/

class Solution {
public:

    int findParent(int i,vector<int>& parent){
        if(i==parent[i]) return i;
        return parent[i] = findParent(parent[i],parent);
    }

    void unionByRank(int i,int j,vector<int>& rank,vector<int>&parent){
        i = findParent(i,parent);
        j = findParent(j,parent);

        if(i==j) return;
        if(rank[i]>rank[j]){
            parent[j] = i;
        }

        if(rank[j]>rank[i]){
            parent[i] = j;
        }
        else {
            rank[i]++;
            parent[j] = i;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<n;j++){
               int x2 = points[j][0];
               int y2 = points[j][1];
               int cost = abs(x1-x2) + abs(y1-y2);
               pq.push({cost,{i,j}});
            }
        }

        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<int> rank(n,0);
        
        int ans = 0;

        while(pq.size()){
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int node1 = it.second.first;
            int node2 = it.second.second;
            if(findParent(node1,parent)!=findParent(node2,parent)){
                ans += cost;
                unionByRank(node1,node2,rank,parent);
            }
        }
        
        return ans;
    }
};