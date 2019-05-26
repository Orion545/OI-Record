#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int czf[25050];
inline void pdyx()
{
	vector<int> q;
    int n,shu[105],maxxx=0;
	memset(czf,0,sizeof(czf));
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&shu[i]);
	}
	for (int i=1;i<=n;i++) maxxx=max(maxxx,shu[i]);
	sort(shu+1,shu+1+n);
	q.push_back(0);
	for (int i=1;i<=n;i++)
	{
		int qqq=q.size();
		for (int j=0;j<qqq;j++)
		{

			for (int k=1;;k++) 
			{
				if (shu[i]*k+q[j]<=maxxx) q.push_back(shu[i]*k+q[j]);
				else break;
			}
		}
	}
	for (int i=0;i<q.size();i++) czf[q[i]]++;
	int anss=n;
	for (int i=1;i<=n;i++)
	{
		if (czf[shu[i]]>1) anss--;
	}
	cout<<anss<<endl;
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++) pdyx();
	return 0;
}
