// Problem: B. Processing Queries
// Link: https://codeforces.com/problemset/problem/644/B
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct process {
	int arrTime;
	int needTime;
	int idx;
};

void main()
{
	int n, b;
	cin >> n >> b;
	process query;
	queue<process> wait;
	long long time = 0;
	vector<long long> completeTime(n);
	bool empty = true;
	for (int i = 0; i < n; i++)
	{
		cin >> query.arrTime;
		cin >> query.needTime;
		query.idx = i;
		if (query.arrTime >= time)
		{
			empty = false;
			if (!wait.empty())
			{
				while (!wait.empty())
				{
					if (time>query.arrTime)
						break;
					time += wait.front().needTime;
					completeTime[wait.front().idx]=time;
					wait.pop();
				}
				if (query.arrTime >= time)
				{
					time = query.arrTime + query.needTime;
					completeTime[query.idx] = time;
				}
				else
					wait.push(query);
				
			}
			else
			{
				if (query.arrTime >= time)
					time = query.arrTime + query.needTime;
				else
					time += query.needTime;

				completeTime[query.idx]=time;
			}
		}
		else
		{
			if (wait.size() == b)
				completeTime[query.idx] = -1;
			else
				wait.push(query);
		}
	}

	while (!wait.empty())
	{
		time += wait.front().needTime;
		completeTime[wait.front().idx]=time;
		wait.pop();
	}
	
	for (int i = 0; i < completeTime.size()-1; i++)
		cout << completeTime[i] << " ";
	cout << completeTime[completeTime.size()-1];
}