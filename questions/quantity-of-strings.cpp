// https://codeforces.com/problemset/problem/150/B

#include<bits/stdc++.h>
using namespace std;

int findParent(int i,vector<int>& parent){
    if(i==parent[i]) return i;
    return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent){
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

int main(){
    long long int n,m,k;
    cin>>n>>m>>k;

    long long int mod = 1e9 + 7;
    long long int ans = 1;
    if(n==k){
        long long int chain = (k+1)/2;
        while(chain){
            ans = (ans * m)%mod;
            chain--;
        }
        cout<<ans<<endl;
    }
    else{
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i] = i;
        vector<int> rank(n,0);

        for(int i=0;i<(n-k+1);i++){
           int j1 = i;
           int j2 = i + k -1;
           while(j1<j2){
            int x = findParent(j1,parent);
            int y = findParent(j2,parent);
            if(x!=y) unionByRank(j1,j2,rank,parent);
            j1++;
            j2--;
           }
        }
        set<int> st;
        for(int i=0;i<n;i++) st.insert(findParent(parent[i],parent));
        // for(auto it : parent) cout<<it<<" ";
        // cout<<endl;
        // cout<<st.size()<<endl;
        int chain = st.size();
        while(chain){
            ans = (ans * m)%mod;
            chain--;
        }
        cout<<ans<<endl;
    }

}