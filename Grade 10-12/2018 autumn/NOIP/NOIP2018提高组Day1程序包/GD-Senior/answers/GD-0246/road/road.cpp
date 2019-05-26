#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int n, f[maxn], res=0, firmin=999999;
bool fir=true;
struct pr
{
	int l, r;
	pr(int a=0, int b=0)
	{
		l=a, r=b;
	}
};
inline void read()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &f[i]);
		if(f[i]<firmin) firmin=f[i];
	}
}
inline int findmin(int l, int r)
{
	int cmin=999999;
	while(l<=r)
	{
		if(f[l]<cmin)
		{
			cmin=f[l];
		}
		++l;
		if(f[r]<cmin)
		{
			cmin=f[r];
		}
		--r;
	}
	return cmin;
}
void srch(int l, int r);
void ffill(int l, int r, int m)
{
	//printf("[%d, %d]: %d\n", l, r, m);
	queue<int> q;
	res+=m;
	for(int i=l; i<=r; ++i)
	{
		f[i]-=m;
		if(f[i]==0)
		{
			q.push(i);
		}
		//printf("%d\n", i);
	}
	/*for(int i=1; i<=n; ++i)
	{
		printf("%d ", f[i]);
	}
	printf("\n");*/
	int temp=q.front()-1;
	if(temp>=l) srch(l, temp);
	while(!q.empty())
	{
		int c=q.front(); q.pop();
		if(q.empty())
		{
			temp=c+1;
			if(temp<=r) srch(c+1, r);
			break;
		}
		else
		{
			int n=q.front();
			srch(c+1, n-1);
		}
	}
}
void srch(int l, int r)
{
	int cmin;
	if(fir)
	{
		cmin=firmin;
		fir=false;
	}
	else
	{
		cmin=findmin(l, r);
	}
	if(cmin==0)return;
	ffill(l, r, cmin);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read();
	srch(1,n);
	printf("%d", res);
	fclose(stdin); fclose(stdout);
	return 0;
}
