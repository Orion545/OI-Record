#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 300010
int n,m;
char str[110];
int d[maxn];
namespace line_1{
	int vis[maxn],ans=2147483647;
	void dfs(int x){
		if(x==n+1){
			int cnt=0;
	/*		for(int i=1;i<=n;i++)
				printf("%d ",vis[i]);*/
			cnt+=(vis[1])*d[1];
			for(int i=2;i<=n;i++){
				if(vis[i]==0&&vis[i-1]==0){
	//				printf("\n");
					return ;
				}
				cnt+=(vis[i])*d[i];
			}
	//		printf("Y %d\n",cnt);
			ans=min(ans,cnt);
			return ;
		}
		if(vis[x]!=-1){
			dfs(x+1);
			return;
		}
		vis[x]=0;
		dfs(x+1);
		vis[x]=1;
		dfs(x+1);
		vis[x]=-1;
	}
	void mian(){
		memset(vis,-1,sizeof vis);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]);
		for(int i=1,u,v;i<n;i++)
			scanf("%d%d",&u,&v);
		for(int i=1,a,b,c,d;i<=m;i++){
			ans=2147483647;
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if((a==c&&b!=d)||(abs(c-a)==1&&b==0&&d==0)){
				printf("-1\n");
				continue;
			}
			vis[a]=b;
			vis[c]=d;
			dfs(1);
			vis[a]=vis[c]=-1;
			printf("%d\n",ans);
		}
		
	}
};
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",str);
//	printf("%d",str[0]=='A');
//	if(str[0]=='A'&&str[2]=='1'){
		line_1::mian();
//	}
	return 0;
}
/*
5 10 A1
1 2 3 4 5
1 2
2 3
3 4
4 5
1 1 2 0
*/
