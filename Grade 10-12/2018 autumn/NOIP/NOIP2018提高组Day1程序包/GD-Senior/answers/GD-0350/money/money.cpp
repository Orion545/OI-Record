#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,f[200],a[200],len,tot,ans,next;
bool flag[200];
int check()
{
	for (int i = 1;i <= n;i++) if (!flag[i]) return i;
	return -1;
}
void dfs(int deep)
{
	for (int i = 1;i <= n;i++) if ((!flag[i])&&(tot == a[i])) flag[i] = true; 
	if (deep > len) return;
	int temp = f[deep],mul = 0;
	while (tot + temp * mul <= a[n])
	{
		tot += temp * mul;
		dfs(deep + 1);
		tot -= temp * mul;
		mul++;
	}
}
void work()
{
	memset(f,0,sizeof(f));
	memset(flag,false,sizeof(flag));
	scanf("%d",&n);ans = 0;
	for (int i = 1;i <= n;i++)
		scanf("%d",a + i);
	sort(a + 1,a + n + 1);
	flag[1] = true;len = 1;f[1] = a[1];tot = 0;
	dfs(1);next = check();ans++;
	while (next > 0) 
	{
		flag[next] = true;len++;f[len] = a[next];tot = 0;
		dfs(1);ans++;
		next = check();
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i = 1;i <= T;i++)
		work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
