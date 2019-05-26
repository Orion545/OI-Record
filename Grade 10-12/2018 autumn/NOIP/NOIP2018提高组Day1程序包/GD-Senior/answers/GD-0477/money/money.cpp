#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=110;
const int M=25010;
int a[N],v[N];
int n,tot,b[N],ans;
int c[N][M];

int check(int x,int p){
	if (p==0) return 0;
	if (c[p][x]!=-1) return c[p][x];
	if (x<b[p]) return c[p][x]=check(x,p-1);
	if (x%b[p]==0) return c[p][x]=1;
	int cnt=x/b[p];
	for (int i=0;i<=cnt;i++)
		if (check(x-i*b[p],p-1)) 
			return c[p][x]=1;
	return c[p][x]=0;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",a+i);
		if (n==2){
			if (a[1]%a[2]==0 || a[2]%a[1]==0)
				printf("1\n"); else printf("2\n");
			continue;
		}
		sort(a+1,a+n+1);
		if (a[1]==1){
			printf("1\n");
			continue;
		}
		memset(v,0,sizeof(v));
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			if (a[j]%a[i]==0)
				v[j]=1;
				
		tot=0;
		for (int i=1;i<=n;i++)
			if (!v[i]) b[++tot]=a[i];
		
		ans=0;
		memset(c,-1,sizeof(c));
		for (int i=tot;i;i--)
			if (!check(b[i],i-1))
				ans++;
		printf("%d\n",ans);
	}
}
