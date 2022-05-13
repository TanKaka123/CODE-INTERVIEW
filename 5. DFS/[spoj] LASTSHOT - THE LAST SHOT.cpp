// Problem: LASTSHOT - THE LAST SHOT
// Link: https://www.spoj.com/problems/LASTSHOT/
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

#define MAX 10001
int visited[MAX] ;
vector<int>bomb[MAX];

int DFS(int currValueVisited, int start)
{
	int countPath = 0;

	stack<int> s;
	s.push(start);
	visited[start] = currValueVisited;
	countPath++;

	while (!s.empty())
	{
		int tmp = s.top();
		s.pop();

		for (int i = 0; i < bomb[tmp].size(); i++)
		{
			if (visited[bomb[tmp][i]] <= currValueVisited - 1)
			{
				s.push(bomb[tmp][i]);
				visited[bomb[tmp][i]] = currValueVisited;
				countPath++;
			}
		}
	}
	return countPath;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		visited[i] = -1;

	int n, m, result=0;
	cin >> n>> m;
	
	int u, v;
	for (int i=0;i<m;i++)
	{
		cin >> u >> v;
		bomb[u].push_back(v);
	}

	int valueVisited = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = DFS(valueVisited,i);
		result = max(result, temp);
		valueVisited++;
		
	}
	
	cout << result;

}