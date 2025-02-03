//https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        int n = startTime.size();
        gaps.push_back(startTime[0]);
        for(int i=0;i<n-1;i++){
          gaps.push_back(startTime[i+1]-endTime[i]);
        }
        gaps.push_back(eventTime-endTime[n-1]);
        
        vector<int> maxRight(gaps.size(),0);
        vector<int> maxLeft(gaps.size(),0);

        for(int i=2;i<gaps.size();i++){
            maxLeft[i] = max(maxLeft[i-1],gaps[i-2]);
        }

        for(int i=gaps.size()-2;i>=0;i--){
            maxRight[i] = max(maxRight[i+1],gaps[i+1]);
        }
        int ans = 0;
        for(int i=1;i<gaps.size();i++){
            int size = endTime[i-1] - startTime[i-1];
            if(size<=maxLeft[i] or size<=maxRight[i]){
                ans = max(ans,size+gaps[i-1]+gaps[i]);
            }
            else ans = max(ans,gaps[i-1]+gaps[i]);
        }

        return ans;
    }
};