//https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n&1) return false;
        stack<int> unLocked,openBrackets;
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0') unLocked.push(i);
            else if(s[i]=='(') openBrackets.push(i);
            else if(s[i]==')'){
                if(openBrackets.size()) openBrackets.pop();
                else if(unLocked.size()) unLocked.pop();
                else return false;
            }
        }

        while(openBrackets.size() and unLocked.size()){
            if(openBrackets.top()<unLocked.top()) {
                openBrackets.pop();
                unLocked.pop();
            }
            else return false;
        }

        if(openBrackets.size()) return false;

        return true;
    }
};