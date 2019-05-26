#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int gs[10050][2],n,maxxx=-1;
long long ansss=0;
int highh[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(gs,0,sizeof(gs));
	scanf("%d",&n);
	int q=n-1,i=2;highh[0]=0,highh[n+1]=0;
	scanf("%d",&highh[1]);
	while (q>0)
	{
		int a;
		scanf("%d",&a);
		highh[i]=a;
		if ((highh[i-1]>=highh[i] && highh[i-1]<=highh[i-2]) || (highh[i-1]<=highh[i] && highh[i-1]>=highh[i-2]))
		{
			highh[i-1]=highh[i];
			q--;
			continue;
		}
		i++;q--;
	}
	highh[i]=0;
	if (highh[i-1]>=0 && highh[i-1]<=highh[i-2]) 
	{
		i--;
		highh[i]=0;
	}
	for (int k=1;k<i;k++) 
	{
		if (highh[k]>highh[k+1]) gs[highh[k]][1]++;
		else gs[highh[k]][0]++;
		maxxx=max(maxxx,highh[k]);
	}
	ansss=0;
	int qq=1+gs[0][0];
	for (int k=1;k<=maxxx;k++)
	{
		ansss=ansss+qq;
		qq=qq+gs[k][0]-gs[k][1];
	}
	cout<<ansss<<endl;
	return 0;
}
