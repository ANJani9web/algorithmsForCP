//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B

//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

#include<bits/stdc++.h>
using namespace std;

#define ll long long 
// Credits to HealthyUG for the inspiration.
// Segment Tree with Point Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<ll> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); 
        //fill(all(tree), Node());
        for(int i=0;i<s;i++){
            tree[i]=Node();
        }
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node{
	ll val; // may change
	Node() { // Identity element
		val =1e18;	// may change
	}
	Node(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node &l, Node &r) { // Merge two child nodes
		val = min(l.val , r.val);  // may change
	}
};

struct Update{
	ll val; // may change
	Update(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node &a) { // apply update to given node
		a.val = val; // may change
	}
};

int main(){
  int n,q;
  cin>>n>>q;
  vector<ll> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  SegTree<Node,Update> s(n,arr);

  for(int i=0;i<q;i++){
    int x;
    cin>>x;
    if(x==1){
        int index;cin>>index;
        //index--;
        ll val;cin>>val;
        s.make_update(index,val);
    }
    else{
        int l,r;
        cin>>l>>r;
        //l--;
        r--;
        cout<<s.make_query(l,r).val<<endl;
    }
  }

}
