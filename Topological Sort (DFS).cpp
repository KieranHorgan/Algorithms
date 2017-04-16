#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool visited[100005];
vector<ll> AdjList[100005];

vector<ll> topoSort; // Topological sorted in reverse order

void dfs(ll u) {
	if(visited[u]) return;
	visited[u] = 1;

	for(auto v: AdjList[u])
		dfs(v);

	topoSort.push_back(u);
}

int main() {

}