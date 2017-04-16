#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
ll AdjMatrix[1005][1005];

void FloydWarshall() {
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k]+AdjMatrix[k][j]);
}

int main() {

}