// Problem: B. Pasha and Tea
// Link: https://codeforces.com/problemset/problem/557/B
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include <iomanip>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	double x;
	cin >> n >> x;
	vector<int>capacity(n*2);
	double girlCapa, boyCapa;
	
	for (int i = 0; i < n*2; i++)
	{
		cin>>capacity[i];
	}

	sort(capacity.begin(), capacity.end());

	girlCapa = capacity[0];
	boyCapa = capacity[n];
	
	double result = min(boyCapa / 2.0, girlCapa);
	result = min(result * 3 * n, (double)x);
	
	cout << setprecision(7)<< result;
	
}

