#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int f[18][200001],p[18][200001];
int n,ans;

void solve(int l,int r,int d)
{
	if(l>r) return ;
	int j=0;
	for(;l+(1<<j+1)<=r;j++);
	int mi=min(f[j][l],f[j][r+1-(1<<j)])-d;
	int pos=(f[j][l]<f[j][r+1-(1<<j)])?p[j][l]:p[j][r+1-(1<<j)];
	ans+=mi;
	solve(l,pos-1,d+mi);
	solve(pos+1,r,d+mi);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;p[0][i]=i,i++) scanf("%d",&f[0][i]);
	for(int j=1;j<18;j++)
		for(int i=1;i<=n;i++)
		{
			f[j][i]=min(f[j-1][i],f[j-1][i+(1<<j-1)]);
			p[j][i]=(f[j-1][i]<f[j-1][i+(1<<j-1)])?p[j-1][i]:p[j-1][i+(1<<j-1)];
		}
	solve(1,n,0);
	printf("%d\n",ans);
	return 0;
}
