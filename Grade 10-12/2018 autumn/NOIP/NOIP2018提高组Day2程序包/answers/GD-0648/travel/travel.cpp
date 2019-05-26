#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int readq(){
	int j=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		j=(j<<3)+(j<<1)+(c^48);
		c=getchar();
	}
	return j;
}
void writeq(int x){
	//for (int i=1;i<=1000000;i++);
	if (x>9) writeq(x/10);
	putchar(x%10+48);
}
#define N 5050
int n,m,sonmin[N];
int wh[N],v[N*2],last[N*2],Z;
bool p[N],c[N],flag=1;
int f[N],dfn[N],cnt,anc[N];
int stack[N],t;
inline void add(int a,int b){last[++Z]=wh[a];wh[a]=Z;v[Z]=b;}
void dfs(int x){
	writeq(x);putchar(' ');p[x]=1;
	int son=N;
	for (int i=wh[x];i;i=last[i])
		if (!p[v[i]])
			son=min(v[i],son);
	while (son!=N){
		dfs(son);
		son=N;
		for (int i=wh[x];i;i=last[i])
			if (!p[v[i]])
				son=min(v[i],son);
	}
}
void dfs1(int x){
	//writeq(x);putchar(' ');p[x]=1;
	int son=N;
	for (int i=wh[x];i;i=last[i])
		if (!p[v[i]]&&!c[v[i]])
			son=min(v[i],son);
	dfs(son);
	son=N;
	for (int i=wh[x];i;i=last[i])
		if (!p[v[i]]&&!c[v[i]])
			son=min(v[i],son);
	if (son!=N){
		sonmin[x]=son;
		stack[++t]=x;
	}
}
void dfs2(int x){
	writeq(x);putchar(' ');p[x]=1;
	if (flag&&c[x]){
		int l=0,r=0,son=10000;
		flag=0;
		for (int i=wh[x];i;i=last[i])
			if (!p[v[i]]){
				if (!c[v[i]]) son=min(son,v[i]);
				if (c[v[i]])
					if (!l) l=v[i]; else r=v[i];
			}
		if (son!=10000){
			sonmin[x]=son;
			stack[++t]=x;
		}
		if (l<r){
			int l2=x;
			while (l<r){
				while (t&&sonmin[stack[t]]<l&&stack[t]==l2) dfs1(stack[t--]);				
				writeq(l);putchar(' ');p[l]=1;
				l2=l;
				son=10000;
				for (int i=wh[l];i;i=last[i])
					if (!p[v[i]])
						if (!c[v[i]]) son=min(son,v[i]); else l=v[i];
				if (son!=10000){
					sonmin[l2]=son;
					stack[++t]=l2;
				}
			}
			while (t&&stack[t]!=x) dfs1(stack[t--]);
			int r2=x;
			while (l!=r){
				while (t&&sonmin[stack[t]]<r&&stack[t]==r2) dfs1(stack[t--]);	
				writeq(r);putchar(' ');p[r]=1;
				r2=r;
				son=10000;
				for (int i=wh[r];i;i=last[i])
					if (!p[v[i]])
						if (!c[v[i]]) son=min(son,v[i]); else r=v[i];
				if (son!=10000){
					sonmin[r2]=son;
					stack[++t]=r2;
				}
			}
			while (t&&sonmin[stack[t]]<l&&stack[t]==r2) dfs1(stack[t--]);	
			dfs(l);
			while (t) dfs1(stack[t--]);
		}else{
			int r2=x;
			while (r<l){
				while (t&&sonmin[stack[t]]<r&&stack[t]==r2) dfs1(stack[t--]);				
				writeq(r);putchar(' ');p[r]=1;
				r2=r;
				son=10000;
				for (int i=wh[r];i;i=last[i])
					if (!p[v[i]])
						if (!c[v[i]]) son=min(son,v[i]); else r=v[i];
				if (son!=10000){
					sonmin[r2]=son;
					stack[++t]=r2;
				}
			}			
			while (t&&stack[t]!=x) dfs1(stack[t--]);
			int l2=x;
			while (l!=r){
				while (t&&sonmin[stack[t]]<l&&stack[t]==l2) dfs1(stack[t--]);	
				writeq(l);putchar(' ');p[l]=1;
				l2=l;
				son=10000;
				for (int i=wh[l];i;i=last[i])
					if (!p[v[i]])
						if (!c[v[i]]) son=min(son,v[i]); else l=v[i];
				if (son!=10000){
					sonmin[l2]=son;
					stack[++t]=l2;
				}
			}
			while (t&&sonmin[stack[t]]<l&&stack[t]==l2) dfs1(stack[t--]);	
			dfs(l);
			while (t) dfs1(stack[t--]);
		}
	}else{
		int son=N;
		for (int i=wh[x];i;i=last[i])
			if (!p[v[i]])
				son=min(v[i],son);
		while (son!=N){
			dfs2(son);
			son=N;
			for (int i=wh[x];i;i=last[i])
				if (!p[v[i]])
					son=min(v[i],son);
		}
	}
}
void circle(int x){
	dfn[x]=anc[x]=++cnt;
	p[x]=1;
	for (int i=wh[x];i;i=last[i])
		if (f[x]!=v[i]){
			if (!p[v[i]]){
				f[v[i]]=x;
				circle(v[i]);
			}else{
				c[x]=1;
				anc[x]=dfn[v[i]];
			}
			anc[x]=min(anc[x],anc[v[i]]);
			if (anc[v[i]]<=dfn[x]) c[x]=1;
		}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=readq();m=readq();
	for (int i=1,x,y;i<=m;i++){
		x=readq();y=readq();
		add(x,y);add(y,x);
	}
	if (m<n){
		dfs(1);
	}else{
		circle(1);
		memset(p,0,sizeof(p));
		dfs2(1);
	}
	return 0;
}
