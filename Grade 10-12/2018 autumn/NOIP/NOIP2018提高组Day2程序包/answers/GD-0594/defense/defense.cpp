#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int n,m;
char ch[10];
struct edge{
	int y,next;
}s[200010];
int first[100010],d[100010],len=0;
long long f[100010][2],back[100010][2];
int tf[100010];

void ins(int x,int y){
	len++;
	s[len]=(edge){y,first[x]};first[x]=len;
}

void get_ans(int x,int fa){
	int tot=0;
	if(tf[x]==-1 || tf[x]==1) f[x][1]=d[x];
	if(tf[x]==-1 || tf[x]==0) f[x][0]=0;
	for(int i=first[x];i!=0;i=s[i].next){
		int y=s[i].y;
		if(y==fa) continue;
		get_ans(y,x);
		if(tf[x]==-1 || tf[x]==1) f[x][1]+=min(f[y][0],f[y][1]);
		if(tf[x]==-1 || tf[x]==0) f[x][0]+=f[y][1];
		tot++;
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",ch);
	int x,y,a,b;
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	if(ch[0]=='A' && (ch[1]=='2' || ch[1]=='1')){
		if(ch[1]=='1'){
			f[1][1]=d[1];f[1][0]=(long long)1e18;
			for(int i=2;i<=n;i++) f[i][1]=min(f[i-1][0],f[i-1][1])+d[i],f[i][0]=f[i-1][1];
			back[n][0]=0;back[n][1]=d[n];
			for(int i=n-1;i>=2;i--) back[i][1]=min(back[i+1][0],back[i+1][1])+d[i],back[i][0]=back[i+1][1];
			for(int i=1;i<=m;i++){
				scanf("%d %d %d %d",&a,&x,&b,&y);
				if(x==0 && y==0 && (a==b+1 || b==a+1)) printf("-1\n");
				else if(y==1) printf("%lld\n",f[b][y]+back[b][y]-d[b]);
				else printf("%lld\n",f[b][y]+back[b][y]);
			}
		}
		else if(ch[1]=='2'){
			f[1][1]=d[1];f[1][0]=0;
			for(int i=2;i<=n;i++) f[i][1]=min(f[i-1][0],f[i-1][1])+d[i],f[i][0]=f[i-1][1];
			back[n][0]=0;back[n][1]=d[n];
			for(int i=n-1;i>=1;i--) back[i][1]=min(back[i+1][0],back[i+1][1])+d[i],back[i][0]=back[i+1][1];
			for(int i=1;i<=m;i++){
				scanf("%d %d %d %d",&a,&x,&b,&y);
				if(x==0 && y==0) printf("-1\n");
				else printf("%lld\n",f[a][x]+back[b][y]);
			}
		}
		return 0;
	}
	memset(tf,-1,sizeof(tf));
	bool an=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&a,&x,&b,&y);
		an=false;
		for(int j=1;j<=n;j++) f[j][0]=f[j][1]=(long long)1e18;
		if(x==0 && y==0) for(int u=first[a];u!=0;u=s[u].next) if(s[u].y==b) {an=true;break;}
		if(an) {printf("-1\n");continue;}
		tf[a]=x;tf[b]=y;
		get_ans(1,0);
		printf("%lld\n",min(f[1][0],f[1][1]));
		tf[a]=tf[b]=-1;
	}
}
