#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool visited[100005];
vector<pair<ll,ll>> AdjList[100005];
ll dist[100005];

void Dijkstra(ll s) {
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

	for(ll i = 0; i < 100005; i++) dist[i]=1<<30;
	dist[s] = 0;

	pq.push({0, s});

	while(!pq.empty()) {
		ll u = pq.top().second; pq.pop();

		if(visited[u]) continue;
		visited[u] = 1;

		for(auto v: AdjList[u]) {
			if(dist[u]+v.first < dist[v.second]) {
				dist[v.second] = dist[u]+v.first;
				pq.push({dist[v.second], v.second});
			}
		}
	}
}

int main() {
	
}