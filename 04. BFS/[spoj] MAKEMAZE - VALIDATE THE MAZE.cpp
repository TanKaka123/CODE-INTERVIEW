// Problem: MAKEMAZE - VALIDATE THE MAZE
// Link: https://www.spoj.com/problems/MAKEMAZE/
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 100
vector<char> maze[MAX];
int path[MAX];
bool visited[MAX][MAX];
int row, col;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

struct coor {
	int x;
	int y;
};

vector <coor > entry;

void BFS()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			visited[i][j] = false;

	queue<coor> Q;

	visited[entry[0].x][entry[0].y] = true;
	Q.push({ entry[0].x,entry[0].y });

	while (!Q.empty())
	{
		coor v;
		coor flag = Q.front();
		Q.pop();
		if (flag.x == entry[1].x && flag.y == entry[1].y)
			break;
		for (int i = 0; i < 4; i++)
		{
			v.x = flag.x + dx[i];
			v.y = flag.y + dy[i];
			if (v.x >= 0 && v.y >= 0 && v.x < row && v.y < col && maze[v.x][v.y] == '.' && visited[v.x][v.y] == false)
			{
				visited[v.x][v.y] = true;
				Q.push({ v.x,v.y });

			}
		}

	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{

		cin >> row >> col;
		entry.clear();
		maze->clear();
		int cnt = 0;
		for (int i = 0; i < row; i++)
		{
			maze[i].resize(col);
			for (int j = 0; j < col; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == '.' && (i == 0 || j == 0 || i == row - 1 || j == col - 1))
					entry.push_back({ i,j });
			}
		}
		if (entry.size() != 2)
		{
			cout << "invalid" << endl;
			continue;
		}

		BFS();

		cout << (visited[entry[1].x][entry[1].y] == true ? "valid" : "invalid") << endl;

	}
}