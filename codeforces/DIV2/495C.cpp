// Date solved- 26/10/15
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
	string s;
	cin>>s;
	int lb=0,rb=0;
	int n=s.length();
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')	lb++;
		if(s[i]==')')	rb++;
	}	

	vector<int> v;
		
	if(rb>=lb)
	{
		cout<<"-1\n";
		return 0;
	}
	else
	{
		int hs=0;
		stack<int> st;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(')
			{
				st.push(i);
			}
			else if(s[i]==')')
			{
				if(st.empty())
				{
					cout<<"-1\n";
					return 0;
				}
				else
				{
					if(s[st.top()]=='(' )
					{
						st.pop();
					}
				}
			}
			else
			{
				hs=i;
				if(st.empty())
				{
					cout<<"-1\n";
					return 0;
				}
				else
				{
					if(st.top()<=hs)
					{
						v.push_back(1);
						st.pop();
					}
					else
					{
						cout<<"-1\n";
						return 0;
					}
				}
			}
			
		}
		while(!st.empty() && st.top()<=hs)
		{
			st.pop();
			v[v.size()-1]++;
		}
		if(!st.empty())
		{
			cout<<"-1\n";
			return 0;
		}
	}
	
	for(unsigned int i=0;i<v.size();i++)
		cout<<v[i]<<"\n";

	return 0;
}
