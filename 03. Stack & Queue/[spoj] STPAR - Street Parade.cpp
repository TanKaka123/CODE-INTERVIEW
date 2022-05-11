// Problem: STPAR - Street Parade
// Link: https://www.spoj.com/problems/STPAR/
// Solution: Nguyen Hong Tan

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		stack<int> containTrucks;
		int x;
		int currTruck=1;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == currTruck)
				currTruck++;
			else {
				while (!containTrucks.empty() && containTrucks.top() == currTruck)
				{
					currTruck++;
					containTrucks.pop();
				}
				
				containTrucks.push(x);
			}
		}
		while (!containTrucks.empty() && containTrucks.top() == currTruck)
		{
			currTruck++;
			containTrucks.pop();
		}
		cout << (containTrucks.empty() ? "yes" : "no") << endl;
	}
}


