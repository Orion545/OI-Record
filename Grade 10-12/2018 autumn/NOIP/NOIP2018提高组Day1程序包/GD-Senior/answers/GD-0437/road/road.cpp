#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, work=0, temp, d1[100001];
	bool lx;
	priority_queue <int, vector <int>, greater<int> > d;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &temp);
		d.push(temp);
		d1[i]=temp;
	}
	
	int p=0, pfr, k=0;
	while(k<n){
		k=0;
		while(!d.empty() && d.top()-p==0)
			d.pop();
		lx=false;
		pfr=p;
		p=d.top();
		for(int i=1; i<n; i++)
		{
			if(d1[i])
			{
				d1[i]-=(p-pfr);
				if(!lx)
					lx=true;
			}
			else{
				k++;
				if(lx)
				{
					lx=false;
					work+=(p-pfr);
				}
			}
		}
		if(d1[n])
		{
			d1[n]--;
			work+=(p-pfr);
		}
		else{
			k++;
			if(lx)
			{
				work+=(p-pfr);
			}
		}
	}

	cout<<work;
	return 0;
}
