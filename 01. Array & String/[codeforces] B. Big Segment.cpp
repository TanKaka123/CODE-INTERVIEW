// Problem: B. Big Segment
// Link: http://codeforces.com/problemset/problem/242/B
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, minS= 1000000000,maxE=-99999;
	int seg[2][100000];
	cin >> n;
	int dis = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> seg[0][i];
		if(minS> seg[0][i])
			minS = seg[0][i];
		cin >> seg[1][i];
		if ( maxE < seg[1][i])
			maxE = seg[1][i];
	}

	for (int i = 0; i < n; i++)
	{
		if (seg[0][i] == minS && seg[1][i] == maxE)
		{
			cout << i + 1;
			return 0;
		}
	}

	cout << -1;

}