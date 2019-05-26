#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define maxn 110
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int a[maxn],cut[maxn];
int f[25010];
int n;
void work()
{
	n=read();
	int mx=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>mx)mx=a[i];
	}
	std::sort(a+1,a+n+1);
	memset(cut,0,sizeof(cut));
	memset(f,0,sizeof(f)); f[0]=1;
	for(int i=1;i<=n;i++)
		if(f[a[i]])cut[i]=1;
		else{
			for(int j=a[i];j<=mx;j++)
				f[j]|=f[j-a[i]];
		}
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(!cut[i]);
	printf("%d\n",cnt);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)work();
	fclose(stdin); fclose(stdout);
	return 0;
}
