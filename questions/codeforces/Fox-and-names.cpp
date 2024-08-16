//https://codeforces.com/problemset/problem/510/C

#include<bits/stdc++.h>
using namespace std;

bool isCycle = false;

void dfs(int node,vector<int>& visited,vector<int>& inStack,vector<int> adjList[]){
    visited[node]=1;
    inStack[node]=1;

    for(auto it : adjList[node]){
        if(!visited[it]) dfs(it,visited,inStack,adjList);
        else{
            if(inStack[it]){
                isCycle = true;
                return;
            }
        }
    }
    inStack[node]=0;
}

void solve(){
    int n;cin>>n;
    vector<string> store(n);
    for(int i=0;i<n;i++) cin>>store[i];
    // a b c d e f 
    // 0 1 2 3 4 5

    vector<int> adjList[26];
    vector<int> indegree(26,0);
    for(int i=0;i<n-1;i++){
        string str1 = store[i];
        string str2 = store[i+1];
        int j=0,k=0;
        bool check = false;
        while(j<str1.length() and k<str2.length()){
            if(str1[j]!=str2[k]){
                adjList[str1[j]-'a'].push_back(str2[k]-'a');
                indegree[str2[k]-'a']++;
                check = true;
                break;
            }
            j++;
            k++;
        }
        if(check) continue;
        else{
            if(str1.length()>str2.length()){
                cout<<"Impossible\n";
                return;
            }
        }
    }
    
    vector<int> visited(26,0);
    vector<int> inStack(26,0);
    
    bool check = false;
    for(int i=0;i<26;i++){
        if(!visited[i]) dfs(i,visited,inStack,adjList);
        if(isCycle){
            cout<<"Impossible\n";
            check = true;
            break;
        }
    }

    if(!check){
        for(int i=0;i<26;i++) visited[i]=0;
        queue<int>  q;
        for(int i=0;i<26;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(q.size()){
            int node = q.front();
            q.pop();
            visited[node] = 1;
            ans.push_back(node);
            for(auto it : adjList[node]){
                indegree[it]--;
                if(indegree[it]==0){
                  q.push(it);
                }
            }
        }

        for(auto it : ans) cout<<char(it+'a');
        for(int i=0;i<26;i++){
            if(visited[i]==0) cout<<char(i+'a');
        }
        cout<<endl;
    }
}

int main(){
    solve();
}