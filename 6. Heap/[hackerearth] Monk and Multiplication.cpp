// Problem: Monk and Multiplication
// Link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	vector<long long>monk(n);
	priority_queue<long long > pq;
	for(int i=0 ; i<n ; i++)
	{
		cin>>monk[i];
	
		pq.push(monk[i]);

		if(pq.size()<3)
		{
			cout<<1endl;
		}
		else {
			long long firstValue= pq.top();
			pq.pop();
			long long secondValue=pq.top();
			pq.pop();
			long long thirdValue=pq.top();
			cout<<firstValue*secondValue*thirdValue<<endl;
			pq.push(firstValue);
			pq.push(secondValue);
			pq.push(thirdValue);
		}
		
	}
}