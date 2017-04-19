#include <bits/stdc++.h>

using namespace std;

#define ll long long

class FenwickTree {
private: vector<ll> ft;

public:
	FenwickTree(ll N) {
		ft.resize(N+1);
	}

	void insert(ll i, ll v) {
		while(i < N+1) {
			data[i] += value;
			i += i&-i;
		}
	}

	ll rsq(ll i) {
		return get
	}
}

int main() {
	
}