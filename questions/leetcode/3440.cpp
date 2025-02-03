//https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0,sum = 0;
        int n = startTime.size();
        vector<int> store;
        store.push_back(startTime[0]);
        for(int i=0;i<n-1;i++){
            store.push_back(startTime[i+1]-endTime[i]);
        }
        store.push_back(eventTime-endTime[n-1]);

        for(int i=0;i<store.size();i++){
            if(i<=k) sum = sum + store[i];
            else sum = sum + store[i] - store[i-k-1];
            ans = max(sum,ans);
        }
        return ans;
    }
};