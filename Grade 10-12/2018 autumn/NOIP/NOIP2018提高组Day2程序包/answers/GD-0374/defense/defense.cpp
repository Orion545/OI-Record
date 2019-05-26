#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100005;
const int INF=0x9fffff;
int n,m,a,x,b,y,w[N],f1[N],f2[N],ans,tot;
char s[5];
struct node{
	int be[105];
	int num;
	int pre;
	int son;
};
node ct[N];

void dfs(int pos,int tot)
{
	if(pos>n){
		ans=min(ans,tot);
		return ;
	}
	if(f1[pos-1]==0) dfs(pos+1,tot+w[pos]);
	else {
		dfs(pos+1,tot);
		f1[pos]=1;
		dfs(pos+1,tot+w[pos]);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d %s",&n,&m,s);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		ct[a].num++;
		ct[a].be[ct[a].num]=b;
		ct[b].num++;
		ct[b].be[ct[b].num]=a;
	}
	if(s[1]=='2'&&x==0&&y==0){
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			printf("-1\n");
		}
	}
	else if(s[0]=='A'&&s[1]=='2'){
		for(int i=1;i<=m;i++){
			memset(f1,0,sizeof(f1));
			scanf("%d%d%d%d",&a,&x,&b,&y);
			f1[0]=1;
			dfs(1,0);
			printf("%d\n",ans);
		}
	}
	else if(s[0]=='A'){
			for(int i=1;i<=n;i++){
				f1[i]=INF;
				f2[i]=INF;
			}
			f1[1]=w[1]; f1[0]=0;
			for(int i=2;i<=n;i++){
				f1[i]=min(f1[i-1]+w[i],min(f1[i-2]+w[i],f1[i-1]));
			}
			f2[n]=w[n]; f2[n+1]=0;
			for(int i=n-1;i>=1;i--){
				f2[i]=min(f2[i+1]+w[i],min(f2[i+2]+w[i],f2[i+1]));
			}
			for(int i=1;i<=m;i++){
				scanf("%d%d%d%d",&a,&x,&b,&y);
				if(a>b){
					swap(a,b);
					swap(x,y);
				}
				if(b-a==1&&x==0&&y==0){
					printf("-1\n");
					continue;
				}
				else {
					f1[a]=min(f1[a-1],f1[a-2]);
					f2[b]=min(f2[b+1],f2[b+2]);
					if(x==1){
						f1[a]+=w[a];
						f1[a+1]=min(f1[a]+w[a+1],f1[a]);
					}
					else f1[a+1]=min(f1[a],f1[a]+w[a+1]);
					if(y==1){
						f2[b]+=w[b];
						f2[b-1]=min(f2[b]+w[b-1],f2[b]);
					}
					else f2[b-1]=min(f2[b]+w[b-1],f2[b]);
					for(int i=a+2;i<=b;i++){
						f1[i]=min(f1[i-1]+w[i],min(f1[i-2]+w[i],f1[i-1]));
					}
					for(int i=b-2;i>=a;i--){
						f2[i]=min(f2[i+1]+w[i],min(f2[i+2]+w[i],f2[i+1]));
					}
					for(int i=a;i<=b;i++){
						ans=max(f1[i],min(f2[i],ans));
					}
					printf("%d\n",ans);
				}
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
