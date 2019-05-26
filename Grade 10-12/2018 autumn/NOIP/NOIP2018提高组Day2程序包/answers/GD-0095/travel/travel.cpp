#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int last[5010],next[10010],to[10010];
int n,m,num;
int a[5010];
bool b[5010];
bool bz[5010];
int bk;
int w[5010][2],x1,x2;
void add(int x,int y){
	next[++num]=last[x];
	last[x]=num;
	to[num]=y;
}
int dfs1(int x,int fa,int t){
	printf("%d ",x);
	int h=t+1;
	for(int j=last[x];j;j=next[j])
		if(to[j]!=fa)
			a[++t]=to[j];
	if(h<=t){
		sort(a+h,a+t+1);
		for(int i=h;i<=t;i++)
			dfs1(a[i],x,t);
	}
}
int get(int x,int fa){
	if(b[x]){
		w[x][0]=fa;
		w[fa][1]=x;
		bz[x]=true;
		return x;
	}
	else{
		b[x]=true;
		int z=0;
		for(int j=last[x];j;j=next[j]){
			if(to[j]!=fa)
				z=get(to[j],x);
			if(z==x)
				return -1;
			if(z>0){
				w[x][0]=fa;
				w[fa][1]=x;
				bz[x]=true;
				return z;
			}
		}
		b[x]=false;
	}
	return 0;
}
void dfs2(int x,int fa,int t){
	printf("%d ",x);
	b[x]=true;
	if(!bk&&bz[x]){
		bk=1;
		x2=max(w[x][0],w[x][1]);
	}
	int h=t+1;
	for(int j=last[x];j;j=next[j])
		if(to[j]!=fa)
			a[++t]=to[j];
	if(h<=t){
		sort(a+h,a+t+1);
		if(bk==1&&bz[a[t]]&&a[t]>x2){
			t--;
			x1=x;
			bk=2;
		}
		for(int i=h;i<=t;i++){
			if(bk==2&&a[i]==x1)
				continue;
			dfs2(a[i],x,t);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	if(m==n-1)
		dfs1(1,0,0);
	else{
		get(1,0);
		dfs2(1,0,0);
	}
	return 0;
}

