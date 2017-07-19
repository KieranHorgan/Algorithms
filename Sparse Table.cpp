#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll log(ll x) { return 63 - __builtin_clzll(x); }

ll n, q, a[100'000], st[100'000][20];

ll BuildSparesTable() {
	for(int i = 0; i < n; i++) st[i][0] = i;
	for(int j = 1; 1<<j <= n; j++) {
		for(int i = 0; i+(1<<j) <= n; i++) {
			if(a[st[i][j-1]] < a[st[i+(1<<(j-1))][j-1]])
				st[i][j] = st[i][j-1];
			else
				st[i][j] = st[i+(1<<(j-1))][j-1];
		}
	}
}

ll RMQ(ll l, ll r) {
	ll j = log(r-l);
	return a[st[l][j]] < a[st[r-(1<<j)][j]] ? st[l][j] : st[r-(1<<j)][j];
}