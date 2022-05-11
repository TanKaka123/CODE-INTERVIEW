// Problem: B. Devu, the Dumb Guy
// Link: http://codeforces.com/problemset/problem/439/B
// Solution: Nguyen Hong Tan


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	long long n, x, result=0;
	cin >> n >> x;
	vector<long long> subject(n);
	for (int i = 0; i < n; i++)
	{
		cin >> subject[i];
	}
	sort(subject.begin(), subject.end());
	for (int i = 0; i < n; i++)
	{
		result += x * subject[i];
		if (x > 1)
			x--;
	}
	cout << result;
}