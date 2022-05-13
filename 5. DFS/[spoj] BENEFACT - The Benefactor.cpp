#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define MAX 50001
bool visited[MAX] = {false};
int dist[MAX];


int DFS(int start, vector<vector<pair<int, int > > > street, int n)
{
	for (int i = 0; i < MAX; i++)
	{
		visited[i] = false;
		dist[i] = 0;
	}

	stack<int> s;
	s.push(start);
	visited[start] = true;
	dist[start] = 0;

	while (!s.empty())
	{
		int flag = s.top();
		s.pop();

		for (int i = 0; i < street[flag].size(); i++)
		{
			if (visited[street[flag][i].first] == false)
			{
				dist[street[flag][i].first] = street[flag][i].second + dist[flag];
				visited[street[flag][i].first] = true;
				s.push(street[flag][i].first);
			}
		}
	}
	int idStreet = 0;
	for (int i = 0; i < n; i++)
	{
		if (dist[idStreet] < dist[i])
			idStreet = i;
	}
	
	return idStreet;
}
int main()
{
	int numTest;
	cin >> numTest;
	while (numTest--)
	{
		int n;
		cin >> n;
		vector<vector<pair<int, int > > > street(n);
		
		int x, y, z;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x >> y >> z;
			x--;
			y--;
			street[x].push_back({ y,z });
			street[y].push_back({ x,z });
		}

		int tmp = DFS(0, street, n);
		tmp= DFS(tmp, street, n);

		cout << dist[tmp]<<endl;
	}
}