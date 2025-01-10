//https://leetcode.com/problems/word-subsets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> frequencyOfAlphabets(26,0);

        for(auto it : words2){
            int count[26]={0};
            for(auto i : it){
                int c = i - 'a';
                count[c]++;
                frequencyOfAlphabets[c]=max(frequencyOfAlphabets[c],count[c]);
            }
        }

        for(auto it : words1){
            int count[26]={0};
            for(auto i : it){
                count[i-'a']++;
            }
            for(int i=0;i<=26;i++){
                if(i==26){
                    ans.push_back(it);
                    break;
                }
                if(count[i]<frequencyOfAlphabets[i]) break;
            }
        }

        return ans;


    }
};