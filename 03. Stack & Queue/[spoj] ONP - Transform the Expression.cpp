// Problem: ONP - Transform the Expression
// Link: https://www.spoj.com/problems/ONP/
// Solution: Nguyen Hong Tan

#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

string handle(string s)
{
	stack<char>sign;
	stack<char>brackets;
	string result;
	int j = 0;	result[j] = '\0';
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			result.push_back(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^')
		{
			sign.push(s[i]);
		}
		else {
			if (!brackets.empty() && brackets.top() == '(' && s[i] == ')')
			{
				brackets.pop();
				result.push_back( sign.top());
				sign.pop();
			}
			else
				brackets.push(s[i]);
		}
	}

	return result;
}
int main()
{
	int n;
	cin >> n;
	string rpn;
	for (int i = 0; i < n; i++) {
		cin >> rpn;
		cout << handle(rpn)<<endl;
	}
	

}