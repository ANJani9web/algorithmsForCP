//https://codeforces.com/problemset/problem/1985/H1

#include<bits/stdc++.h>
using namespace std;

int findParent(int i,vector<int>& parent){
    if(i==parent[i]) return parent[i]=i;
    return parent[i] = findParent(parent[i],parent);
}

void unionByRank(int i,int j,vector<int>& rank,vector<int>& parent){
    i = findParent(i,parent);
    j = findParent(j,parent);

    if(rank[i]>=rank[j]){
        rank[i] += rank[j];
        parent[j] = i;
    }
    if(rank[i]<rank[j]){
        rank[j] += rank[i];
        parent[i] = j;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>grid[i][j];
    }
    
    vector<int> parent(n*m,0),rank(n*m,1);
    int ans = 0;
    for(int i=0;i<n*m;i++) parent[i] = i;

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#'){
                int node1 = i*m + j;
                for(int k=0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x<n and x>=0 and y<m and y>=0 and grid[x][y]=='#'){
                        int node2 = x*m + y;
                        if(findParent(node1,parent)!=findParent(node2,parent)) unionByRank(node1,node2,rank,parent);
                    }
                }
            }
        }
    }
    
    set<int> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]=='#'){
            st.insert(findParent(i*m+j,parent));
           }
        }
    }

    for(auto it : st) ans = max(ans,rank[findParent(it,parent)]);
    
    for(int i=0;i<n;i++){
        int count = 0;
        set<int> st;
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                count++;
                for(int k=0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 and x<n and y>=0 and y<m and grid[x][y]=='#'){
                       st.insert(findParent(x*m+y,parent));
                    }
                }
            }
        }
        for(auto it : st) count += rank[findParent(it,parent)];
        ans = max(ans,count);
    }

    for(int j=0;j<m;j++){
        int count = 0;
        set<int> st;
        for(int i=0;i<n;i++){
            if(grid[i][j]=='.'){
                count++;
                for(int k=0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 and x<n and y>=0 and y<m and grid[x][y]=='#'){
                       st.insert(findParent(x*m+y,parent));
                    }
                }
            }
        }
        for(auto it : st) count += rank[findParent(it,parent)];
        ans = max(ans,count);        
    }
    
    cout<<ans<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}