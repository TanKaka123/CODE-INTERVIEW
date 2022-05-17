// Problem: QHEAP1
// Link: https://www.hackerrank.com/challenges/qheap1/problem
// Solution: Nguyen Hong Tan

#include<iostream>
#include<queue>
using namespace std;



int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>pq;
	priority_queue<int, vector<int>, greater<int>>delPq;
	int u, v;
	for (int i = 0; i <n; i++)
	{
		cin >> u;
		
		if (u == 1)
		{
			cin >> v;
			pq.push(v);
		}
		else if (u== 2) {
			cin >> v;
			delPq.push(v);
			while (!delPq.empty() && delPq.top() == pq.top())
			{
				delPq.pop();
				pq.pop();
			}
		}
		else if(u==3)
			cout << pq.top() << endl;
	}

}