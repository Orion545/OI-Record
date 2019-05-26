#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100005];

int main(void)
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
	int max_d = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] > max_d)max_d = a[i];
	}
	
	int count = 0;
	int left = 0, right = 0;
	for(int d = 1; d <= max_d; ++d)
	{
		left = 0;
		right = 0;
		for(int j = 1; j <= n; ++j)
		{
			if(a[j] >= d)	//youkeng
			{
				if(left == 0)
				{
					left = j;
					right = j;
				}
				else
				{
					right++;
				}
			}
			else	//wukeng
			{
				if(left == 0)
				{
					;
				}
				else
				{//cout << left << " " << right << endl;
					count++;
					right = 0;
					left = 0;
				}
			}
		}
		if(left != 0)
		{
			count++;
		}
		//if(left != 0)count += right - left + 1;
	}
	
	cout << count;
	
	return 0;
}


