#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> pos[20005];
int n;
const int maxn=300005;
int num[maxn];
int ST[25][maxn];
int logo[maxn];
inline int deal(int l,int r,int c,int step)
{
	int ans=0;
	if(l>r) return 0;
	if(l==r) 
	return num[l]-c;
	int len=r-l+1;
	int k=logo[len];
	int tmp=min(ST[k][l],ST[k][r-(1<<k)+1]);
	int i,j,last=l;
	ans+=tmp-c;
	for(i=0;i<pos[tmp].size();i++)
	{
		j=pos[tmp][i];
		if(j<l) continue;
		if(j>r) break;
		ans+=deal(last,j-1,tmp,step+1);
		last=j+1;
	}
	ans+=deal(last,r,tmp,step+1);
	return ans;
}
inline int check(int l,int r)
{
	int len=r-l+1;
	int k=logo[len];
	int tmp=min(ST[k][l],ST[k][r-(1<<k)+1]);
	return tmp;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(ST,1,sizeof ST);
	scanf("%d",&n);
	int a,b,c,d;
	for(a=2;a<=n;a++)
	logo[a]=logo[a/2]+1;
	for(a=1;a<=n;a++)
	{
		scanf("%d",&num[a]);
		pos[num[a]].push_back(a);
		ST[0][a]=num[a];
	}
	for(a=1;(1<<a)<=n;a++)
	{
		for(b=1;b+(1<<a)-1<=n;b++)
		{
			ST[a][b]=min(ST[a-1][b],ST[a-1][b+(1<<(a-1))]);
		}
	}
	printf("%d\n",deal(1,n,0,0));
	return 0;
}
