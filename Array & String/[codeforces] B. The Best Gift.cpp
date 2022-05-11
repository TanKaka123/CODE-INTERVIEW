// Problem: B. The Best Gift
// Link: http://codeforces.com/problemset/problem/609/B
// Solution: Nguyen Hong Tan


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	long long n,m,inputBook;
	long long numPairBook ;
	cin >> n>>m;
	vector<long long> arrBook;
	arrBook.resize(m + 1);
	for (int i = 0; i <= m; i++)
		arrBook[i] = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> inputBook;
		arrBook[inputBook]++;
	}
	
	numPairBook = (n * (n - 1)) / 2;
	
	for (int i = 1; i <=m; i++)
	{
		if(arrBook[i]>1)
			numPairBook -= (arrBook[i] * (arrBook[i] - 1))/2 ;
		if ((arrBook[i] * (arrBook[i] - 1)) %2== 1)
			numPairBook--;

	}
	cout << numPairBook;

}