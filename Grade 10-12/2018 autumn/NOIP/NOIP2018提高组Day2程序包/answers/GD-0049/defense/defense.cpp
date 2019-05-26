#include<cstdio>
#include<cstring>
using namespace std;

const int N=300010;
int hea[N],nex[N<<1],ver[N<<1];
int val[N],dis[N],fa[N];
int pt=0;

int min(int a,int b){
	if(a==-1)	return b;
	if(b==-1)	return a;
	return a<b?a:b;
}

void put(int x,int y){
	ver[++pt]=y;
	nex[pt]=hea[x];hea[x]=pt;
}

int dp[N][2];
void dfs(int x){
	dp[x][0]=0;dp[x][1]=val[x];
	for(int i=hea[x];i;i=nex[i]){
		if(ver[i]==fa[x])	continue;
		dis[ver[i]]=dis[x]+1;
		fa[ver[i]]=x;
		dfs(ver[i]);
		dp[x][0]+=dp[ver[i]][1];
		dp[x][1]+=dp[ver[i]][0]<dp[ver[i]][1]?dp[ver[i]][0]:dp[ver[i]][1];
	}
}

void read(int &x){
	register char tmp=getchar();x=0;
	while(tmp<=32)	tmp=getchar();
	while(tmp>32)	x=(x<<1)+(x<<3)+tmp-'0',tmp=getchar();
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	read(a);
	for(int i=1;i<=n;++i)	read(val[i]);
	for(int i=1;i<n;++i){
		read(a),read(b);
		put(a,b);put(b,a);
	}
	dis[1]=1;
	dfs(1);
	int c,d;
	int at1[2],at0[2],ct1[2],ct0[2];
	int ap=0,cp=0;
	for(int i=0;i<m;++i){
		read(a),read(b),read(c),read(d);
		at1[0]=at1[1]=at0[0]=at0[1]=0;
		ap=0;
		ct1[0]=ct1[1]=ct0[0]=ct0[1]=0;
		cp=0;
		if(!b&&!d){
			for(int i=hea[a];i;i=nex[i])	if(ver[i]==c){
				printf("-1\n");
				goto hell;
			}
		}
		if(dis[a]<dis[c]){
			a^=c,c^=a,a^=c;
			b^=d,d^=b,b^=d;
		}
		if(b)	at1[0]=dp[a][1],at0[0]=-1;
		else	at0[0]=dp[a][0],at1[0]=-1;
		if(b)	ct1[0]=dp[c][1],ct0[0]=-1;
		else	ct0[0]=dp[c][0],ct1[0]=-1;
		while(dis[a]>dis[c]){
			at1[ap^1]=dp[fa[a]][1]+(min(at0[ap],at1[ap])-min(dp[a][0],dp[a][1]));
			at0[ap^1]=at1[ap]==-1?-1:(dp[fa[a]][0]-dp[a][1]+at1[ap]);
			a=fa[a];ap^=1;
		}
		if(a==c){
			if(d)	printf("%d\n",at1[ap]);
			else	printf("%d\n",at0[ap]);
			goto hell;
		}
		while(fa[a]!=fa[c]){
			at1[ap^1]=dp[fa[a]][1]+(min(at0[ap],at1[ap])-min(dp[a][0],dp[a][1]));
			at0[ap^1]=at1[ap]==-1?-1:(dp[fa[a]][0]-dp[a][1]+at1[ap]);
			a=fa[a];ap^=1;
			ct1[cp^1]=dp[fa[c]][1]+(min(ct0[cp],ct1[cp])-min(dp[c][0],dp[c][1]));
			ct0[cp^1]=ct1[cp]==-1?-1:(dp[fa[c]][0]-dp[c][1]+ct1[cp]);
			c=fa[c];cp^=1;
		}
		at1[ap^1]=dp[fa[a]][1]+(min(at0[ap],at1[ap])-min(dp[a][0],dp[a][1]));
		at0[ap^1]=at1[ap]==-1?-1:(dp[fa[a]][0]-dp[a][1]+at1[ap]);
		at1[ap^1]=at1[ap^1]+(min(ct0[cp],ct1[cp])-min(dp[c][0],dp[c][1]));
		at0[ap^1]=ct1[cp]==-1?-1:(at0[ap^1]-dp[c][1]+ct1[cp]);
		a=fa[a];ap^=1;
		while(fa[a]){
			at1[ap^1]=dp[fa[a]][1]+(min(at0[ap],at1[ap])-min(dp[a][0],dp[a][1]));
			at0[ap^1]=at1[ap]==-1?-1:(dp[fa[a]][0]-dp[a][1]+at1[ap]);
			a=fa[a];ap^=1;
		}
		printf("%d\n",min(at0[ap],at1[ap]));
		hell:
		continue;
	}
	return 0;
}
