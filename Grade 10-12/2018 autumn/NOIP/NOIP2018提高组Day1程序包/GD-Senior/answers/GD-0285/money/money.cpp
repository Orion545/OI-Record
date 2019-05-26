#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int rd(){
	char c=getchar();int x=0,flag=1;
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-')
			flag=-1;
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return x*flag;
}
int n,a[110],vis[25010];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(int T=rd();T--;){
		memset(vis,0,sizeof(vis));
		n=rd();vis[0]=1;
		for(int i=1;i<=n;i++)
			a[i]=rd();
		for(int i=1;i<=n;i++)
			for(int j=a[i];j<=25000;j++)
				if(vis[j-a[i]])
					vis[j]++;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(vis[a[i]]==1)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
