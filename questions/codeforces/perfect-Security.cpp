//https://codeforces.com/contest/706/problem/D

#include<bits/stdc++.h>
using namespace std;

// struct Node {
//   Node *ch[2];
//   int sum;
// };

typedef struct Node
{
    int sum;
    Node *ch[2];
    Node()
    {
        sum=0;ch[0]=NULL;ch[1]=NULL;
    }
} Trie;

Trie *root;
 
void insert(int x) {
  Trie *p = root;
  for (int i = 30; i >= 0; --i) {
    int k = (x >> i) & 1;
    if (!p->ch[k]) p->ch[k] = new Trie();
    p = p->ch[k];
    p->sum++;
  }
}

void remove(int x){
  Trie *temp = root;
  for(int i=30;i>=0;i--){
    int k = (x>>i) &1;
    temp=temp->ch[k];
    temp->sum--;
  }
}
 
int query(int x) {
  // int ret = 0;
  // for (int i = 30; i >= 0; --i) {
  //   int k = (x >> i) & 1;
  //     if(!p->ch[k] || (p->ch[k]->sum==0)){
  //       ret = ret | (1<<i);
  //       p = p->ch[!k];
  //     }
  //     else p = p->ch[k];
  //   }
  //   //p->sum--;
  // return ret;
  int ans = 0;
  Trie* temp = root;
  for(int i=30;i>=0;i--){
    int k = (x>>i)&1;
    // k = 1
    if(temp->ch[k]!=NULL and temp->ch[k]->sum){
       temp = temp->ch[k];
    }
    else {
      ans = ans | (1<<i);
      temp = temp-> ch[!k];
    }
  }
  return ans;
}
 
 
int main() {
  int n;cin>>n;
  vector<int> encryptedMessage(n);
  vector<int> permutedEncyptionKey(n);
  for(int i=0;i<n;i++) cin>>encryptedMessage[i];
  for(int i=0;i<n;i++) cin>>permutedEncyptionKey[i];
  root = new Trie();
  
  for(int i=0;i<n;i++){
    insert(permutedEncyptionKey[i]);
  }
  for(int i=0;i<n;i++){
    int x = query(encryptedMessage[i]);
    cout<<x<<" ";
    remove(x^encryptedMessage[i]);
  }
}

// int n;cin>>n;
//   vector<int> encryptedMessage(n);
//   vector<int> permutedEncyptionKey(n);
//   for(int i=0;i<n;i++) cin>>encryptedMessage[i];
//   for(int i=0;i<n;i++) cin>>permutedEncyptionKey[i];
//   Node* root = new_node();
//   for(int i=0;i<n;i++){
//     insert(root,permutedEncyptionKey[i],1);
//   }
//   for(int i=0;i<n;i++){
//     cout<<query(root,encryptedMessage[i])<<" ";
//   }

