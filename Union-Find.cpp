#include <bits/stdc++.h>

using namespace std;

#define ll long long

class UnionFind {
private:
	vector<ll> parent, sz;
	ll numberOfComponents;

public:
	UnionFind(ll N) {
		numberOfComponents=N;
		sz.assign(N, 1);
		parent.assign(N, 0);
		for(int i = 0; i < N; i++) parent[i] = i;
	}
	ll findSet(ll i) {
		if(i!=parent[i])
			return parent[i] = findSet(parent[i]);
		return i;
	}
	bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
	void mergeSet(ll i, ll j) {
		ll x = findSet(i);
		ll y = findSet(j);
		if(x==y) return;
		if(sz[x] < sz[y]) swap(x,y);
		parent[y] = x;
		sz[x]+= sz[y];
		numberOfComponents--;
	}
	ll count() { return numberOfComponents; }
};

int main() {

}