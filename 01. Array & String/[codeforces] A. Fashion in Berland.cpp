// Problem: A. Fashion in Berland
// Link: http://codeforces.com/contest/691/problem/A
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,cnt=0,btn;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> btn;
		if (btn == 0)
			cnt++;
	}
	
	if (n == 1)
		cout <<(cnt==1 ?"NO":"YES");
	else 
		cout<< (cnt == 1 ? "YES" : "NO");
}