//https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPossible(int index,int target,string str){
           if(index>=str.length()){
            return target==0;
           }
           int sum = 0;
           for(int i=index;i<str.length();i++){
             sum = sum * 10 +(str[i]-'0');
             if(sum>target) return false;
             if(isPossible(i+1,target-sum,str)) return true;
           }
           return false;
        }
    
        int punishmentNumber(int n) {
            int ans = 0;
            for(int i=1;i<=n;i++){
                int temp = i*i;
                string str;
                while(temp){
                    str.push_back('0'+(temp%10));
                    temp = temp/10;
                }
                // cout<<i<<" "<<str<<endl;
                reverse(str.begin(),str.end());
                //cout<<i<<" "<<str<<endl;
                if(isPossible(0,i,str)) {
                    cout<<i<<endl;
                    ans = ans + i*i;
                }
            }
            return ans;
        }
    };