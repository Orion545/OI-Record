#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int a[maxn];
int n;  
int dfs(int v,int t,int b)           
{
	if (t>n) return 0;
	if (t==b) return dfs(v,t+1,b);
	if (v<a[t]) return dfs(v,t+1,b);
	if (v%a[t]==0) return 1;
	int cnt=v/a[t];
	int j=v%a[t];
	for (int i=0;i<=cnt;++i)
	if (dfs(j+i*a[t],t+1,b)) return 1;
	return 0;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int t,ans;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;++i)
	{
		cin>>n; ans=0;
		for (int j=1;j<=n;++j) cin>>a[j];
		sort(a+1,a+n+1,cmp);
		for (int j=1;j<=n;++j)
		if (!dfs(a[j],1,j)) 
		++ans;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
