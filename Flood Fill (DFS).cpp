#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll R, C;
char grid[10005][10005];
ll dc[] = {1, 1, 0,-1,-1,-1, 0, 1};
ll dr[] = {0, 1, 1, 1, 0,-1,-1,-1};

ll FloodFill(ll r, ll c, ll c1, ll c2) {
	if(r<0 || r>=R || c<0 || c>=C) return 0;
	if(grid[r][c] != c1) return 0;

	ll ans = 1;
	grid[r][c] = c2;

	for(int d = 0; d < 8; d++)
		ans += FloodFill(r+dr[d], c+dc[d], c1, c2);
	return ans;
}

int main() {
	
}