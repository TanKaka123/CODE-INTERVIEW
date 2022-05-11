// Problem: C. Kefa and Park
// Link: https://codeforces.com/problemset/problem/580/C
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100001
vector<int>graph[MAX];
vector<int> containCat;
int visited[MAX] = { false };
int n, limit;
int cntRes = 0;

struct catLimited {
	int idx;
	int meetCat;
};

void BFS()
{
	queue<catLimited>Q;
	Q.push({ 1,containCat[1] });
	visited[1] = true;

	while (!Q.empty())
	{
		catLimited u = Q.front();
		Q.pop();

		for (int i = 0; i < graph[u.idx].size(); i++)
		{
			if (visited[graph[u.idx][i]] == false && containCat[graph[u.idx][i]] + u.meetCat <= limit)
			{
				visited[graph[u.idx][i]] = true;
				if (containCat[graph[u.idx][i]] == 0)
					Q.push({ graph[u.idx][i] ,0 });
				else 
					Q.push({ graph[u.idx][i] , 1 + u.meetCat });
				
			}
		}

	}
}

int main()
{

	cin >> n >> limit;
	containCat.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> containCat[i];

	int u, v, cnt = 0;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	BFS();

	for (int i = 2; i <= n; i++)
		if (graph[i].size() == 1 && visited[i])
			cnt++;

	cout << cnt;
}