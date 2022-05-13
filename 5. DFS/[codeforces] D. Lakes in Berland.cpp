// Problem: D. Lakes in Berland
// Link: https://codeforces.com/problemset/problem/723/D
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
#define MAX 52

int n, m, k;
char map[MAX][MAX];
int visited[MAX][MAX] ;
int dX[] = { 1,0,0,-1 };
int dY[] = { 0,1,-1,0 };

bool compareNumberWater(pair<int, pair<int, int> > n1, pair<int, pair<int, int> > n2)
{
	return n1.first < n2.first;
}

struct Cell {
	int x;
	int y;
};


int DFS(int currStatusVisit, Cell start)
{
	int numberWater = 0;
	stack<Cell>containWater;

	containWater.push({ start.x,start.y });
	visited[start.x][start.y] = currStatusVisit;
	numberWater++;

	while (!containWater.empty())
	{
		Cell u = containWater.top();
		containWater.pop();

		for (int i = 0; i < 4; i++)
		{
			Cell v;
			v.x = u.x + dX[i];
			v.y = u.y + dY[i];

			if (v.x>0 && v.y>0 && v.x<n && v.y<m && map[v.x][v.y] == '.' && visited[v.x][v.y] == -1)
			{
				visited[v.x][v.y] = currStatusVisit;
				containWater.push({ v.x,v.y });
				numberWater++;
			}
		}
	}
	return numberWater;
}
int main()
{

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '.' && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
				int temp = DFS(0, { i,j });
			}
		}
	}

	int numberVisit = 1;
	vector< pair<int, pair<int, int> > > numberWater;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '.' && visited[i][j] == -1) {
				numberWater.push_back({ DFS(numberVisit,{i,j}), make_pair(i,j) });
			}
			numberVisit++;
		}
	}
	
	int maxWater = numberWater[numberWater.size() - k - 1].first;
	int countWaterDel = 0;
	sort(numberWater.begin(), numberWater.end(), compareNumberWater);

	

	for (int h = 0; h < numberWater.size() - k; h++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visited[i][j] == visited[numberWater[h].second.first][numberWater[h].second.second]) {
					map[i][j] = '*';
					countWaterDel++;
				}
			}
		}
	}

	cout << countWaterDel << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}