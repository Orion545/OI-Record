#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

//int a[100005];
int m, a[100001];
bool flag;

void search(int i, int key, int judging);

int main(void)
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	int t;
	cin >> t;
	
	
	for(int i = 1; i <= t; ++i)
	{
		
		cin >> m;
		for(int j = 1; j <= m; ++j)
		{
			cin >> a[j];
		}
		
		
		
		int count = 0;
		for(int j = 1; j <= m; ++j)
		{
			flag = true;
			search(1, a[j], j);
			if(flag){++count;	//wubiaoshi
			//cout << a[j] << " ";
		}
		}
		cout << count << endl;
	}
	
	
	return 0;
}

void search(int i, int key, int judging)
{
		if(i > m || flag == false || (i == judging && key == a[i]))
		{
			return;
		}
		for(int j = 0; j <= key; j += a[i])
		{
			
			if(j == key)
			{
				flag = false;
			}
			search(i + 1, key - j, judging);

		}

}
