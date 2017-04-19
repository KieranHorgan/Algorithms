#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll prefixSum[1005][1005], n, m;

ll rsq(ll r1, ll c1, ll r2, ll c2) { return prefixSum[r2][c2] - prefixSum[r1-1][c2] - prefixSum[r2][c1-1] + prefixSum[r1-1][c1-1]; }

int main() {
	cin >> n >> m;

	ll max2DRange = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> prefixSum[i][j];
			prefixSum[i][j] += prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
			max2DRange = max(max2DRange, prefixSum[i][j]);
		}
	}
}