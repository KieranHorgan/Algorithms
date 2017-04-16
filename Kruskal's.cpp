#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define piii pair<ll,pair<ll,ll>>

ll n;
vector<piii> EdgeList;

class UnionFind {
private:
	ll numberOfComponents;
	vector<ll> sz, parent;

public:
	UnionFind(ll N) {
		numberOfComponents = N;
		sz.assign(N, 1);
		parent.assign(N, 0);
		for(int i = 0; i < N; i++) parent[i] = i;
	}
	ll findSet(ll i) {
		if(parent[i]!=i)
			return parent[i] = findSet(parent[i]);
		return i;
	}
	void mergeSet(ll i, ll j) {
		ll x = findSet(i);
		ll y = findSet(j);
		if(x==y) return;
		if(sz[i]<sz[y]) swap(x,y);
		parent[y]=x;
		sz[x]+=sz[y];
		numberOfComponents--;
	}
	bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
	ll count() { return numberOfComponents; }
};

void Kruskal() {
	UnionFind UF = UnionFind(n);
	sort(EdgeList.begin(), EdgeList.end());
	ll MST = 0;

	for(auto i: EdgeList) {
		ll u = i.second.first;
		ll v = i.second.second;
		ll w = i.first;

		if(!UF.isSameSet(u,v)) {
			UF.mergeSet(u, v);
			MST += w;
		}
	}

	cout << MST << endl;
}

int main() {
	
}