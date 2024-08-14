// https://leetcode.com/problems/making-a-large-island/description/

#include<bits/stdc++.h>
using namespace std;


class Solution {

private:

int findParent(int i,vector<int>& parent){
    if(i==parent[i]) return i;
    return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent){
    i = findParent(i,parent);
    j = findParent(j,parent);
    if(i==j) return;
    if(rank[i]>rank[j]){
        rank[i]=rank[i]+rank[j];
        parent[j] = i;
    }
    if(rank[j]>rank[i]){
        rank[j] = rank[j]+rank[i];
        parent[i]=j;
    }
    if(rank[i]==rank[j]){
        rank[i] = rank[i] + rank[j];
        parent[j]=i;
    }
}

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> newGrid(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            int x = i*m;
            for(int j=0;j<m;j++){
                newGrid[i][j] = x;          
                x++;
            }
        }

        int total = n*m;
        vector<int> parent(total),rank(total,1);
        for(int i=0;i<total;i++) parent[i] = i;
         
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]){
                int node1 = i*m + j;
                for(int k=0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 and y>=0 and x<n and y<m and grid[x][y]){
                        int node2 = x*m + y;
                        if(findParent(node1,parent)!=findParent(node2,parent)){
                            unionByRank(node1,node2,rank,parent);
                        }
                    }
                }
              }
            }
        }
    
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x>=0 and y>=0 and x<n and y<m and grid[x][y]){
                            st.insert(findParent(x*m+y,parent));
                        }
                    }
                    int count = 1;
                    for(auto it : st){
                      count += rank[it];
                    }
                    ans = max(ans,count);
                }
                else{
                    ans = max(ans,rank[i*m+j]);
                }
            }
        }
        return ans;
    }
};