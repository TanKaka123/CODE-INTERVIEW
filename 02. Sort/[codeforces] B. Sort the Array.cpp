// Problem: B. Sort the Array
// Link: http://codeforces.com/problemset/problem/451/B
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> reverseArr(vector<long long>seg,int l, int r)
{
	vector<long long> tmpSeg;
	for (int i = l; i <= r; i++)
	{
		tmpSeg.push_back(seg[i]);
	}
	int j = tmpSeg.size()-1;
	for (int i = l; i <= r; i++)
	{
		seg[i] = tmpSeg[j];
		j--;
	}
	return seg;
}
int main()
{
	int n;
	int l = -1, r = -1;
	cin >> n;
	vector<long long> seg(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> seg[i];
	}
	for (int i = 0; i < n-1; i++)
	{
		if (seg[i] > seg[i + 1]) {
			l = i;
			break;
		}
	}
	for (int i = n-1; i >=1; i--)
	{
		if (seg[i] < seg[i - 1])
		{
			r = i;
			break;
		}
	}
	if (l != -1 && r != -1)
	{
		seg=reverseArr(seg, l, r);
	}
	for(int i=0;i<n-1;i++)
		if (seg[i] > seg[i + 1])
		{
			cout << "no";
			return 0;
		}
	if (l == r)
		cout << "yes" << endl << 1 << " " << 1;
	else
		cout << "yes" << endl << l+1 << " " << r+1;
}