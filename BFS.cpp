#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
vector<ll> AdjList[100005];

void bfs(ll s) {
	vector<bool> visited(n, 0);
	queue<ll> q;
	q.push(s);

	while(!q.empty()) {
		ll u = q.front(); q.pop();

		if(visited[u]) continue;
		visited[u] = 1;

		cout << u << endl;

		for(auto v: AdjList[u])
			q.push(v);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}

	bfs(0);
}