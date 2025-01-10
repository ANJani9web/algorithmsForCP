//https://codeforces.com/contest/706/problem/D

#include<bits/stdc++.h>
using namespace std;

// class TrieNode{
//     public:
//     // int countZero = 0;
//     // int countOne = 0;
//     int count = 0;
//     TrieNode* children[2];

//     // Constructore to initialize a trie node
//     TrieNode()
//     {
//         // countZero = 0;
//         // countOne = 0;
//         count = 0;
//         for (int i = 0; i < 2; i++) {
//             children[i] = nullptr;
//         }
//     }
// };

// class Trie {
// public:
//     TrieNode* root;
//     Trie() {
//       root = new TrieNode();
//     }
    
//     void insert(string word) {
//         TrieNode* temp = root;
//         for(auto it  : word){
//             int index = it - '0';
//             if(!temp->children[index]){
//                 temp->children[index] = new TrieNode();
//             }
//             temp->count++;
//             temp = temp->children[index];
//         }
//         temp->count++;
//     }

//     void deleteFromTrie(string word){
//         TrieNode* temp = root;
//         for(auto it : word){
//             int index = it - '0';
//             temp->count--;
//             temp = temp->children[index];
//         }
//         temp->count--;
//     }
    
//     bool search(string word) {
//         TrieNode* temp = root;
//         for(auto it : word){
//             int index = it - 'a';
//             if(!temp->children[index]){
//                 return false;
//             }
//             temp = temp->children[index];
//         }
//         return temp->count;
//     }
    
//     bool startsWith(string prefix) {
//         TrieNode* temp = root;
//         for(auto it : prefix){
//             int index = it - 'a';
//             if(!temp->children[index]) return false;
//             temp = temp->children[index];
//         }
//         return true;
//     }

//     int findMax(string word){
//         int ans = 0;
//         int current = 30;
//         TrieNode* temp = root;
//         for(auto it : word){
//             int index = it - '0';
//             index = index ^ 1;
//             if(temp->children[index]){
//                 if(temp->children[index]->count)
//               {ans = ans + pow(2,current);
//               temp = temp->children[index];}
//               else temp = temp->children[index^1];
//             }
//             else{
//                 temp = temp->children[index^1];
//             }
//             current--;
//         }
//         return ans;
//     }
// };

// int main(){
//     // int n;
//     // cin>>n;
//     string binary = bitset<31>(8).to_string();
//     // cout<<binary<<endl;
//     // cout<<binary.length()<<endl;
//     // cout<<bitset<31>(8).to_string()<<endl;
//     // cout<<bitset<31>(9).to_string()<<endl;
//     // cout<<bitset<31>(11).to_string()<<endl;
//     // cout<<bitset<31>(6).to_string()<<endl;
//     // cout<<bitset<31>(1).to_string()<<endl;
//     Trie* t = new Trie();
//     int q;
//     cin>>q;
//     vector<pair<int,int>> bitcount(31,{0,0}); // count of zero and count of one
//     while(q--){
//       char ch;
//       cin>>ch;
//       int n;
//       cin>>n;
//       if(ch=='+'){
//         string binary = bitset<31>(n).to_string();
//         t->insert(binary);
//         // for(int i=0;i<31;i++){
//         //     int index = binary[i]-'0';
//         //     if(index==0){
//         //         bitcount[i].first++;
//         //     }
//         //     else bitcount[i].second++;
//         // }
//       }
//       else if(ch=='-'){
//         string binary = bitset<31>(n).to_string();
//         // for(int i=0;i<31;i++){
//         //     int index = binary[i]-'0';
//         //     if(index==0){
//         //         bitcount[i].first--;
//         //     }
//         //     else bitcount[i].second--;
//         // }
//         t->deleteFromTrie(binary);
//       }
//       else{
//         string binary = bitset<31>(n).to_string();
//         cout<<t->findMax(binary)<<endl;
//         // int current = 30;
//         // int ans = 0;
//         // for(int i=0;i<31;i++){
//         //     int index = binary[i]-'0';
//         //     int countForZero = bitcount[i].first;
//         //     int countForOne = bitcount[i].second;
//         //     if(index==0){
//         //         if(countForOne>0) ans += pow(2,current);
//         //     }
//         //     else if(countForZero>0) ans += pow(2,current);
//         //     current--;
//         // }
//         // cout<<ans<<endl;

//       }
//     }

// }

struct Node {
  Node *ch[2];
  int sum;
};
 
const int N = 2e5 + 10;
Node pool[N * 30], *last;
 
Node* new_node() {
  Node* ret = last++;
  ret->ch[0] = ret->ch[1] = nullptr;
  ret->sum = 0;
  return ret;
}
 
void insert(Node* p, int x, int y) {
  for (int i = 29; i >= 0; --i) {
    int k = (x >> i) & 1;
    if (!p->ch[k]) p->ch[k] = new_node();
    p = p->ch[k];
    p->sum += y;
  }
}
 
int query(Node* p, int x) {
  int ret = 0;
  for (int i = 29; i >= 0; --i) {
    int k = (x >> i) & 1;
    k ^= 1;
    if (p->ch[k] && p->ch[k]->sum) {
      p = p->ch[k];
      ret |= 1 << i;
    } else {
      p = p->ch[k ^ 1];
    }
  }
  return ret;
}
 
 
int main() {
  int n;
  cin >> n;
  last = pool;
  Node* root = new_node();
  insert(root, 0, 1);
  while (n--) {
    string op;
    int x;
    cin >> op >> x;
    if (op == "+") {
      insert(root, x, 1);
    } else if (op == "-") {
      insert(root, x, -1);
    } else {
      int ret = query(root, x);
      cout << ret << '\n';
    }
  }
  return 0;
}

