//https://leetcode.com/problems/zigzag-grid-traversal-with-skip/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();
        int i=0,j=0;
        bool right = true;
        for(int row = 0;row<n;row++){
            if(right){
                for(int j=0;j<m;j=j+2){
                    ans.push_back(grid[row][j]);
                }
            }
            else {
                int end = 0;
                if(m%2==1) end = m-2;
                else end = m-1;
                while(end>=0){
                    ans.push_back(grid[row][end]);
                    end = end -2;
                }
            }
            right = !right;
        }
        return ans;
    }
};