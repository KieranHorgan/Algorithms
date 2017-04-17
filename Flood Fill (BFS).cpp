#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll R, C;
char grid[10005][10005];
ll dc[] = {1, 1, 0,-1,-1,-1, 0, 1};
ll dr[] = {0, 1, 1, 1, 0,-1,-1,-1};

ll FloodFill(ll r, ll c, ll c1, ll c2) {
	queue<pair<ll,ll>> q;
	q.push({r,c});
	ll ans = 0;

	while(!q.empty()) {
		pair<ll,ll> u = q.front(); q.pop();
		if(u.first<0 || u.first>=R || u.second<0 || u.second>=C) continue;
		if(grid[u.first][u.second] != c1) continue;
		ans++;

		grid[u.first][u.second] = c2;

		for(int d = 0; d < 8; d++)
			q.push({u.first+dr[d], u.second+dc[d]});
	}
	return ans;
}

int main() {
	
}