// Problem: Dhoom 4
// Link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100001
bool visited[MAX] = { false };
int path[MAX] = { 0 };
int src, des, nKey;
vector<int> valueKey;

void BFS()
{
	queue<int>Q;
	visited[src] = true;
	Q.push(src);

	while (!Q.empty())
	{
		long long flag = Q.front();
		Q.pop();

		if (flag == des)
			break;

		for (int i = 0; i < nKey; i++)
		{
			long long v = (flag * valueKey[i])% 100000;	
			if (!visited[v])
			{	
				path[v] =path[flag]+1;
				visited[v] = true;
				Q.push(v);
			}
		}
	}
}
int countPath()
{
	if (src == des)
		return 0;
	if (path[des] == 0)
		return -1;
	return path[des];
}
int main()
{
	
	cin >> src >> des;
	cin >> nKey;

	valueKey.resize(nKey);
	for (int i = 0; i < nKey; i++)
		cin >> valueKey[i];

	BFS();
	cout << countPath();
}