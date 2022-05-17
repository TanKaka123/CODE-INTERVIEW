// Problem: Restaurant Rating
// Link: https://www.codechef.com/problems/RRATING
// Solution: Nguyen Hong Tan

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long u, v, virSize=0,maxCurr;
	priority_queue<long long,vector<long long>, greater<long long> >pq;
	priority_queue<long long> pqTemp;
	while (n--)
	{
		cin >> u;

		if (u == 1)
		{
			cin >> v;
			virSize++;

			if (!pq.empty() && v > pq.top())
			{
				pqTemp.push(pq.top());
				pq.pop();
				pq.push(v);
			}
			else
				pqTemp.push(v);

			if (virSize % 3 == 0)
			{
				pq.push(pqTemp.top());
				pqTemp.pop();
			}

		}
		else
		{
			if (pq.empty())
				cout << "No reviews yet" << endl;
			else 
				cout << pq.top() << endl;
		}
	}
}