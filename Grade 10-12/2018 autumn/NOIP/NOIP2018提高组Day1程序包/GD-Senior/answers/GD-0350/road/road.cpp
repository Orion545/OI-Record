#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,d[200000],f[200000],a,b,ans,now,maxx,block;
bool flag;
/*int check(int p)
{
	if (f[p] > now) return f[p];
	int mul = 1,temp,val = a[p];
	while (mul < p) 
	{
		temp = f[p - mul];
		val = val < temp ? val : temp;
		mul = mul << 1;
	}
	return (val);
}
void modify(int p,int num)
{
	if (p > n) return;
	f[p] = d[num] < f[p] ? d[num] : f[p];
	modify(p + (p & (-p)),num);
}
int sreach(int L,int R)
{
	
	if (L >= R) return 0;
	int xL = L - 1;
	a = sreach(1,xL - (xL & (-xL)));
	a = a
	b = sreach(1,R - (R & (-R)));
	return (a < b ? a : b);
}*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0,sizeof(d));
	memset(f,0,sizeof(f));
	ans = 0;now = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",d + i);
		maxx = d[i] > maxx ? d[i] : maxx;
	}
	while (now < maxx) 
	{
		flag = true;block = 0;
		for (int i = 1;i <= n;i++)
		{
			if (d[i] <= now) flag = true;
			else if (flag) {block++;flag = false;};
		}
		now++;ans += block;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
